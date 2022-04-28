#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    char data;
    struct node *nxt, *prev;
} * head, *temp, *temp1;
void display()
{
    if (head == NULL)
    {
        printf("Empty");
        exit(0);
    }
    else
    {
        temp1 = head;
        printf("\nThe entered string is :");
        while (temp1 != NULL)
        {
            printf("%c", temp1->data);
            temp1 = temp1->nxt;
        }
    }
}
void palindrome()
{
    struct node *front, *tail;
    tail = temp;
    front = head;
    if (front == tail)
    {
        printf("\nThe given string  is palindrome ");
        return;
    }
    while (front != tail)
    {
        if (front->data != tail->data)
        {
            printf("\nThe given string is not palindrome ");
            return;
        }
        front = front->nxt;
        tail = tail->prev;
    }
    printf("\nThe given string is palindrome");
}
void main()
{
    char ch;
    printf("\nEnter the string with last character as \'0\' : ");
    while (1)
    {
        scanf("%c", &ch);
        if (ch == '0')
            break;
        struct node *new = malloc(sizeof(struct node));
        new->data = tolower(ch);
        new->prev = NULL;
        new->nxt = NULL;
        if (head == NULL)
        {
            head = new;
            temp = head;
        }
        else
        {
            new->prev = temp;
            temp->nxt = new;
            temp = new;
        }
    }
    display();
    palindrome();
}
