#include<stdio.h>
void bsort(int,int arr[]);
int main()
{
    int i,n,arr[25];
    printf("Enter the array size:");
    scanf("%d",&n);

    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    bsort(n,arr);
    return 0;

}
void bsort(int n,int arr[])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The sorted array is:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}