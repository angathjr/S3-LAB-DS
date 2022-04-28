#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node* root=NULL;
void inorder(struct node* node)
{
	if(node ==NULL)
	{
		return;
	}
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
	
}
void preorder(struct node* node)
{
	if(node ==NULL)
	{
		return;
	}
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
	
}
void postorder(struct node* node)
{
	if(node ==NULL)
	{
		return;
	}
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}


void insert(int item)
{	
	struct node* ptr=root,*ptr1,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));

	newnode->data=item;
	if(newnode->data==-1)
		return;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
		return;
	}

	while(ptr!=NULL)
	{
		if(ptr->data>newnode->data)
		{
			ptr1=ptr;
			ptr=ptr->left;
		}
		else if(ptr->data<newnode->data)
		{
			ptr1=ptr;
			ptr=ptr->right;
		}
		else
		{
			printf("\nItem already exist");
			return;
		}
	}	
	if(ptr1->data>newnode->data)
		ptr1->left=newnode;
	else
		ptr1->right=newnode;
}
void create()
{
	int x;
	printf("\n**-1 to stop**");
	while(1)
	{
		printf("\nEnter value to insert:");
		scanf("%d",&x);
		if(x==-1)
			return;
		insert(x);
	}
}
void delete(int item)
{
	struct node* ptr=root,*ptr1=NULL;
	int flag=0,val;
	if(root==NULL)
	{
		printf("\nTree is empty");
		return;
	}
	while((ptr!=NULL)&&(flag==0))
	{
		if(ptr->data>item)
		{
			ptr1=ptr;
			ptr=ptr->left;
		}
		else if(ptr->data<item)
		{
			ptr1=ptr;
			ptr=ptr->right;
		}
		else
		{
			flag=1;
			break;
		}
	}	
	if(flag==0)
	{
		printf("\n%d doesnt exist",item);
		return;
	}
	
	if((ptr->left==NULL)&&(ptr->right==NULL))
	{
		if(ptr1==NULL)
		{	
			root=NULL;
			return;
		}
		if(ptr1->left==ptr)
			ptr1->left=NULL;
		else
			ptr1->right=NULL;
	}
	
	else if((ptr->left!=NULL)&&(ptr->right!=NULL))
	{
		struct node* temp;
		temp=ptr->right;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		val=temp->data;
		delete(val);
		ptr->data=val;
	}
	
	else
	{
		if(ptr1->left==ptr)
		{
			if(ptr->right==NULL)
				ptr1->left=ptr->left;
			else
				ptr1->left=ptr->right;
		}
		else
		{
			if(ptr->right==NULL)
				ptr1->right=ptr->left;
			else
				ptr1->right=ptr->right;
		}
	}
}
int leaf;
void countleaf(struct node* node)
{
	if(node==NULL)
		return;
	
	if(node->left==NULL&&node->right==NULL)
	{
		leaf++;
		return;
	}
	if(node->right!=NULL)
		countleaf(node->right);
	if(node->left!=NULL)
		countleaf(node->left);
	
}
void main()
{
	int c,x;
	
	
	create();
	while(1)
	{
		printf("\n\n..OPTIONS..\n1.Insert node to the binary search tree\n2.Inorder Traversal\n3.Preorder traversal\n4.Post order traversal\n5.Delete a node\n6.Count leaf nodes\n7.Exit");
		printf("\nEnter an option:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("\nEnter value to insert:");
				scanf("%d",&x);
				insert(x);
				printf("\nInorder traversal:");
				inorder(root);
				break;
			}
			case 2:
			{	
				printf("\nInorder traversal:");
				inorder(root);
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
				scanf("%d",&x);
				delete(x);
				printf("\nInorder traversal:");
				inorder(root);
				break;
			}
			case 6:
			{
				leaf=0;
				countleaf(root);
				printf("\nNo.of leaf nodes:%d",leaf);
				break;
			}
			
			case 7:
			{
				exit(0);
			}
		}
	}
}
