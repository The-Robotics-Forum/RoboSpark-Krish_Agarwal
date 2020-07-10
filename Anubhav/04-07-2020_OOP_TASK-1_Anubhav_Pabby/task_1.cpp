// INSERTATION OF HEADER FILES
#include<bits/stdc++.h>
using namespace std;

//DELCLARTION OF GLOBAL VARRIBLES
int sgrade = 0;
int scredit = 0;
int gtotal;


class Student  // CLASS DEFINATION
{
    public:
    int* sgrades;
    int* scredits;
    string sname;
    int sid;
    float scgpa;

    //CONSTRUCTOR
    /*
        SETTING UP CGPA TO 0
        TAKING INPUT CGPA
        NUMBER OF GRADES INSERT
        FUNCATION CALLED TO ACCESS CGPA DETIALS
    */
    Student() 
    {   
        sgrades = NULL;
        scredits = NULL;
        scgpa=0; 
        getInput();
        cout << "\nTotal grades obtained : " << total() << endl;    
        showDetails();
    }

    //FUNCATION TO TAKE INPUT STUDENT DETIALS
    void getInput()     
    {
        cout << "\nEnter student details --- \n";
        cout << "Name: ";
        cin >> sname;
        cout << "Id : ";
        cin >> sid;
        cout << "\n";
        sgrades = new int[5];       //ALLOCATION OF DYNAMIC MEMORY
        scredits = new int[5];      //ALLOCATION OF DYNAMIC MEMORY
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i+1 << " grade obtained : ";
            cin >> sgrades[i];
            cout << "Subject" << i+1 << " credits obtained : ";
            cin >> scredits[i];
        }
    }

    //PRINTING OUT CGPA DETIALS
    void showDetails()  
    {
        cout << "\nStudent : " << sname << " - Id no. : " << sid <<" secured " << setprecision(3) << cgpa() <<" CGPA." << endl;   
    }

    //FUNCTION TO CALCULATE THE GRADES
    int total()     
    {
        for (int i = 0; i < 5; i++)
        {
            sgrade += sgrades[i];
            scredit += scredits[i];
        }

        return sgrade;
    }

    //FUNCTION TO CALCULATE CGPA    
    float cgpa()        
    {
        for (int i = 0; i < 5; i++){
           gtotal = gtotal + sgrades[i] * scredits[i];
        }
        scgpa = float(gtotal)/float(scredit);
        return scgpa;
    }

    ~Student(){
        if(sgrades!=NULL){
            delete [] sgrades;
        }

        if(scredits!=NULL){
            delete [] sgrades;
        }
    }
};
//TERMINATION OF CLASS

int main()
{
    Student *s = new Student;
    delete s;
    return 0;    
}