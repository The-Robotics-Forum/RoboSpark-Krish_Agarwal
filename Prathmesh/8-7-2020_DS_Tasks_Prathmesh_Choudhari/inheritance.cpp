/*Task for today -
Problem statement On Inheritance
I want my Personal data, Professional data, & Academic data to be separated in different classes and 4th class called biodata.
If I create object of biodata class then using that object I can get all my professional, personal and academic data.
Decide which type of inheritance you will be using to achieve this goal .
Take data members in classes as follows:
personal class - Name, Surname, address, mobile_no, dob.
professional class - name_of_organization, job_profile, project.
Academic - year_of_passing, cgpa, college_name, branch
member functions
All class includes default constructor(if data members are present), and one function to get data from user for its data member.
Note :- define all data members as protected so that you can access this members in its derived class directly */

#include<iostream>
#include<string>
using namespace std;

class personal_class{
    protected:
    string Name;
    string Surname;
    string mobile_no;
    string dob;
    personal_class(){
        Name="";
        Surname="";
        mobile_no="";
        dob="00-00-0000";
    }
    void get_personal(){
        string n,sn,DOB;
        string mn;
        cout<<"\nEnter name\n";
        cin>>n;
        cout<<"\nEnter Surname\n";
        cin>> sn;
        cout<<"\nEnter mob. no.\n";
        cin>> mn;
        cout<<"\nEnter Date of birth (DDMMYYYY format without any sign)\n";
        cin>> DOB;
        this->Name=n;
        this->Surname=sn;
        this->mobile_no=mn;
        this->dob=DOB;
    }
};

class professional_class: protected personal_class{
    protected:
    string name_of_organization;
    string job_profile;
    string project;
    void get_professional(){
        get_personal();
        cout<<"\nEnter name of organization";
        getline(cin,name_of_organization);
        getline(cin,name_of_organization);
        cout<<"\n Enter job profile";
        getline(cin,job_profile);
        cout<<"\n Enter mob. no.";
        getline(cin,project);
    }

};

class Academic : protected professional_class{
    protected:
    int year_of_passing; 
    float cgpa;
    string college_name;
    string branch;
    void get_academic(){
        get_professional();
        cout<<"\nEnter Passing year";
        cin>>year_of_passing;
        cout<<"\n Enter CGPA";
        cin>>cgpa;
        cout<<"\n Enter College Name";
        getline(cin,college_name);
        getline(cin,college_name);

        cout<<"\n Enter Branch Name";
        getline(cin,branch);
        
    }
    

}; 
class bio: protected Academic{
    public:
    bio(){
        get_academic();
    }
    void print(){
        cout<<"\nHere are your details\n"<<endl;
        cout<<"Name: "<<Name<<Surname<<endl;
        cout<<"DOB: "<<dob<<endl;
        cout<<"Mobile number: "<<college_name<<endl;
        cout<<"College Name: "<<college_name<<endl;
        cout<<"Branch: "<<branch<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
        cout<<"Passing Year: "<<year_of_passing<<endl;
        cout<<"Organization Name: "<<name_of_organization<<endl;
        cout<<"Job Profile: "<<job_profile<<endl;
        cout<<"Project: "<<project<<endl;
        }
};

int main(){
    bio B;
    B.print();

}