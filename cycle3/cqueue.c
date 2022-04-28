#include<stdio.h>
#include<stdlib.h>
#define n 6
int cq[n];
int f=-1,r=-1;
void push(int x)
{
    if(f==-1 && r==-1)
    {
        f=r=0;
        cq[r]=x;
    }
    else if((r+1)%n==f)
    {
        printf("queue is full");
    }
    else
    {
        r=(r+1)%n;
        cq[r]==x;
    }
}
void pop()
{
    if(r==-1 && f==-1)
    {
        printf("queue is empty");
    }
    else if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%n;
    }
}
void display()
{
    int i=f;
    if(f==-1 && r==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("the queue is");
        while(i!=r)
        {
            printf("%d",cq[i]);
            i=(i+1)%n;
        }
        printf("%d",cq[r]);

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

