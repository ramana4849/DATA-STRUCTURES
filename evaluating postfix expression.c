#include<stdio.h>
#include<ctype.h>
#include<string.h>
int stack[50];
int top=-1;
int push(int);
int pop();
int main()
{
  char postfix[50],ch;
  int i=0,op1,op2;
    printf("Enter the Postfix Expression:\n");
  gets(postfix);
  while( (ch=postfix[i++]) != '\0')
  {
    if(isdigit(ch))
    push(ch-48);
    else
    {
      op2=pop();
      op1=pop();
      switch(ch)
      {
	case '+':push(op1+op2);break;
	case '-':push(op1-op2);break;
	case '*':push(op1*op2);break;
	case '/':push(op1/op2);break;
	case '%':push(op1%op2);break;
	default: printf("Input invalid \n");

      }
    }
  }
  printf("Result: %d\n",stack[top]);
  return 0;
}
int pop()
{
  return(stack[top--]);
}
int push(int elem)
{
  stack[++top]=elem;
}
