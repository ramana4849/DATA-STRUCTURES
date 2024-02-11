
#include<stdio.h>
#include<stdlib.h>
int push();
int pop();
int display();
int stack[20],top=-1,n;
int main()
{
int choice;

printf("Enter size of stack:\t");
scanf("%d",&n);
while(1)
{
printf("\n*** MENU ***\n1.PUSH\t 2.POP\t 3.DISPLAY\t  4.EXIT");
printf("\nEnter your choice from menu:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:push();
       break;
case 2:pop();
       break;
case 3:display();
       break;
case 4:exit(0);
default:printf("Wrong Choice\n");
}
}
}
int push(int x)
{
if(top==n-1)
printf("Stack is full (Overflow)\n");
else
{
printf("Enter element to be pushed:\t");
scanf("%d",&x);
top++;
stack[top]=x;
}
}
int pop()
{
if(top==-1)
printf("Stack is empty (Underflow)\n");
else
{
int x;
x=stack[top];
top--;
printf("Deleted(Popped) element from stack is %d\n",x);
}
}


int display()
{
int i;
if(top==-1)
printf("\nStack is Empty\n");
else
{
printf("Stack contains\n");
for(i=top;i>=0;i--)
printf("%d\t",stack[i]);
}
}







































