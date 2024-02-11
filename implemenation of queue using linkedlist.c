#include<stdio.h>
#include<malloc.h>
int  enqueue();
int display();
int dequeue();
int ch,i,n,j,item,pos;

struct node
{
 int data;
 struct node *next;
}*front=NULL,*rear=NULL,*newnode,*temp,*p;

int main()
{

 printf(" **** MENU **** ");
 while(1)
 {
  printf("\n1.ENQUEUE\t 2.DEQUEUE\t 3.DISPLAY\t 4.EXIT\n");
  printf("Enter your choice:\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: enqueue(); break;
   case 2: dequeue(); break;
   case 3: display(); break;
   case 4: exit(0);   break;
   default:printf("Wrong choice");
  }
 }
}

int enqueue()
{
 printf("Enter the element to be inserted:");
 scanf("%d",&item);
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=item;
 if(rear==NULL)
 {
  newnode->next=NULL;
  front=rear=newnode;
 }
 else
 {
  newnode->next=NULL;
  rear->next=newnode;
  rear=newnode;
 }
}
int display()
{
 if((front==NULL)&&(rear==NULL))
 printf("QUEUE IS EMPTY (UNDERFLOW)\n");
 else
 {
  for(temp=front;temp->next!=NULL;temp=temp->next)
  printf("%d->",temp->data);
  printf("%d\n",temp->data);
 }
}

int dequeue()
{
 temp=front;
 if((front==NULL)&&(rear==NULL))
 printf("QUEUE IS EMPTY (UNDERFLOW)\n");
 else
 {
   item=front->data;
   printf("deleted element is:%d\n",item);
   if(front==rear)
   front=rear=NULL;
   else
   front=front->next;
   free(temp);
 }
}

