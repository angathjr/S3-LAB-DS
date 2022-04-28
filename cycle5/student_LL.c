#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=1;
struct node
{
    int roll,mark;
    char name[20];
    struct node*link;
}*head,*tail,*temp;
void insert()
{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the name of student: ");
    scanf("%s",&new->name);
    printf("\nEnter the roll number:");
    scanf("%d",&new->roll);
    printf("Enter the mark :");
    scanf("%d",&new->mark);
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
        tail=new;
    }
    else
    {
        tail->link=new;
        tail=new;
    }
    count++;
}
void delete()
{
    int no,flag=0;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d",&no);
    struct node *temp,*current;
    temp=head;
    if(head->roll==no)
    {
        printf("\nDeleted roll number is %d",no);
        head=head->link;
        free(temp);
    }
    else
    {
        while(temp->link!=NULL)
        {
            if(temp->link->roll==no)
            {
                current=temp->link;
                printf("Deleted roll number is %d",no);
                if(current->link==NULL)
                    tail=temp;
                temp->link=current->link;
                free(current);
                flag=1;
                break;
            }
            temp=temp->link;
        }
        if(flag==0)
            printf("The number doesnt exist");
    }
    
}
void display()
{
    if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        temp=head;
        printf("\nThe list is:\n");
        while(temp!=NULL)
        {
            printf("\n\nName :%s",temp->name);
            printf("\nRoll.No :%d",temp->roll);
            printf("\n Mark :%d",temp->mark);
            temp=temp->link;
        }
    }
}
void search()
{
    int no,pos=1,flag=-1;
    temp=head;
    printf("Enter the roll number to search:");
    scanf("%d",&no);
    while(temp!=NULL)
    {
        if(temp->roll==no)
        {
            printf("The number is found at position %d",pos);
            printf("\nName :%s",temp->name);
            printf("\n Roll.No : %d",temp->roll);
            printf("\nMark :%d",temp->mark);
            flag=1;
            break;
        }
        temp=temp->link;
        pos++;
    }
    if(!flag)
        printf("The roll number is  not present in the list");

}
void sort()
{
    struct node*t1,*t2;
    int i,j,roll,mrk;
    char nm[20];
    if(head==NULL)
        printf("Empty list");
    else
    {
        printf("\nThe sorted list is:\n");
        for(t1=head;t1->link!=NULL;t1=t1->link)
        {
            for(t2=head;t2->link!=NULL;t2=t2->link)
            {
                if(t2->roll > t1->link->roll)
                {
                    roll=t2->roll;
                    t2->roll=t1->link->roll; 
                    t1->link->roll=roll;

                    mrk=t2->mark;
                    t2->mark=t1->link->mark;
                    t1->link->mark=mrk;

                    strcpy(nm,t2->name);
                    strcpy(t2->name,t1->link->name);
                    strcpy(t1->link->name,nm);
                      
                }
            }
        }

    }
}
void main()
{
    int n;
    while(1)
    {
        printf("\n\nMENU");
        printf("\n1.Insert\n2.Delete \n3.Search\n4.sort(rollnumber)\n5.Exit\n\n");
    	printf("\nEnter your choice : ");
    	scanf("%d",&n);
        switch(n)
        {
    		case 1: insert();
    		    	display();
				    break;
        	case 2: delete();
         	    	display();
         	    	break;
         	case 3: search();
				    break;
			case 4: sort();
				    display();
				    break;     	
    		case 5: printf("Exited");
                    exit(0);
            default:printf("Invalid input!!");
    	}

    
    }
}