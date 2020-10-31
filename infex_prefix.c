#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 50
int top=-1;
char stk[SIZE];
int associativity(char op)
{
	if(op=='^' || op=='$')
	{
		return 1;
	}
	return 0;

}
void push(char e)
{
	stk[++top]=e;
}
char pop()
{
	return stk[top--];
}
int prior(char op)
{
	if(op=='+' || op=='-')
	{
		return 1;
	}
	else if(op=='*' || op=='/')
	{
		return 2;
	}
	else if(op=='^' || op=='$')
	{
		return 3;
	}
	return 0;
}
void main()
{
	char infix[SIZE],prefix[SIZE];
	int i,idx=0,ep,sp;
	clrscr();
	puts("Enter the infix exp:");
	gets(infix);

	for(i=strlen(infix)-1;i>=0;i--)
	{
		switch(infix[i])
		{
			case ')':   //
				push(infix[i]);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '$':
				ep=prior(infix[i]);
				sp=prior(stk[top]);

				if(ep==sp && )

				while(sp>ep)  // in postfix it is sp>=ep
				{
					prefix[idx++]=pop();
					sp=prior(stk[top]);  // to update stack priority again.
				}
				push(infix[i]);
				break;
			case '(':
				while(stk[top]!=')')
				{
					prefix[idx++]=pop();
				}
				pop();    //top--;  to delete or pop ')' from stack
				break;
			default:
				prefix[idx++]=infix[i];
		}

	}
	prefix[idx]=NULL;
	strrev(prefix);
	printf("\nThe prefix exp = %s",prefix);
	getch();


}
