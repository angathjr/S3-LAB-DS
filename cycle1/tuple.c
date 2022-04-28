#include<stdio.h>
void main()
{
    int a[20][20],i,j,m,n;
    int b[20][20];
    printf("enter the array");
    scanf("%d %d",&m,&n);
    printf("enter the array elements");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d ",&a[i][j]);
        }

    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            while(a[i][j]!=0)
            {
                n=0;
                while(n>2)
                {
                    b[i][n]=i;n++;
                    b[i][n]=j;n++;
                    b[i][n]=a[i][j];

                }
            }
        }

    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",&b[i][j]);
        }

    }

}