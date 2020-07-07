#include<stdio.h>
struct stud
{
    int stud_id;
    char stud_name[35];
    int stud_year;
    float stud_cgpa; 
};

int main(){
    struct stud S[100];
    int choice;
    int i=0;
    while (1)
    {
        printf("\nWant to enter student details ? 1.Yes 2.No\n");
        scanf("%d",&choice);
    if(choice==1){
        printf("\nEnter id : ");
        scanf("%d",&S[i].stud_id);
    
        printf("\nEnter student name : ");
        scanf("%s",&S[i].stud_name);
    
        printf("\nEnter Year : ");
        scanf("%d",&S[i].stud_year);

        printf("\nEnter CGPA : ");  
        scanf("%f",&S[i].stud_cgpa);
        i++;
    }
    else{
        break;
    }
    }
    printf("id\t\tName\t\tYear\t\tCGPA\n");
for (int j=0;j<i;j++){
    
        printf("%d\t\t",S[j].stud_id);
    
        printf("%s\t\t",S[j].stud_name);
    
        printf("%d\t\t",S[j].stud_year);

        printf("%f\n",S[j].stud_cgpa);
        
}
}

/*Output*/
/*
Want to enter student details ? 1.Yes 2.No
1

Enter id : 1

Enter student name : Ramesh

Enter Year : 2

Enter CGPA : 9.1

Want to enter student details ? 1.Yes 2.No
1

Enter id : 2

Enter student name : Suresh

Enter Year : 2

Enter CGPA : 8.2

Want to enter student details ? 1.Yes 2.No
1

Enter id : 3

Enter student name : Gajesh

Enter Year : 2

Enter CGPA : 9.9

Want to enter student details ? 1.Yes 2.No
2
id              Name            Year            CGPA
1               Ramesh          2               9.1
2               Suresh          2               8.2
3               Gajesh          2               9.9
*/    

    
    
    

    
    

