#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

//Declaration of stack
struct Stack{
    int top;
    char arr[MAX_SIZE];
} st;

void init(){
    st.top = -1;
}
//Operation of stack
bool isEmpty(){
    if(st.top == -1){
        return true;
    }else{
        return false;
    }
}

//Operation of stack
bool isFull(){
    if(st.top == MAX_SIZE-1){
        return true;
    }else{
        return false;
    }
}

//Operation of stack
//Push code
void push(char item){
    if(isFull()){
            printf("Stack is full");
    }else{
        st.top++;
        st.arr[st.top] = item;
    }
}

//Operation of stack
// Pull code
void pop(){
    if(isEmpty()){
        printf("Stack is empty");
    }else{
        st.top--;
    }
}

//Operation of stack
// Top code
char gettop(){
    return st.arr[st.top];
}

//Operation for check
//Pair Checking
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

int main()
{
    char in_expr[MAX_SIZE];
    int length=0,i,j;

    init();

    printf("Enter an expression to check:");
    gets(in_expr);

    length = strlen(in_expr);

    for(i=0;i<length;i++){
        if(in_expr[i] == '(' || in_expr[i] == '{' || in_expr[i] == '['){
                push(in_expr[i]);
        }else if(in_expr[i] == ')' || in_expr[i] == '}' || in_expr[i] == ']'){
            char a = gettop();
            printf("%c",a);
            if(isEmpty() || !ArePair(gettop(),in_expr[i])){
                printf("\nResult - Invalid expression - Not a Balanced one !");
            }else{
                pop();
            }
        }
    }
    if(isEmpty()){
        printf("\nBalanced !");
    }else{
        printf("\nNot a Balanced one !");
    }

    return 0;
}