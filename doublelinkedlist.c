#include<stdio.h>
#include<malloc.h>
int deletion();
int traverse();
int insert();
int ch,i,n,j,item,pos;

struct node
{
 int data;
 struct node *prev;
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
  newnode->prev=NULL;
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
   case 1:  newnode->prev=NULL;
	    newnode->next=start;
	    start->prev=newnode;
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
	    newnode->prev=p;
	    newnode->next=temp;
	    temp->prev=newnode;
	    break;
   case 3:  while(temp->next!=NULL)
	    temp=temp->next;
	    newnode->next=NULL;
	    temp->next=newnode;
	    newnode->prev=temp;
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
  printf("1.Forward direction\t 2.Backward direction\n");
  printf("Enter your choice:\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:   for(temp=start;temp->next!=NULL;temp=temp->next)
	    printf("%d->",temp->data);
	    if(temp->next==NULL)
	    printf("%d\n",temp->data);
	    break;
   case 2:   while(temp->next!=NULL)
	    temp=temp->next;
	    for(;temp->prev!=NULL;temp=temp->prev)
	    printf("%d->",temp->data);
	    printf("%d",start->data);
	    break;
   default: printf("\nWrong Choice\n");
  }
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
	   start->prev=NULL;
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
	   temp->next->prev=p;
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
