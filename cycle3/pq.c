#include<stdio.h>
#include<stdlib.h>
void penq();
void pdeq();
void display();
int N,pq[30],r=-1,f=-1;
int main()
{
    int k,n;
    printf("Enter the size of queue:");
    scanf("%d",&N);
    do
   { 
        printf("Enter 1 for enqueue\n2 for dequeue\n3 for display:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            penq();
            break;
            case 2:
            pdeq();
            break;
            case 3:
            display();
            break;
            default:
            exit(0);
        }
        printf("\nEnter 1 to do more operations and any other number to stop:");
        scanf("%d",&k);
    }while(k==1);
    return 0;
}
void penq()
{
    int pos,item;
    printf("Enter value to be inserted");
    scanf("%d",&item);
    if(r==N-1)
        printf("Overflow");
    else
    {
        pos=r;
        r+=1;
        while(pos>=0 && pq[pos]>=item)
        {
            pq[pos+1]=pq[pos];
            pos=pos-1;
        }
        pq[pos+1]=item;
        if(f==-1)
            f+=1;
    }
}

void pdeq()
{
    if(r==-1 && f==-1)
        printf("Underflow!");
    else if(f==r)
    {
        printf("The dequeued element is %d\n",pq[f]);
        f=-1;
        r=-1;
   
    }
    else
    {
        printf("The dequeued element is %d\n",pq[f]);
        f+=1;
        
    }

}
void display()
{
    int i;
    for(i=f;i<=r;i++)
        printf("%d ",pq[i]);
}