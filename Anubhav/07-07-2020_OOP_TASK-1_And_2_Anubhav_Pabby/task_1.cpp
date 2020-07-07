#include<iostream>
using namespace std;

class String{

private:
	char* str;
	int length;

public:

	// Default Constructor
	String(){
		this -> str = NULL;
		this -> length = 0;
	}

	// Parameterized Constructor for assigning character array string to our String object
	String(char const *const str){
		this -> length = lengthOfString(str);
		this -> str = new char[(this -> length) + 1];
		
		// Coping string from char const *const str to data member str
		int i=0;
		for(;str[i]!='\0';i++){
			this -> str[i] = str[i];
		} 
		// Also end the string with Null character
		this -> str[i] = '\0';
	}

	// Copy Constructor which performs deep copy on String Objects
	String(String const& s){
		
		// Finding length of string that is to be copied and allocating memory to string according to it's new length
		this -> length = s.length;
		this -> str = new char[(this -> length) + 1];

		// Performing copying on strings
		int i=0;
		for(;s.str[i]!='\0';i++){
			this -> str[i] = s.str[i];
		}
		// Also end the string with Null character
		this -> str[i] = '\0';
	}

	// Overloaded = operator for copying of String object
	// This performs a deep copy.
	String& operator=(String const& s){
		// Deallocating memory of old string
		delete [] (this -> str);
		str = NULL;

		// Finding length of string that is to be copied and allocating memory to string according to it's new length
		this -> length = s.length;
		this -> str = new char[(this -> length) + 1];
		
		// Performing copying on strings
		int i=0;
		for(;s.str[i]!='\0';i++){
			this -> str[i] = s.str[i];
		}
		// Also end the string with Null character
		this -> str[i] = '\0';

		return *this;
	}

	// Making our own concatenation operator by operator overloading
	String& operator+(String const& s){

		// Calculating length of both the strings
		int strLength1 = this -> length;
		int strLength2 = s.length;
		
		// Finding length of string that is to be concatenated and allocating memory to string according to it's new length
		int length = strLength1 + strLength2;
		char* newStr = new char[length + 1];
		
		// Performing concatenation on strings
		int index_new_str=0;
		for(int index_str=0;this -> str[index_str]!='\0';index_str++){
			newStr[index_new_str] = this -> str[index_str];
			index_new_str++;
		}
		newStr[index_new_str] = '\0';
		for(int index_str=0;s.str[index_str]!='\0';index_str++){
			newStr[index_new_str] = s.str[index_str];
			index_new_str++;
		}
		// Also end the string with Null character
		newStr[index_new_str] ='\0';

		// Deallocating memory of old string
		delete [] (this -> str);
		// Assigning Base address of our new String ptr to old String ptr
		this -> str = newStr;
		this -> length = length;

		return *this;
	}

	String& operator*(unsigned int numOfTimes){

		// Calculating length of the string after multiplication of strings
		int strLength = (this -> length) * numOfTimes;
		
		// Finding length of string that is to be multiplied and allocating memory to string according to it's new length
		char* newStr = new char[strLength + 1];
		
		// Performing operation on strings
		int index_new_str = 0;
		for(int times=1;times<=numOfTimes;times++){
			
			int index_str=0;
			for(;this -> str[index_str]!='\0';index_str++){
				newStr[index_new_str] = this -> str[index_str];
				index_new_str++;
			}

		}
		// Also end the string with Null character
		newStr[index_new_str] ='\0';

		// Deallocating memory of old string
		delete [] (this -> str);
		// Assigning Base address of our new String ptr to old String ptr
		this -> str = newStr;
		this -> length = strLength;

		return *this;
	}

	void readline(char delimitor='\n'){

		char* newStr = NULL;

		int i=0;
		char ch = cin.get();
		while(ch!=delimitor){
			this -> str[i] = ch;
			i++;
			if(i==this -> length){
				newStr = new char[2*(this -> length)];

				for(int i=0;str[i]!='\0';i++){
					newStr[i] = str[i];
				}

				delete [] str;
				str = newStr;
				this -> length = 2 * (this -> length);
			}
			ch = cin.get();
		}
		str[i] = '\0';

		int length = lengthOfString(this -> str);
		this -> length = length;
	}

	friend istream& operator>>(istream& cin,String& s){
		// deallocating memory of all Strings
		if(s.str==NULL){
			s.length = 2;
			s.str = new char[2];
			s.str[0] = '\0';
		}

		s.readline();
	    
	    return cin;
	}

	friend ostream& operator<<(ostream& out,String const& s){
		for(int i = 0;i<s.length; i++){
        	out << s.str[i];
		}

    	return out;
	}

	void setStringCharArray(char const *const str){
		// Deallocating memory of old string
		delete [] (this -> str);
		this -> str = NULL;

		// Finding length of string that is to be copied and allocating memory to string according to it's new length
		this -> length = lengthOfString(str);
		this -> str = new char[(this -> length)+1];
		
		// Performing copying on strings
		int i=0;
		for(;str[i]!='\0';i++){
			this -> str[i] = str[i];
		}
		// Also end the string with Null character
		this -> str[i] ='\0';
	}

	void setStringObjectString(String const& s){
		// Deallocating memory of old string
		delete [] (this -> str);
		str = NULL;

		// Finding length of string that is to be copied and allocating memory to string according to it's new length
		this -> length = s.length;
		this -> str = new char[(this -> length) + 1];
		
		// Performing copying on strings
		int i=0;
		for(;s.str[i]!='\0';i++){
			this -> str[i] = s.str[i];
		}
		// Also end the string with Null character
		this -> str[i] ='\0';
	}

	char* getString(){
		return this -> str;
	}


	// It returns the length of string.
	int getLength(){
		return this -> length;
	}

	int lengthOfString(char const *const str){
		
		int length = 0;
		for(int i=0;str[i]!='\0';i++){
			length++;
		}

		return length;
	}

	~String(){
		if(this -> str!=NULL){
			delete [] str;
			this -> str = NULL;
			cout << "Destructor !" << endl;
		}
	}

};

int main(int argc, char const *argv[]){

	String s1;
	cout << "Enter a String" << endl;
	cin >> s1;
	cout << s1 << endl;	

	char name[] = "Anubhav";
	String s2(name);
	cout << s2 << endl;

	// Concatenation of two Strings
	String s3;
	s3 = (s1 + s2);
	cout << s3 << endl;

	// Multipication of string s3 by 5
	cout << s3*5 << endl;

	return 0;
}