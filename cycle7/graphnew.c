#include <stdio.h>
int n, mat[10][10], visited1[10], visited2[10], vtx[10], q[20], r = -1, f = 0;
char vertices[20];
void bfs(int);
void dfs(int);
void main()
{
    int i, j, x;
    printf("Enter no of vertices:");
    scanf("%d", &n);
    printf("Enter the vertices");
    for (int i = 0; i < n; ++i)
    {
        scanf(" %c", &vertices[i]);
    }
    for (i = 0; i < n; i++)
    {
        visited1[i] = 0;
        visited2[i] = 0;
        for (j = 0; j < n; j++)
        {
            printf("Is %c and %c connected y/n :", vertices[i], vertices[j]);
            scanf("%d", &mat[i][j]);
        }
    }
    char ch;
    int m;
    printf("\nEnter staring vertex: ");
    scanf(" %c", &ch);
    for (m = 0; m < n; m++)
    {
        if (ch == vertices[m])
            break;
    }
    bfs(m);
    printf("\n");
    printf("DFS: ");
    dfs(m);
}
void bfs(int v)
{
    int x, i;
    printf("\nBFS:");
    visited1[v] = 1;
    q[++r] = v;
    while (r >= f)
    {
        x = q[f++];
        printf("%c ", vertices[x]);
        for (i = 0; i < n; i++)
        {
            if ((mat[x][i] && (visited1[i] == 0)))
            {
                q[++r] = i;
                visited1[i] = 1;
            }
        }
    }
}
void dfs(int v)
{
    int i;
    printf("%c ", vertices[v]);
    visited2[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (visited2[i] == 0 && mat[v][i] == 1)
        {
            dfs(i);
        }
    }
}
