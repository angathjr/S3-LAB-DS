#include<stdio.h>
void main()
{
    int n,AR[20],i,mid,key,pos=-1;
    printf("Enter the no of elements in the array");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&AR[i]);

    }
    printf("Enter the item to be searched");
    scanf("%d",&key);
    int first=0;
    int last=n-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(key==AR[mid])
        {
            pos=mid;
            break;

        }
        if(key<AR[mid])
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
        

    }
    if(pos!=-1)
    {
        printf("The item is found at position %d",pos+1);
    }
    else
    {
        printf("the item is not found in the array");

    }
}