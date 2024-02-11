#include<stdio.h>
#include<malloc.h>
int deletion();
int traverse();
int insert();
int ch,i,n,j,item,pos;

struct node
{
 int data;
 struct node *next;
}*start=NULL,*newnode,*temp,*p;

int main()
{

 printf(" **** MENU **** ");
 while(1)
 {
  printf("\n1.Insertion\t 2.Deletion\t 3.Traverse\t 4.Exit\n");
  printf("Enter the choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: insert();   break;
   case 2: deletion(); break;
   case 3: traverse(); break;
   case 4: exit(0);    break;
   default:printf("Wrong choice");
  }
 }
}

int insert()
{
 temp=start;
 printf("Enter the item to be inserted:");
 scanf("%d",&item);
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=item;
 if(start==NULL)
 {
  newnode->next=NULL;
  start=newnode;
 }
 else
 {
  printf("1.Beginning\t 2.Particular position\t 3.Ending\n");
  printf("Enter your choice:\t");
  scanf("%d",&ch);

switch(ch)
  {
   case 1:  newnode->next=start;
	    start=newnode;
	    break;
   case 2:  printf("Enter the position to place item:\t");
	    scanf("%d",&pos);
	    for(i=1;i<pos;i++)
	    {
	      p=temp;
	      temp=temp->next;
	    }
	    p->next=newnode;
	    newnode->next=temp;
	    break;
   case 3:  while(temp->next!=NULL)
	    temp=temp->next;
	    newnode->next=NULL;
	    temp->next=newnode;
	    break;
   case 4:  exit(0);
  }
 }
}
int traverse()
{
 if(start==NULL)
 printf("LIST IS EMPTY\n");
 else
 {
  for(temp=start;temp->next!=NULL;temp=temp->next)
  printf("%d->",temp->data);
  if(temp->next==NULL)
  printf("%d\n",temp->data);
 }
}

int deletion()
{
 temp=start;
 if(start==NULL)
 printf("LIST IS EMPTY\n");
 else
 {
  printf("1.Beginning\t 2.Particular Position\t 3.Ending\n");
  printf("Enter your choice:\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: item=start->data;
	   printf("deleted item is:%d\n",item);
	   temp=start;
	   start=start->next;
	   free(temp);
	   break;
   case 2: printf("Enter the position to delete item:\t");
	   scanf("%d",&pos);
	   for(i=1;i<pos;i++)
	   {
	    p=temp;
	    temp=temp->next;
	   }
	   item=temp->data;
	   printf("deleted item is:%d\n",item);
	   p->next=temp->next;
	   free(temp);
	   break;
   case 3: while(temp->next!=NULL)
	   {
	    p=temp;
	    temp=temp->next;
	   }
	   item=temp->data;
	   printf("deleted item is:%d\n",item);
	   p->next=NULL;
	   free(temp);
  }
 }
}

