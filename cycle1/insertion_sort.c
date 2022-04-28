#include<stdio.h>
void main()
{
   int i,j,n,ar[20],temp;
   printf("Enter the size of the array");
   scanf("%d",&n); 
   printf("enter the array elements");
   for(i=0;i<n;i++)
   {
     scanf("%d",&ar[i]);
   }
   for(i=1;i<n;i++)
   {
      temp=ar[i];
       j=i-1;
       while(j>=0 && ar[j]>temp)
       {
           ar[j+1]=ar[j];
           j=j-1;
       }
       ar[j+1]=temp;
   }
   printf("the sorted array is ");
   for (i=0;i<n;i++)
   { 
       printf("%d ",ar[i]);
   }

}