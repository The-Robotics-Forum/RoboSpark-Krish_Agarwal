 Write a code to store and display student records using a structure. It should contain stud_id, stud_name, stud_year and stud_cgpa.



#include<stdio.h>
#include<stdlib.h>
#define Num_Of_Studs 4

struct Student
{
    int id;
    char name[20];
    char yr[10];
    float cgpa;

}stud[Num_Of_Studs];

int main()
{   
    int i;
    char chk;

    A:

    for(i=1;i<Num_Of_Studs+1;i++)
    {
        printf("\nEnter Student %d's ID: ", i);
        fflush(stdin);
        scanf("%d", &stud[i].id);

        printf("Enter Student %d's Name: ", i);
        fflush(stdin);
        gets(stud[i].name);

        printf("Enter %s's studying year: ", stud[i].name);
        fflush(stdin);
        gets(stud[i].yr);

        printf("Enter %s's CGPA: ", stud[i].name);
        fflush(stdin);
        scanf("%f", &stud[i].cgpa);
    }
    
    printf("Do you want to print everything [y/n] ?\n");
    fflush(stdin);
    scanf("%c", &chk);

    if(chk == 'y'){
        for(i=1;i<Num_Of_Studs+1;i++)
        {
            printf("\n\nStudent %d:", i);
            printf("\nID: %d", stud[i].id);
            printf("\nName: %s", stud[i].name);
            printf("\nYear: %s", stud[i].yr);
            printf("\nCGPA: %.2f", stud[i].cgpa);
        }

        printf("Do you want to enter the information again [y/n] ?\n");
        fflush(stdin);
        scanf("%c", &chk);

        if(chk == 'y')
        {
            goto A;
        }
        else
        {
            exit(0);
        }
    }
    else
    {    
        printf("Do you want to enter the information again [y/n] ?\n");
        fflush(stdin);
        scanf("%c", &chk);

        if(chk == 'y')
        {
            goto A;
        }
        else
        {
            exit(0);
        }
    }  
}