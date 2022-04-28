#include <stdio.h>
int n, i;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int lb, int ub)
{
	int pivot = a[lb];
	int start = lb;
	int end = ub;
	while (start < end)
	{
		while (a[start] <= pivot)
			start++;
		while (a[end] > pivot)
			end--;
		if (start < end)
		{
			swap(&a[start], &a[end]);
		}
	}
	swap(&a[lb], &a[end]);
	return end;
}

void QuickSort(int a[], int lb, int ub)
{
	if (lb < ub)
	{
		int loc = partition(a, lb, ub);
		QuickSort(a, lb, loc - 1);
		QuickSort(a, loc + 1, ub);
	}
}
void main()
{
	int mat[10];
	printf("Enter the size of array");
	scanf("%d", &n);
	printf("Enter the elements of array");
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &mat[i]);
	}
	QuickSort(mat, 0, n - 1);
	printf("Sorted array is ");
	for (i = 0; i < n; i++)
	{
		printf("%d", mat[i]);
	}
}
