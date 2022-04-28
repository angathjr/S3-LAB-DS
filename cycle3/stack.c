#include<stdio.h>
#include<stdlib.h>
#define N 6
int stack[N];
int top=-1;
void push(int x)
{       
    if(top==N-1)
        printf("Stack overflow ");
    else if(top==-1)
    {
        top=0;
        stack[top]=x;
    }
    else
    {
        top=top+1;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
        printf("stack underflow\n\n");
    else
    {
        printf("\n\nDeleted element is %d",stack[top]);
        top--;        
    }
}
void display()
{
    if(top==-1)
    {
        printf("The stack is empty\n\n");
    }
    else
    {
        printf("\nThe elemets are :");
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}
int main()
{
    char ch;
    int i,op,num;
    while(1)
    {
        printf("\n MENU\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n\n");
        printf("\nEnter the operation needed to perform");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("\nEnter the number to be PUSH ");
                    scanf("%d",&num);
                    push(num);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("EXIT");
                    exit(0);
            default:printf("INVALID INPUT!!!");
        }
    }
    return 0;
}

