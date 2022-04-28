#include <stdio.h>
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void maxHeapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1, r = 2 * i + 2;
	if ((l < n) && (a[l] > a[largest]))
	{
		largest = l;
	}
	if ((r < n) && (a[r] > a[largest]))
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(&a[i], &a[largest]);
		maxHeapify(a, n, largest);
	}
}

void heapsort(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{

		maxHeapify(a, n, i);
	}
	for (i = n - 1; i >= 0; i--)
	{

		swap(&a[0], &a[i]);
		maxHeapify(a, i, 0);
	}
}

void binary(int a[], int n, int s)
{
	int mid, left = 0, right = n - 1, flag = -1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == s)
		{
			printf("Searcch element %d found at index %d\n", s, mid);
			flag = 0;
			break;
		}

		else if (s < a[mid])
			right = mid - 1;

		else
			left = mid + 1;
	}

	if (flag == -1)
		printf("Search element %d not found\n", s);
}

void main()
{
	int i, a[20];
	int n, s;
	printf("Enter no.of elements:");
	scanf("%d", &n);
	printf("Enter the elements:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	heapsort(a, n);

	printf("\nSorted array:");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n\nEnter the element to search:");
	scanf("%d", &s);
	binary(a, n, s);
}
