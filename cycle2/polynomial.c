#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
    int c;
    int e;
} p[50];
int main()
{
    int i, j, m, n, k;
    printf("Enter the no of terms in the polynomial 1: ");
    scanf("%d", &m);
    printf("Enter the exponent and coefficient  in the ascending order: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &p[i].e, &p[i].c);
    }
    printf("Enter the no of terms in the polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the exponent and coefficient of polynomial 2 in ascending order: ");
    for (i = m; i < m + n; i++)
    {
        scanf("%d %d", &p[i].e, &p[i].c);
    }
    i = 0;
    j = m;
    k = m + n;
    while (i < m && j < m + n)
    {
        if (p[i].e > p[j].e)
        {
            p[k].c = p[j].c;
            p[k].e = p[j].e;
            j++;
        }
        else if (p[i].e < p[j].e)
        {
            p[k].c = p[i].c;
            p[k].e = p[i].e;
            i++;
        }
        else
        {
            p[k].c = p[i].c + p[j].c;
            p[k].e = p[i].e;
            i++;
            j++;
        }
        k++;
    }
    while (i < m)
    {
        p[k].c = p[i].c;
        p[k].e = p[i].e;
        i++;
        k++;
    }
    while (j < m + n)
    {
        p[k].c = p[j].c;
        p[k].e = p[j].e;
        j++;
        k++;
    }
    printf("The first polynomial is\n");
    for (i = 0; i < m; i++)
        printf("%d x^ %d +", p[i].c, p[i].e);
    printf("\nThe second polynomial is\n");
    for (i = m; i < m + n; i++)
        printf("%d x^ %d +", p[i].c, p[i].e);
    printf("\nThe sum of the polynomial is \n");
    for (i = m + n; i < k; i++)
    {
        printf("%d x^ %d +", p[i].c, p[i].e);
    }
    return 0;
}