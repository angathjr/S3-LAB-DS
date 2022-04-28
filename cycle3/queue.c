#include<stdio.h>
#include<stdlib.h>
#define n 6
int q[n];
int f=-1,r=-1;
void push(int x)
{
    if(r==n-1)
    {
        printf("queue overflow");
    }
    else if(f==-1 && r==-1)
    {
        f=r=0;
        q[r]=x;
    }
    else
    {
        r++;
        q[r]=x;
    } 
}
void pop()
{
    if(r==-1 && f==-1)
    {
        printf("queue underflow");
    }
    else if(f==r)
    {
            f=r=-1;
    }
    else    
        f=f+1;
}
void display()
{
    if(f==-1 && r==-1)
        printf("queue is empty");
    else 
    {
        printf("the queue elements are:");
        for(int i=f;i<r+1;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}
int main()
{
    int num,i;
    while(1)
    {
        printf("\nMENU");
        printf("-----");
        printf("\n1.POP");
        printf("\n2.PUSH");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\n\nenter the option ");
        scanf("%d",&num);        
        switch(num)
         {
            case 1: pop();
                    break;
            case 2: printf("enter the element to push");
                    scanf("%d",&i);
                    push(i);
                    break;
            case 3: display();
                    break;
            case 4: printf("exited");
                    exit(0);
            default:printf("invalid option");
        }
    }
    
}