/*2. Overload the showRank function in the following way -
When the function has only int as an argument, print that integer as rank.
When the function has only student as an argument, print the student details and print "no rank".
When the function received one student and one int as arguments, print the student details and the rank.
Rank is not a data member of Student
Remember : Avoid copy pasting the code. Define proper functions. (edited) */

#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    float cgpa;
    void showRank(Student S){
        cout<<"\n\n\tStudent detils\n";
        cout<<"\n\tStudent detils\n";
        cout<<"Name: "<<S.name;
        cout<<"\nRoll: "<<S.roll;
        cout<<"\nCGPA: "<<S.cgpa<<endl;
        

    }
    void showRank(Student S, int rank){
        cout<<"\n\tStudent detils\n";
        cout<<"Name: "<<S.name;
        cout<<"\nRoll: "<<S.roll;
        cout<<"\nCGPA: "<<S.cgpa;
        cout<<"\nRank: "<<rank<<endl;
    }
    void showRank(int rank){
        cout<<"\nStudent Rank: "<<rank<<endl;
    }


};

int main()
{
    Student S;
    S.name="John";
    S.roll=21;
    S.cgpa=8.6;
    int rank=2;
    S.showRank(S);
    S.showRank(S,rank);
    S.showRank(rank);

}

/*
        Student detils
Name: John
Roll: 21
CGPA: 8.6
Rank: No rank

   Student detils
Name: John
Roll: 21
CGPA: 8.6
Rank: 2

Student Rank: 2

*/