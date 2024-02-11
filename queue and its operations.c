#include<stdio.h>

int enqueue();
int dequeue();
int display();
int queue[20],front=-1,rear=-1,n;
int main()
{
int choice,x;
printf("Enter size of Queue:\t");
scanf("%d",&n);
printf("\n*** MENU ***\n1.ENQUEUE\t 2.DEQUEUE\t 3.DISPLAY\t  4.EXIT");
while(1)
{
printf("\nEnter your choice from menu:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();
       break;
case 2:dequeue();
       break;
case 3:display();
       break;
case 4:exit(0);
default:printf("Wrong Choice\n");
}
}
}
int enqueue()
{
int x;
if(rear==n-1)
printf("Queue is full (Overflow).Above Element not inserted\n");
else
{
printf("Enter element to be inserted:\t");
scanf("%d",&x);
if(rear==-1&&front==-1)
rear=front=0;
else
rear++;
queue[rear]=x;
printf("Enqueue operation succesful");
}
}
int dequeue()
{
int x;
if(front==-1|| front>rear)
{
printf("Queue is empty (Underflow)\n");
}
else
{
x=queue[front];
front++;
printf("Deleted element from Queue is %d\n",x);
}
}
int display()
{
int i;
if(front==-1||front>rear)
{
printf("\nQueue is Empty\n");
}
else
{
printf("Queue contains\n");
for(i=front;i<=rear;i++)
printf("%d\t",queue[i]);
}
}






































