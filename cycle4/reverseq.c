#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} * front, *rear, *top;
void enque(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    if (front == NULL)
    {
        front = temp;
        rear = temp;
        front->link = NULL;
        rear->link = NULL;
    }
    else
    {
        rear->link = temp;
        rear = temp;
        rear->link = NULL;
    }
}
void deque()
{
    struct node *temp;
    if (front == NULL)
    {
        return;
    }
    else
    {
        temp = front;
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = temp->data;
        newnode->link = top;
        top = newnode;
        front = front->link;
        free(temp);
    }
    temp = top;
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("\nqueue:");
        while (temp != NULL)
        {
            printf("%d   ", temp->data);
            temp = temp->link;
        }
    }
}
void reverse()
{
    struct node *temp;
    temp = front;
    while (temp != NULL)
    {
        temp = front;
        printf("\ndequed %d", temp->data);
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = temp->data;
        if (top == NULL)
            top = newnode;
        else
            newnode->link = top;
        top = newnode;
        front = front->link;
        free(temp);
    }

    temp = top;
    printf("%d", temp->data);
    while (temp != NULL)
    {
        enque(temp->data);
        temp = temp->link;
    }
    printf("ssd");
    display();
}
void main()
{
    int ch, item;
    while (1)
    {

        printf("\n\nMENU\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DISPLAY IN REVERSE");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be added:");
            scanf("%d", &item);
            enque(item);
            display();
            break;
        case 2:
            reverse();
            exit(0);
        default:
            printf("Invalid input!!");
        }
    }
}
