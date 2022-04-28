#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *rear=NULL;
struct node *front=NULL;
void enq()
{
    int value;
    printf("\nEnter value to be inserted:");
    scanf("%d",&value);
    struct node *new =malloc(sizeof(struct node));
    new->data=value;
    new->link=NULL;
    if(rear==NULL)
    {
        front=rear=new;
    }
    else
    {
        rear->link=new;
        rear=new;
    }
}
void deq()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is empty");
    }
     else
    {
        temp=front;
        front=front->link;
        temp->link=NULL;
        printf("%d is deleted",temp->data);
        free(temp);
        
    }
}
void display()
{
    struct node *temp=front;
    if(front==NULL)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("\nQueue:");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}
int main()
{
    int n;
    while(1)
    {
        printf("\nMENU\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: enq();
                    display();
                    break;
            case 2: deq();
                    display();
                     break;
            case 3: display();
                     break;
            case 4: printf("EXited!!");
                    exit(0);
            default:printf("Invalid input!");
        }
    }
}