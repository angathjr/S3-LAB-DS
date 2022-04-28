#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*temp,*current;
struct node *head=NULL;
int num;
void display()
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        printf("\nData:");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->link;
        }
    }
}
void inatb()
{
    printf("Enter the element to enter:");
    scanf("%d",&num);
    struct node *new=malloc(sizeof(struct node));
    new->data=num;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->link=head;
        head=new;
    }
    
}
void inate()
{
    temp=head;
    struct node*new=malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&num);
    new->data=num;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else{
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new;
    }
}
void inatpos()
{
    int pos;
    printf("Enter the position and element which element is to be insert:");
    scanf("%d %d",&pos,&num);
    if(pos<=0)
    {
        printf("cannot add to this position");
        return;
    }
    temp=head;
    struct node *new=malloc(sizeof(struct node));
    new->data=num;
    new->link=NULL;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->link;
        i++;
        if(temp==NULL && pos!=i)
        {
            printf("cannot add to this position");
            return;
        }
    }
    new->link=temp->link;
    temp->link=new;
}
void delatb()
{
    if (head==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        temp=head;
        head=head->link;
        printf("deleted element is %d",temp->data);
        free(temp);
    }
}
void delate()
{
    if(head==NULL)
        printf("The list is empty");
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            current=temp;
            temp=temp->link;
        }
        current->link=NULL;
        printf("Deleted element is %d",temp->data);
        free(temp);
    }
}
void delatpos(int pos)
{
    temp=head;
    if(pos<=0)
        printf("position doesnt exist");
    else if(head==NULL)
        printf("The list is empty");
    else if(head->link==NULL)
    {
        if(pos>1)
            printf("position doesnot exist");
        else
        {
            temp=head;
            head=NULL;
            printf("%d is deleted",temp->data);
            free(temp);
        }
    }   
    else
    {
        int i=1;
        while(i<pos)
        {
            current=temp;
            temp=temp->link;
            i++;
            if(temp==NULL)
            {
                printf("position did not exist");
                return;
            }
        }
        current->link=temp->link;
        printf("Deleted element is %d",temp->data);
        free(temp);
    }
}
void main()
{
    int c,pos;
    while(1)
    {
        printf("\n\nMENU\n\n");
        printf("\n1.Display");
        printf("\n2.insert at beginning");
        printf("\n3.insert at end");
        printf("\n4.insret at spec pos");
        printf("\n5.Delete from beginning");
        printf("\n6.delete from end");
        printf("\n7.delete from spec pos");
        printf("\n8.EXIT");
        printf("\n\nEnter your choice:");
        scanf("%d",&c);
        switch(c){

        case 1: display();
                break;
        case 2: inatb();
                display();
                break;
        case 3: inate();
                display();
                break;
        case 4: inatpos();
                display();
                break;
        case 5: delatb();
                display();
                break;
        case 6: delate();
                display();
                break;
        case 7: printf("Enter the position of the node to delete");
                scanf("%d",&pos);
                delatpos(pos);
                display();
                break;
        case 8: printf("EXITED");
                exit(0);
        default:printf("INVALID INPUT!!");
        } 
    }
}