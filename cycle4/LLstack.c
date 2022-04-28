#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*top;
void push()
{
    int value;
    struct node *new=malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&value);
    if(top==NULL)
    {
        new->data=value;
        new->link=NULL;
        top=new;
    }
    else
    {
        new->data=value;
        new->link=top;
        top=new;
    }
}
void pop()
{   
    struct node *temp;
    if(top==NULL)
        printf("The stack is empty");
    else
    {
        temp=top;
        printf("%d is deleted",temp->data);
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}
void display()
{  
    struct node *temp;
    if(top==NULL)
        printf("\nStack is empty");
    else
    {
        temp=top;
        printf("\nstack :");
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
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: push();
                    display();
                    break;
            case 2: pop();
                    display();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exited!!");
                    exit(0);
            default: printf("Wrong input");
        }
    }
}