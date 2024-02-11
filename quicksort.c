#include<stdio.h>

int quicksort(int[],int,int);
int main()
{
 int x[20],i,n;
 printf("Enter size of list:");
 scanf("%d",&n);
 printf("Enter %d elements:",n);
 for(i=0;i<n;i++)
 scanf("%d",&x[i]);
 quicksort(x,0,n-1);
 printf("Sorted List:");
 for(i=0;i<n;i++)
 printf("%d\t",x[i]);
 return 0;
}
int quicksort(int x[20],int first,int last)
{
 int pivot,i,j,t;
 if(first<last)
 {
  pivot=first;
  i=first;
  j=last;
  while(i<j)
  {
   while(x[i]<=x[pivot] && i<last)
   i++;
   while(x[j]>x[pivot])
   j--;
   if(i<j)
   {
    t=x[i];
    x[i]=x[j];
    x[j]=t;
   }
  }
  t=x[pivot];
  x[pivot]=x[j];
  x[j]=t;
  quicksort(x,first,j-1);
  quicksort(x,j+1,last);
 }
}


