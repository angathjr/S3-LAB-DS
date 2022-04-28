#include<stdio.h>
#include<stdlib.h>
int key;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *create()
{
    int x;
    struct node*new=malloc(sizeof(struct node));
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    else
    {
        new->data=x;
        printf("Enter the left node for %d: ",x);
        new->left=create();
        printf("Enter the right node for %d: ",x);
        new->right=create();
        return new;
    }
}
struct node*search(struct node* root)
{
    struct node*ptr;
    ptr=root;
    if(ptr->data!=key)
    {
        if(ptr->left!=NULL)
        {
            search(ptr->left);
        }
        else{
            return ptr;
        }
        if(ptr->right!=NULL)
        {
            search(ptr->right);
        }
        else
            return ptr;
    }
    else{
        return ptr;
    }
}

void insert(struct node*root)
{
    struct node*ptr,*new1;
    int key,item;
    char ch;
    printf("Enter the data content in positon node :");
    scanf("%d",&key);
    ptr=search(root);
    if(ptr==NULL)
    {
        printf("Exit");
        exit(0);
    }
    if(ptr->left==NULL || ptr->right==NULL)
    {
        printf("ENter the new node data:");
        scanf("%d",&item);
        struct node*temp=malloc(sizeof(struct node));
        printf("left or Right?");
        scanf("%c",&ch);
        if(ch=='L')
        {
            if(ptr->left==NULL)
            {
                ptr->left=temp;
                temp->data=item;                
                temp->left=NULL;
                temp->right=NULL;
            }
        }
        if(ch=='R')
        {
            if(ptr->right==NULL)
            {
                ptr->right=temp;
                temp->data=item;                
                temp->left=NULL;
                temp->right=NULL;
            }
        }
    }
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node*root)
{
    if(root==NULL)
        return ;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node*root)
{
    if(root==NULL) 
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main()
{
    struct node*root=NULL;
    printf("Enter the root node:");
    root=create();
    int n,ch;
    while(1)
    {
        printf("\nmenu\n\n");
        printf("\n1.insert");
        printf("\n2.preorder");
        printf("\n3.Inorder");
        printf("\n4.postorder");
        printf("\n5.Delete");
        printf("\n6.Exit");
        printf("\n\nEnter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    insert(root);
                    break;
            case 2:
        		printf("\nPreorder traversal:");
        		preorder(root);
        		break;

      		case 3:
        		printf("\nInorder traversal:");
        		inorder(root);
       			break;

       		case 4:
       			printf("\npostorder traversal:");
       			postorder(root);
       			break;

       		case 5:
       			//delete();
       			//break;

       		case 6:
        		exit(0);

        }
    }
        

}