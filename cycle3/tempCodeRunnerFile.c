#include<stdio.h>
#define max 30
char stack[max],post[max];
int top=-1,top2=-1,len;
char pop()
{
	if (top!=-1)
	{
		top=top-1;
		return stack[top+1];
	}
}
void push(char x)
{
	top++;
	stack[top]=x;
}

void pushpost(char x)
{
	top2++;
	post[top2]=x;
}

int operand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}

int prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

void display()
{
	int i;
	printf("\n\nfinalprefix answer=");
	for(i=top2;i>=0;i--)
		printf("%c",post[i]);
}

void main()
{
	char a[max],c;
	printf("enter exp:");
	gets(a);
	int i,j;
	for(i=0;a[i]!='\0';i++)
	{}
	len=i;
	for(i=len-1;i>=0;i--)
	{
		if(operand(a[i]))
			pushpost(a[i]);
		else if(prec(a[i])!=-1)
			{
				if (top==-1)
					push(a[i]);
				else if(prec(a[i])>=prec(stack[top]))
					push(a[i]);
				else
				{
					while((prec(a[i])<prec(stack[top]))||(top!=-1))
					{
						if(stack[top]==')')
							break;
						c=pop();
						pushpost(c);
					}

					push(a[i]);
				}

			}
		if(a[i]==')')
			push(a[i]);
		else if(a[i]=='(')
		{

			while(stack[top]!=')')
			{
				c=pop();
				pushpost(c);
			}
			top--;
		}
	}
	while(top!=-1)
	{
		pushpost(pop());
	}
	display();

}