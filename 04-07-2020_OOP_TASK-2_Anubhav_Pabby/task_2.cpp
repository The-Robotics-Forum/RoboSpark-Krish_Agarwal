#include<bits/stdc++.h>
using namespace std;

//DECLARING THE CLASSS DETIALS
class Student_details{
    public:
    //IF DATA NOT PROVIDE THEN DEFAULT CONDITION
    string stud_name = "My_Default_Name";   
    int stud_roll=00;
    int stud_id=00;
};

//FUNCTION TO SHOWRANK WHEN ONLY A INTEGER IS PASSED
void showRank(int stud_rank){
    cout << stud_rank << endl;
}


//FUNCTION TO SHOWRANK WHEN ONLY STUDENT DETIALS ARE PASSED
void showRank(string stud_name, int stud_roll, int stud_id){
    cout << "\nNo integer passed, therefore student details are ---" << endl;
    cout << "Name: " << stud_name << endl;
    cout << "Roll: " << stud_roll << endl;
    cout << "Id: " << stud_id << endl;
}

//FUNCTION TO SHOWRANK WHEN A INTEGER AND STUDENT DETIALS ARE PASSED
void showRank(string stud_name, int stud_roll, int stud_id, int stud_rank){
    cout << "\nBoth rank and student details are ---"<< endl;
    cout << "Name: " << stud_name << endl;
    cout << "Roll: " << stud_roll << endl;
    cout << "Id: " << stud_id << endl;
    cout << "Rank: " << stud_rank << endl;
}

int main(){
    int rank;
    Student_details s1;     
    int user_in;

    //INPUT 
    cout << "Enter---\n1. TO GET RANK ONLY...!\n2. TO GET STUDENT DETIALS ONLY....!\n3. TO GET STUDENT DETAILS AS WELL AS RANK...!\nInput : ";
    cin >> user_in;

    //IF - ELSE IF - ELSE CONDITIONS
    if (user_in==1){     //TO GET RANK ONLY...!
        cout << "PASS RANK: ";
        cin >> rank;
        cout << "ONLY RANK IS PASEED SO, RANK IS : ";
        showRank(rank);
    }else if (user_in==2){    //TO GET STUDENT DETIALS ONLY....!   
        cout << "\nPASS STUDENT DETIALS --- \n";
        cout << "STUDENT NAME: ";
        cin >> s1.sname;
        cout << "PASS ROLL NUMBER: ";
        cin >> s1.sroll;
        cout << "PASS STUDENT ID : ";
        cin >> s1.sid;   
        showRank(s1.sname, s1.sroll, s1.sid);
    }else{   //TO GET STUDENT DETAILS AS WELL AS RANK...!
        cout << "\nPASS STUDENT DETIALS --- \n";
        cout << "STUDENT NAME: ";
        cin >> s1.sname;
        cout << "PASS ROLL NUMBER: ";
        cin >> s1.sroll;
        cout << "PASS STUDENT ID : ";
        cin >> s1.sid;
        cout << "PASS RANK: ";
        cin >> rank;
        showRank(s1.sname, s1.sroll, s1.sid, rank);
    }
    return 0;
}