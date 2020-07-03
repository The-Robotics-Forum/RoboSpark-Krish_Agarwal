#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
    {
        char namep[20];
        int roll;
    };

typedef struct queue{ 
    
    struct student s[10];
    int front,rear;
} queue;
 
void intialize(queue*  q){
    q->front=0;
    q->rear=0;
}

void enqueue( queue* q, struct student x){
    if((x.roll)%2==0){
    q->s[q->rear++]=x;
    }

}

struct student dequeue( queue* q){
    return (q->s[q->front++]);
}

int isEmpty( queue* q){
    return q->front==q->rear;
}

void print( queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("\nFRONT : ");
    for (int i=q->front;i<q->rear;i++){
        printf(" %s-> %d  ",q->s[i].namep,q->s[i].roll);
    }
    printf(" REAR.");
    return;    
}

int main(){
    queue* q1 = (  queue*) malloc(sizeof(queue));
    intialize(q1);
    struct student s1;
    printf("\nEnter the name of student: ");
    scanf("%s",s1.namep);
    printf("\nEnter the roll number of student: ");
    scanf("%d",&s1.roll);
    enqueue(q1,s1);
    print(q1);
    struct student s2;
    printf("\nEnter the name of student: ");
    scanf("%s",s2.namep);
    printf("\nEnter the roll number of student: ");
    scanf("%d",&s2.roll);
    enqueue(q1,s2);
    print(q1);
    dequeue(q1);
    print(q1);
    


}
