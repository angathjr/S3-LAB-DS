#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,min,n,a[50],temp;

    printf("ENTER SIZE");
    scanf("%d",&n);
    printf("ENTER ARRAY");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {  
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                {min=j;}
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    printf("AFTER SORT");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}