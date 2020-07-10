 Solve Balanced Bracket Problem using STACK.
eg - (()) is balanced, (((()))) is balanced, (((((()) is not balanced.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max_Size 100

struct Stack
{
    int top;
    char arr[Max_Size];
}st;

int isEmpty()
{
    if(st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(st.top == Max_Size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void push()
{
    if(isFull())
    {
        printf("[!!] Memory Error");
        printf(">> Stack is full");
        exit(0);
    }
    else
    {
        st.top++;
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("Unbalanced!!!");
        exit(0);
    }
    else
    {
        st.top--;
    }
}

int main()
{
    char brackets[Max_Size], chk;
    int i;
    st.top = -1;

    A:

    printf("Enter the brackets: \n");
    scanf("%s", &brackets);

    for(i=0;i<strlen(brackets);i++)
    {
        if(brackets[i] == '(')
        {
            push();
        }
        else if
        (brackets[i] == ')')
        {
            pop();
        }
        else
        {
            printf("[!!] Input Error");
            printf(">> Invalid Input");
            exit(0);
        }
    }

    if(isEmpty())
    {
        printf("Balanced!!!");
    }
    else
    {
        printf("Unbalanced!!!");
    }

    printf("\nDo you want to check again [y/n] ?\n");
    fflush(stdin);
    scanf("%c", &chk);

    if(chk == 'y')
    {
        goto A;
    }
    else
    {
        printf("[!!] Exiting...");
        exit(0);
    }

    return 0;
}