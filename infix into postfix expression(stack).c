#include<stdio.h>
#include<ctype.h>
#include<string.h>
static char stack[20];
int top=-1;
char priority(char);
char push(char);
char pop();
int main()
{
 char in[20],post[20],ch;
 int i,j,len;

 printf("Enter infix Expression : \n");
 gets(in);
 len=strlen(in);
 for(i=0,j=0;i<len;i++)
 if(isalpha(in[i]))
 post[j++]=in[i];
 else
 {
  if(in[i]=='(')
  push(in[i]);
  else if(in[i]==')')
  while((ch=pop())!='(')
  post[j++]=ch;
  else
  {
  while(priority(in[i])<=priority(stack[top]))
  post[j++]=pop();
  push(in[i]);
  }
 }
 while(top!=-1)
 post[j++]=pop();
 post[j]='\0';
 printf("\nEquivalent postfix expression is:%s",post);
return 0;
}
char priority (char c)
{
 switch(c)
 {
  case'+': return 1;
  case'-': return 1;
  case'*': return 2;
  case'/': return 2;
  case '^':return 3;
  case '%':return 2;
 }
 return 0;
}
char push(char c)
{
 stack[++top]=c;
}
char pop()
{
 return(stack[top--]);
}

