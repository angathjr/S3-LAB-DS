#include<stdio.h>
#include<stdlib.h>
#define max 15
int  dequeue[max];
int f=-1;
int r=-1;
void enqueuefront(int x)
{
	if((f==0&&r==max-1)||(f==r+1))
	{
		printf("Queue is full");
	}
	else if(f==-1&&r==-1)
	{
		f=r=0;
		dequeue[f]=x;
	}
	else if(f==0)
	{
		f=max-1;
		dequeue[f]=x;
	}
	else
	{
		f=f-1;
		dequeue[f]=x;
	}
}
void enqueuerear(int x)
{
	if((f==0&&r==max-1)||(r==f-1))
	{
		printf("Queue is full");
	}
	else if(f==-1&&r==-1)
	{
		f=r=0;
		dequeue[r]=x;
	}
	else if(r==max-1)
	{
		r=0;
		dequeue[r]=x;
	}
	else
	{
		r=r+1;
		dequeue[r]=x;
	}
}
void deletefront()
{
	if(f==-1&&r==-1)
	{
		printf("Queue is empty");
	}
	else if(f==0)
	{
		printf("the deleted element is %d",dequeue[f]);
		f=max-1  ;
	}
	else if(f==r)
	{
		printf("the deleted element is %d",dequeue[f]);
		f=r=-1;
	}
	else
	{
		printf("the deleted element is %d",dequeue[f]);
		f=f+1;
	}
}
void deleterear()
{
	if(f==-1&&r==-1 )
	{
		printf("Queue is empty");
	}
	 else if(r==max-1)
	{
		printf("the deleted element is %d",dequeue[r]);
		r=0;
	}
	else if(f==r)
	{
		printf("the deleted element is %d",dequeue[r]);
		f=r=-1;
	}
	else
	{
		printf("the deleted element is %d",dequeue[f]);
		r=r-1;
	}
}
void display()
{
       int i=f;
       if(f==-1&&r==-1)
       {
       		printf("empty Queue");
       }		
       printf("\n");
	while(i!=r)
	{
	      printf("%d ",dequeue[i]);
	      i=(i+1)%max;

	}
	printf("%d",dequeue[r]);
}				

void main()
{
	int ch,x,y;
	while(1)
	{
		printf("\n** Stack Menu **");
		printf("\n\n1.Enqueuefront\n2.Dequeuefront\n3.Enqueuerear\n4.Dequeuerear\n5.Display\n6.Exit");
		printf("\n\nEnter your choice(1-4):");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("enter the element to \n");
			   scanf("%d",&x);
			   enqueuefront(x);
			   break;
		case 2:deletefront();
			 break;
		case 3:printf("enter the element to \n");
			   scanf("%d",&y);
			   enqueuerear(y);
			   break;
	        case 4:deleterear();
			   break;
		case 5: display();
			   break;
		case 6: exit(0);
		default: printf("\nWrong Choice!!");
    	}

	}
}