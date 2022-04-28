#include<stdio.h>
#include<stdlib.h>
struct node
{
   int e;
   int c;
   struct node* link; 
}*head1,*head2,*head3,*t1,*t2;
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
    printf("Enter the coefficient and exponent of first polynomial");
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
    printf("Enter the number of terms in the second polynomial");
    scanf("%d",&m);
    printf("Enter the coefficient and exponent of Second polynomial ");
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
    struct node*t3,*t4,*nxtpos;
    t1=head1;
    while(t1!=NULL)
	{
		t2=head2;
		while(t2!=NULL)
		{
			struct node*poly3=malloc(sizeof(struct node));
    		poly3->link=NULL;
    		poly3->c=t1->c*t2->c;
    		poly3->e=t1->e+t2->e;
			if(head3==NULL)
    		{
       	 		head3=poly3;
        		t3=poly3;

    		}
    		else
    		{
        		t3->link=poly3;
        		t3=poly3;
    		}
    		t2=t2->link;
		}
		t1=t1->link;
	}
    t3=head3;
	while(t3->link!=NULL)
	{
		nxtpos=t3->link;
		while(nxtpos!=NULL)
		{
			if(nxtpos->e==t3->e)
			{
				t3->c+=nxtpos->c;
				t4=head3;
				while(t4->link!=nxtpos)
				{
					t4=t4->link;
				}
				nxtpos=nxtpos->link;
				free(t4->link);
				t4->link=nxtpos;
			}
			else
			{
				nxtpos=nxtpos->link;
			}
		}
		t3=t3->link;
    }
    int exp,coe;
    for(t3=head3;t3->link!=NULL;t3=t3->link)
    {
    	for(t4=head3;t4->link!=NULL;t4=t4->link)
    	{
    		if(t4->e < t4->link->e)
    		{
    			exp=t4->e;
    			coe=t4->c;
    			t4->c=t4->link->c;
    			t4->e=t4->link->e;
    			t4->link->c=coe;
    			t4->link->e=exp;
			}
		}
	}
    printf("\n\nFinal  Product is :");
    t3=head3;
    while(t3!=NULL)
    {
        printf("%d x^%d ",t3->c,t3->e);
        t3=t3->link;
        if(t3!=NULL)
        	printf("+");
    }
}
