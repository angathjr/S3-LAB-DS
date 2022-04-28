#include<stdio.h>
#include<stdlib.h>
#define MAX 15
struct tuple
{
    int row;
    int col;
    int value;
}t1[MAX],t2[MAX],tran1[MAX],tran2[MAX],sum[MAX];
void totuple(struct tuple[],int [][10],int,int);
void transpose(struct tuple[],struct tuple[] );
void findsum(struct tuple[],struct tuple[]);
void main()
{
    int a[10][10],b[10][10],i,j,k,acol,arow,brow,bcol;
    printf("enter row and col of 1st:");
    scanf("%d%d",&arow,&acol);
    printf("enter elements  1st:");
    for(i=0;i<arow;i++)
        for(j=0;j<acol;j++)
            scanf("%d",&a[i][j]);
    printf("\n1st matrix:\n");
    for(i=0;i<arow;i++){
        for(j=0;j<acol;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }

    printf("enter row and col of 2nd:");
    scanf("%d%d",&brow,&bcol);
    printf("enter elements 2st:");
    for(i=0;i<brow;i++)
        for(j=0;j<bcol;j++)
            scanf("%d",&b[i][j]);
    printf("\n2nd matrix:\n");
    for(i=0;i<brow;i++){
        for(j=0;j<bcol;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }

    totuple(t1,a,arow,acol);                        //totuple call
    totuple(t2,b,brow,bcol);
    printf("\n1st tuple matrix:\n");
    for(i=0;i<=t1[0].value;i++){
        printf("%d\t%d\t%d",t1[i].row,t1[i].col,t1[i].value);
        printf("\n");
    }
     printf("\n2nd tuple matrix:\n");
    for(i=0;i<=t2[0].value;i++){
        printf("%d\t%d\t%d",t2[i].row,t2[i].col,t2[i].value);
        printf("\n");
    }

    transpose(tran1,t1);
    transpose(tran2,t2);
    printf("\n1st transpose matrix:\n");
    for(i=0;i<=tran1[0].value;i++){
        printf("%d\t%d\t%d",tran1[i].row,tran1[i].col,tran1[i].value);
        printf("\n");
    }
     printf("\n2nd transpose matrix:\n");
    for(i=0;i<=tran2[0].value;i++){
        printf("%d\t%d\t%d",tran2[i].row,tran2[i].col,tran2[i].value);
        printf("\n");
    }


    findsum(t1,t2);
     printf("\nsum:\n");
    for(i=0;i<=sum[0].value;i++){
        printf("%d\t%d\t%d",sum[i].row,sum[i].col,sum[i].value);
        printf("\n");
    }

}

void totuple(struct tuple t[],int a[][10],int r,int c)         //totuple
{
    int i,j,k=1,count=0;
    t[0].row=r;
    t[0].col=c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                t[k].row=i;
                t[k].col=j;
                t[k].value=a[i][j]; 
                k++; 
                count++;  
            }           
        }
    }
    t[0].value=count;   
}

void transpose(struct tuple tran[],struct tuple t[] )      //transpose
{
    int n,i,j,k=1;
    n=t[0].value;
    tran[0].row=t[0].col;
    tran[0].col=t[0].row;
    tran[0].value=n;
    for(i=0;i<t[0].col;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(t[j].col==i)
            {
                tran[k].row=t[j].col;
                tran[k].col=t[j].row;
                tran[k].value=t[j].value;
                k++;
            }
        }
    }

}
void findsum(struct tuple a[],struct tuple b[])
{
    int i=1,j=i,k=1,count=0;
    if((a[0].col!=b[0].col)||(a[0].row!=b[0].row))
    {
        printf("cant add\n");
        exit(0);
    }
    else
    {
        sum[0].row=a[0].row;
        sum[0].col=a[0].col;
        while((i<=a[0].value)&&(j<=b[0].value))
        {
            if(a[i].row==b[j].row&&a[i].col==b[j].col)
            {
                sum[k].row=a[i].row; 
                sum[k].col=a[i].col;
                sum[k].value=a[i].value+b[j].value;
                i++;j++;
            }
            else if(a[i].row<b[j].row)
            {
                sum[k].row=a[i].row;
                sum[k].col=a[i].col;
                sum[k].value=a[i].value;
                i++;
            }
            else if(a[i].row>b[j].row)
            {
                sum[k].row=b[j].row;
                sum[k].col=b[j].col;
                sum[k].value=b[j].value;
                j++;
            }
            else if(a[i].col<b[j].col)
            {
                sum[k].row=a[i].row;
                sum[k].col=a[i].col;
                sum[k].value=a[i].value;
                i++;
            }
            else
            {
                sum[k].row=b[j].row;
                sum[k].col=b[j].col;
                sum[k].value=b[j].value;
                j++;
            }
            k++;
            count++;
        }
        while(i<=a[0].value)
        {
            sum[k].row=a[i].row;
            sum[k].col=a[i].col;
            sum[k].value=a[i].value;
            i++;
            k++;
            count++;
        }
        
        while (j<=b[0].value)
        {
             sum[k].row=b[j].row;
             sum[k].col=b[j].col;
            sum[k].value=b[j].value;
            j++;            
            k++;
            count++;  
        }
         sum[0].value=count;
        
    }
   
}