#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *table[10];

void init()
{
	int i;
	for(int i=0;i<10;i++)
		table[i] = NULL;
}

void insert(int value)
{
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	int index = value%10;
	if(table[index]==NULL)
		table[index] = newnode;
	else
	{
		struct node *ptr = table[index];
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}
}

struct node* search(int value)
{
	int index = value%10;
	int flag=0;
	struct node *ptr = table[index];
	while(ptr!=NULL)
	{
		if(ptr->data==value)
		{
			flag=1;
			return ptr;
		}
		ptr = ptr->next;
	}
	if(flag==0)
	{
		printf("Value not found in the table\n");
		return NULL;
	}
}

void delete(int value)
{
	int index = value%10;
	struct node *ptr = table[index];
	struct node *temp = ptr;
	int flag=0;
	if(ptr->data==value)
	{
		table[index] = ptr->next;
		free(ptr);
		return;
	}
	while(ptr!=NULL)
	{
		if(ptr->data==value)
		{
			flag=1;
			break;
		}
		else
		{
			temp = ptr;
			ptr = ptr->next;
		}
	}
	if(flag==1)
	{
		temp->next = ptr->next;
		free(ptr);
	}
	else
		printf("Value not found\n");
}

void display()
{
	for(int i=0;i<10;i++)
	{
		struct node *ptr = table[i];
		printf("Chain[%d]-->",i);
		while(ptr)
		{
			printf("%d -->",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	init();
	insert(12);
	insert(14);
	insert(13);
	insert(2);
	insert(6);
	insert(22);
	insert(8);
	delete(8);
	delete(2);
	display();
	return 0;
}