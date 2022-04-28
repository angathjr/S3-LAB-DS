#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*front,*rear,*top;
void display()
{
    struct node*temp=front;
    if(temp==NULL){
        printf("Q IS EMPTY");
    }
    else{
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->link;
        }
    }
}
void enq(int item)
{
    struct  node*temp;
    struct node* new=malloc(sizeof(struct node));
    new->data=item;
    if(front==NULL){
        front=new;
        rear=new;
        front->link=NULL;
        rear->link=NULL;
    }
    else
    {
        rear->link=new;
        rear=new;
        rear->link=NULL;
    }
}
void rev(){
    if(front==NULL){
        printf("empty");
    }
    else{
        
        struct node*temp;
        struct node*temp1;
        while(front!=NULL)
        {
            temp=front;
            struct node* stack=(struct node*)malloc(sizeof(struct node));
            if(stack==NULL){
                stack->data=front->data;
                top=stack;
                top->link=NULL;
                front=front->link;
                temp->link=NULL;
                free(temp);
            }
            else{
                
                stack->data=front->data;
                stack->link=top;;
                top=stack;
                front=front->link;
                temp->link=NULL;
                free(temp);
            }
        }
    }
    while(top!=NULL){
        enq(top->data);
        top=top->link;
    }
    display();
}
void main()
{
    int n;
    printf("Enter elements into the queue -1 to exit");
    while(1){
        scanf("%d",&n);
        if(n!=-1)
            enq(n);
        else
            break;

    }
    printf("the queue is :\n");
    display();
    printf("the reversed queue is\n ");
    rev();
    
    

}