#include<stdio.h>
#include<malloc.h>
int pop();
int display();
int push();
int ch,i,n,j,item,pos;

struct node
{
 int data;
 struct node *next;
}*top=NULL,*newnode,*temp;

int main()
{
 printf(" **** MENU **** ");
 while(1)
 {
  printf("\n1.PUSH\t 2.POP\t 3.DISPLAY \t 4.Exit\n");
  printf("Enter the choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: push();
	   break;
   case 2: pop();
	   break;
   case 3: display(); break;
   case 4: exit(0);    break;
   default:printf("Wrong choice");
  }
 }
}

int push()
{
 temp=top;
 printf("Enter the element to be pushed:");
 scanf("%d",&item);
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=item;
 if(top==NULL)
 {
  newnode->next=NULL;
  top=newnode;
 }
 else
 {
   newnode->next=top;
   top=newnode;
 }
}
int display()
{
 if(top==NULL)
 printf("STACK IS EMPTY (UNDERFLOW)\n");
 else
 {
  for(temp=top;temp->next!=NULL;temp=temp->next)
  printf("%d->",temp->data);
  printf("%d\n",temp->data);
 }
}
int pop()
{
 temp=top;
 if(top==NULL)
 printf("STACK IS EMPTY (UNDERFLOW)\n");
 else
 {
   item=top->data;
   printf("popped (deleted) element is:%d\n",item);
   top=top->next;
   free(temp);
  }
}

