#include <bits/stdc++.h>
using namespace std;

class String
{
    public:
    string str;
    String()
    {
        str = "none";
    }
    String(string str)
    {
        this->str = str; 
    }
    void getInput(){
        cin >> str;
    }

    void display();
    
    String operator+(String s);
   
    void operator*(int n);
   
    friend void operator*(int n, String &s);

    friend istream& operator>>(istream& cin,String &s);

    friend ostream& operator<<(ostream& cout,String &s);
    
};

void String :: display(){
    cout << str << endl;
}

String String :: operator+(String s){
    String res;
    res.str = this->str + s.str;
    return res; 
}

void String :: operator*(int n){
    string temp = this->str;
    for (int i=1; i<n; i++){
        this->str = this->str + temp;
    }
}

void operator*(int n, String &s){
    string temp = s.str;
    for (int i=1; i<n; i++){
        s.str = s.str + temp;
    }
}

istream& operator>>(istream& cin, String &s){
    cin >> s.str;
    return cin;
}

ostream& operator<<(ostream& cout, String &s){
    cout << s.str;
    return cout;
}

int main(){
    String s("OK");
    String s1("google");
    String s2;
    s2 = s + s1;
    //s3.display();
    s*3;
    4*s1;
    s.display();
    s1.display();
    s2.display();
    String s3,s4,s5;
    cin >> s3 >> s4 >> s5;
    cout << s3 << s4 << s5;
}
/*
OKOKOK
googlegooglegooglegoogle
OKgoogle
hi
hello
namaskar
hihellonamaskar
*/