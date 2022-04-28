#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    char data;
    struct node*nxt,*prev;
}*head,*temp,*temp1,*temp2;
void insert()
{
    char ch;
    printf("\nEnter the  character : ");
    scanf("%c ",&ch);
    struct node* new=malloc(sizeof(struct node));
    new->data=tolower(ch);
    new->prev=NULL;
    new->nxt=NULL;
    if(head==NULL)
    {
        head=new;
        temp=head;

    }
    else
    {
        new->prev=temp;
        temp->nxt=new;
        temp=new;
    }
}
void  undo()
{
    if(temp==NULL)
        printf("Empty");
        return;
    temp1=temp;
    temp=temp->prev;

}
void redo()
{
    temp2=temp;
    temp2->nxt=temp1;
}
void main()
{
    int n;
    while(1)
    {

         printf("\n\nmenu\n\n");
         printf("\n1.enter \n2.undo\n3.redo\n4.exit");
         printf("\n enter your choice:");
         scanf("%d",&n);
         switch (n)
         {
            case 1: insert();
                    break;
            case 2: undo();
                    break;
            case 3: redo();
                    break;
            case 4: exit(0);
            default: printf("invalid option");
         }
    }
}
