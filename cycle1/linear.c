#include<stdio.h>
void main()
{
    int AR[20],n,pos=-1,key,i;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&AR[i]);

    }
    printf("Enter the element to be search");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==AR[i])
        {
            pos=i;
            break;
        }

    }
    if(pos)
     printf("Element found at position %d",i+1);
    else
     printf("Element didnt found");
}


