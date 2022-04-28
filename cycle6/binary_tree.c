#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left, *right;
};
struct node *root = NULL;
int front = -1, rear = -1;
struct node *queue[25];
int count = 0;
void enqueue(struct node *newnode)
{
	if (front == -1 || rear == -1)
	{
		front++;
		rear++;
		queue[front] = newnode;
	}
	else
	{
		queue[++rear] = newnode;
	}
}

struct node *dequeue()
{
	if (front == -1 || front > rear)
	{
		return NULL;
	}
	else
	{
		return queue[front++];
	}
}
struct node *create()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	int x;
	scanf("%d", &x);
	if (x == -1)
	{
		return NULL;
	}
	else
	{
		count++;
		newnode->data = x;
		printf("left node of %d:", x);
		newnode->left = create();
		printf("right node of %d:", x);
		newnode->right = create();
		return newnode;
	}
}
void inorder(struct node *node)
{
	if (node == NULL)
	{
		return;
	}
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}
void preorder(struct node *node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}
void postorder(struct node *node)
{
	if (node == NULL)
	{
		return;
	}
	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}
void insert()
{
	struct node *tempnode = root, *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	front = rear = -1;
	printf("\nEnter value to insert:");
	scanf("%d", &newnode->data);
	newnode->left = NULL;
	newnode->right = NULL;
	if (root == NULL)
		root = newnode;
	else
	{
		while (front <= rear)
		{
			if (tempnode->left == NULL)
			{
				tempnode->left = newnode;
				return;
			}
			if (tempnode->right == NULL)
			{
				tempnode->right = newnode;
				return;
			}
			if (tempnode->left != NULL)
				enqueue(tempnode->left);
			if (tempnode->right != NULL)
				enqueue(tempnode->right);
			tempnode = dequeue();
		}
	}
}
void delete_last_node(struct node *last)
{
	struct node *tempnode = root;
	front = rear = -1;
	if (last == root)
	{
		root = NULL;
		return;
	}
	while (front <= rear)
	{

		if (tempnode->left == last)
		{
			tempnode->left = NULL;
			return;
		}
		if (tempnode->right == last)
		{
			tempnode->right = NULL;
			return;
		}
		if (tempnode->left != NULL)
			enqueue(tempnode->left);
		if (tempnode->right != NULL)
			enqueue(tempnode->right);
		tempnode = dequeue();
	}
}

void delete (int value)
{
	struct node *tempnode = root, *ptr = root;
	struct node *node_to_delete = NULL;
	front = rear = -1;
	if (root == NULL)
	{
		printf("\nTree empty");
		return;
	}
	else
	{
		enqueue(root);

		while (front <= rear)
		{

			tempnode = dequeue();
			if (tempnode->data == value)
			{
				node_to_delete = tempnode;
			}

			if (tempnode->left != NULL)
				enqueue(tempnode->left);
			if (tempnode->right != NULL)
				enqueue(tempnode->right);
		}
	}

	if (node_to_delete == NULL)
	{
		printf("\n%d not found in tree", value);
	}
	else
	{
		node_to_delete->data = tempnode->data;

		delete_last_node(tempnode);
	}
}
void main()
{
	printf("Enter root node:");
	root = create();
	int c;
	while (1)
	{
		printf("\n\n..OPTIONS..\n1.Insert node to the binary tree\n2.Inorder Traversal\n3.Preorder traversal\n4.Post order traversal\n5.Delete a node\n6.Exit");
		printf("\nEnter an option:");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
		{

			insert();
			break;
		}
		case 2:
		{
			printf("\nInorder traversal:");
			inorder(root);
			printf("no of nodes %d", count);
			break;
		}
		case 3:
		{
			printf("\nPreorder traversal:");
			preorder(root);
			break;
		}
		case 4:
		{
			printf("\nPostorder traversal:");
			postorder(root);
			break;
		}
		case 5:
		{
			printf("Enter the element to delete:");
			int x;
			scanf("%d", &x);
			delete (x);
			break;
		}
		case 6:
		{
			exit(0);
		}
		}
	}
}
