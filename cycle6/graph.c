#include <stdio.h>
#include <stdlib.h>
int graph[100][100];
int nv = 0;
char vertices[10];
int visited[100];
int visited_index = 0;
int queue[100];
int front = -1;
int rear = -1;
void enqueue(int data)
{
    if (front == -1)
        front++;
    queue[++rear] = data;
}

int dequeue()
{
    return queue[front++];
    if (front > rear)
        front = rear = -1;
}
void display()
{
    printf(" ");
    for (int i = 0; i < nv; ++i)
    {
        printf(" %c", vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < nv; ++i)
    {
        printf("%c ", vertices[i]);
        for (int j = 0; j < nv; ++j)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int is_visited(int data)
{
    for (int i = 0; i < visited_index; ++i)
    {
        if (visited[i] == data)
            return 1;
    }
    return 0;
}
void add_visited(int data)
{
    visited[visited_index++] = data;
}
int index_of(int n)
{
    for (int i = 0; i < nv; ++i)
    {
        if (vertices[i] == n)
            return i;
    }
    return -1;
}
void bfs()
{
    visited_index = 0;
    front = rear = -1;
    add_visited(vertices[0]);
    enqueue(vertices[0]);
    while (front <= rear)
    {
        int n = dequeue();
        printf("%d ", n);
        for (int i = 0; i < nv; ++i)
        {
            if (is_visited(vertices[i]) == 0 && graph[index_of(n)][i] == 1)
            {
                add_visited(vertices[i]);
                enqueue(vertices[i]);
            }
        }
    }
}
void dfs(int n)
{
    add_visited(n);
    printf("%d ", n);
    for (int i = 0; i < nv; ++i)
    {
        if (is_visited(vertices[i]) == 0 && graph[index_of(n)][i] == 1)
            dfs(vertices[i]);
    }
}
int main()
{
    printf("Enter the no of vertices");
    scanf("%d", &nv);
    printf("Enter the vertices");
    for (int i = 0; i < nv; ++i)
    {
        scanf(" %c", &vertices[i]);
    }
    for (int i = 0; i < nv; ++i)
    {
        for (int j = 0; j < nv; ++j)
        {
            printf("Is %c and %c connected y/n :", vertices[i], vertices[j]);
            char temp;
            getchar();
            scanf("%c", &temp);
            graph[i][j] = temp == 'y' ? 1 : 0;
        }
    }
    while (1)
    {
        int choice;
        printf("\nEnter the choice \n1.Display\n2.BFS\n3.DFS\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            display();
            break;
        }
        case 2:
        {

            bfs();
            break;
        }
        case 3:
        {
            visited_index = 0;
            dfs(vertices[0]);
            break;
        }
        case 4:
        {
            return 0;
        }
        }
    }
    return 0;
}