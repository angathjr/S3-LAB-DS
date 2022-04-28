
#include <stdio.h>
int i, n;
int b[20];
int mat[10];
void merge(int a[], int lb, int mid, int ub)
{

	i = lb;
	int j = mid + 1;
	int k = lb;
	while (i <= mid && j <= ub)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
		k++;
	}

	while (j <= ub)
	{
		b[k] = a[j];
		j++;
		k++;
	}

	while (i <= mid)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	for (i = lb; i <= ub; i++)
	{
		a[i] = b[i];
	}
}
void MergeSort(int a[], int lb, int ub)
{
	if (lb < ub)
	{
		int mid = (ub + lb) / 2;
		MergeSort(a, lb, mid);
		MergeSort(a, mid + 1, ub);
		merge(a, lb, mid, ub);
	}
}
void main()
{

	printf("Enter the size of array");
	scanf("%d", &n);
	printf("Enter the elements of array");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &mat[i]);
	}
	MergeSort(mat, 0, n - 1);
	printf("Sorted array is ");
	for (i = 0; i < n; i++)
	{
		printf("%d", b[i]);
	}
}
