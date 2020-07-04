#include<stdio.h>
#include<string.h>

struct Students{
    int stud_id; 
    char stud_name[100]; 
    char stud_year[10];  
    float stud_cgpa;
};

int main(){
    //Declarition of struct name
    struct Students Anubhav;
    struct Students Neel;
    struct Students Ayush;
    struct Students Yashraj;

    //stud_id specification
    Anubhav.stud_id = 191407;
    Neel.stud_id = 191402;
    Ayush.stud_id = 191398;
    Yashraj.stud_id = 191350;

    //stud_name specification
    strcpy(Avinash.stud_name, "Anubhav Vijayvargiya");
    strcpy(Neel.stud_name,"Neel Malwatkar");
    strcpy(Ayush.stud_name,"Ayush Prasad");
    strcpy(Yashraj.stud_name,"Yashraj Panar");

    //stud_year specification
    strcpy(Anubhav.stud_year,"SY");
    strcpy(Neel.stud_year,"SY");
    strcpy(Ayush.stud_year,"TY");
    strcpy(Yashraj.stud_year,"B.Tech");

    //stud_cgpa specification
    Anubhav.stud_cgpa = 8.17f;
    Neel.stud_cgpa = 8.30f;
    Ayush.stud_cgpa = 9.0f;
    Yashraj.stud_cgpa = 8.5f;

    //priting Infomation
    printf("\n");
    printf("Printing infomation of Avinash\n");
    printf("\n");
    printf("Student ID : %d\n",Anubhav.stud_id);
    printf("Student Full Name : %s\n",Anubhav.stud_name);
    printf("Student Year : %s\n",Anubhav.stud_year);
    printf("Student CGPA : %.2f\n",Anubhav.stud_cgpa);

    printf("\n");
    printf("Printing infomation of Neel\n");
    printf("\n");
    printf("Student ID : %d\n",Neel.stud_id);
    printf("Student Full Name : %s\n",Neel.stud_name);
    printf("Student Year : %s\n",Neel.stud_year);
    printf("Student CGPA : %.2f\n",Neel.stud_cgpa);

    printf("\n");
    printf("Printing infomation of Ayush\n");
    printf("\n");
    printf("Student ID : %d\n",Ayush.stud_id);
    printf("Student Full Name : %s\n",Ayush.stud_name);
    printf("Student Year : %s\n",Ayush.stud_year);
    printf("Student CGPA : %.2f\n",Ayush.stud_cgpa);

    printf("\n");
    printf("Printing infomation of Yashraj\n");
    printf("\n");
    printf("Student ID : %d\n",Yashraj.stud_id);
    printf("Student Full Name : %s\n",Yashraj.stud_name);
    printf("Student Year : %s\n",Yashraj.stud_year);
    printf("Student CGPA : %.2f\n",Yashraj.stud_cgpa);

    return 0;
}   