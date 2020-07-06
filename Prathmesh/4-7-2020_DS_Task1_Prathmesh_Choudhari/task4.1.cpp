/*Create a student class. Add the necessary data members and also add a dynamic array to store the marks of 5 subjects (use new keyword). Initialize the data members using constructors. We don't know the cgpa yet so assign it some random value in constructor. Write following functions inside the class -
Function to return the total marks. Function to calculate and store the cgpa in the variable, Funtion to take input (Dont take cgpa as input) and to display the data.
Think : Where can you use delete keyword to free the memory allocated to the marks array.
*/

#include<iostream>
#include<cstring>
using namespace std;

class Student{
    public:
    
    string name;
    int roll;

    Student(){
        name="";
        roll=0;
    }
    int* arr= new int[5];
    int total(int* arr){
        float  sum=0;
        for (int i =0; i<5; i++){
            sum=sum+arr[i];
        }
        return(sum);   
    }
    
    float cgpa(int sum){
        float per;
        float cgpa=0;
        per=sum/5;
        cgpa=per/9.5;
        return cgpa;
        }

    Student input(){
        Student S;
        cout<<"Fill student details\n";
        cout<<"Enter the name and roll number\n";
        cin>>S.name;
        cin>>S.roll;
        cout<<"Enter the marks (out of 100) of 5 subjects \n";
        cin>>S.arr[0]>>S.arr[1]>>S.arr[2]>>S.arr[3]>>S.arr[4];
        return(S);
    }    
    void display(Student S)
    {   
        cout<<"\nStudent name: "<<S.name;
        cout<<"\nRoll number: "<<S.roll;
        cout<<"\nThe total score is: "<<total(S.arr);
        cout<<"\nCGPA: "<<cgpa(total(S.arr));
        
    }

    
};



int main(){
    Student S;
    S=S.input();
    S.display(S);

}

/*
Fill student details
Enter the name and roll number
John
13
Enter the marks (out of 100) of 5 subjects
90
80
70
80
90

Student name: John
Roll number: 13
The total score is: 410
CGPA: 8.63158
*/