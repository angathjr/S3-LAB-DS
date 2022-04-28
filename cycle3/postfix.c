#include <stdio.h>
#include <math.h>
#define max 30
char stack[max], post[max];
float eval[10];
int top = -1, top2 = -1;
char pop()
{
	if (top != -1)
	{
		top = top - 1;
		return stack[top + 1];
	}
}
void push(char x)
{
	top++;
	stack[top] = x;
}
void pushpost(char x)
{
	top2++;
	post[top2] = x;
}
int operand(char ch)
{
	int x = (ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z');
	return x;
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
	printf("\n\nfinal postfix answer:");
	for (i = 0; i <= top2; i++)
		printf("%c", post[i]);
}
void evaluate()
{
	int i = 0, j = 0, x;
	while (i <= top2)
	{
		if (operand(post[i]))
		{

			printf("\nEnter value for %c ", post[i]);
			scanf(" %f", &eval[j]);
		}
		else
		{
			switch (post[i])
			{
			case '+':
				eval[j - 2] = eval[j - 2] + eval[j - 1];
				break;
			case '-':
				eval[j - 2] = eval[j - 2] - eval[j - 1];
				break;
			case '*':
				eval[j - 2] = eval[j - 2] * eval[j - 1];
				break;
			case '/':
				eval[j - 2] = eval[j - 2] / eval[j - 1];
				break;
			case '^':
				eval[j - 2] = pow(eval[j - 2], eval[j - 1]);
				break;
			}

			j = j - 2;
		}
		++i;
		++j;
	}
	printf("\n\nfinal eval answer=");
	printf("%f", eval[0]);
}
void main()
{
	char a[max], c;
	printf("Enter exp :");
	scanf("%s", a);
	int i, j;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == '(')
			push(a[i]);
		else if (operand(a[i]))
			pushpost(a[i]);
		else if (prec(a[i]) != -1)
		{
			if (top == -1)
				push(a[i]);
			else if (prec(a[i]) > prec(stack[top]))
				push(a[i]);
			else
			{

				while ((prec(a[i]) <= prec(stack[top])) && (top != -1))
				{
					if (stack[top] == '(')
						break;
					c = pop();
					pushpost(c);
				}
				push(a[i]);
			}
		}
		else if (a[i] == ')')
		{
			while (stack[top] != '(')
			{
				c = pop();
				pushpost(c);
			}
			top--;
		}
	}
	while (top != -1)
	{
		pushpost(pop());
	}
	display();

	evaluate();
}