#include<stdio.h>
#include<stdlib.h>
struct node
{
   int e;
   int c;
   struct node* link; 
};
void main()
{
    int n,m;
    int co,ex;
    struct node*head1=NULL;
    struct node*t1=NULL;
    struct node*head2=NULL;
    struct node*t2=NULL;
    printf("Enter number of terms in first polynomial:");
    scanf("%d",&n);
    printf("Enter the coefficient and exponent of first polynomial :");
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&co,&ex);
        struct node*poly1=malloc(sizeof(struct node));
        poly1->c=co;
        poly1->e=ex;
        poly1->link=NULL;
        if(head1==NULL) 
        {
            head1=poly1;
            t1=poly1;
        }
        else
        {
            t1->link=poly1;
            t1=poly1;
        }
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d",&m);
    printf("Enter the coefficient and exponent of Second polynomial: ");
    for(int j=1;j<=m;j++)
    {
        scanf("%d %d",&co,&ex);
        struct node*poly2=malloc(sizeof(struct node));
        poly2->c=co;
        poly2->e=ex;
        poly2->link=NULL;
        if(head2==NULL) 
        {
            head2=poly2;
            t2=poly2;
        }
        else
        {
            t2->link=poly2;
            t2=poly2;
        }
    }
    printf("\nThe first polynomial is :");
    t1=head1;
    while(t1!=NULL)
    {
        printf("%d x^%d ",t1->c,t1->e);
        t1=t1->link; 
        if(t1!=NULL)
            printf("+");
          
    }
    printf("\n\nThe second polynomial is:");
    t2=head2;
    while(t2!=NULL)
    {
        printf("%d x^%d ",t2->c,t2->e);
        t2=t2->link; 
        if(t2!=NULL)
            printf("+");  
         
    }
    t1=head1;
    t2=head2;
    printf("\n\nThe sum of the polynomial is:");
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->e > t2->e)
        {
            printf("%d x^%d ",t1->c,t1->e);
            t1=t1->link;
        }
        else if(t1->e < t2->e)
        {
            printf("%d x^%d ",t2->c,t2->e);
            t2=t2->link;
        }
        else
        {
            printf("%d x^%d ",t1->c+t2->c,t1->e);
            t1=t1->link;
            t2=t2->link;
        }
        if(t1!=NULL && t2!=NULL)
            printf("+");
    }
    while(t1!=NULL)
    {
        printf("%d x^%d ",t1->c,t1->e);
        t1=t1->link;
        while(t1!=NULL)
            printf("+");
    }
    while(t2!=NULL)
    {
        printf("%d x^%d ",t2->c,t2->e);
        t2=t2->link;
        while(t2!=NULL)
            printf("+");
        
    }
}