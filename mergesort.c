#include <stdio.h>
#include <stdlib.h>
int merge(int a[],int,int,int);
int mergesort(int a[],int,int);
int main()
{
 int a[20],i,n;

 printf("Enter size of List:");
 scanf("%d",&n);
 printf("\nEnter %d elements: \n",n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 mergesort(a,0,n-1);
 printf("Sorted List:");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
 return 0;
}
int mergesort(int a[],int beg,int end)
{
 int mid;
 if(beg<end)
 {
  mid=(beg+end)/2;
  mergesort(a, beg, mid);
  mergesort(a, mid + 1, end);
  merge(a,beg,mid,end);
 }
}
int merge(int a[],int beg,int mid,int end)
{
 int i=beg,j = mid+1,index=beg,temp[20],k;
 while((i<=mid)&&(j<=end))
	 {
  if(a[i]<a[j])
  {
   temp[index]=a[i];
   i++;
  }
  else
  {
   temp[index]=a[j];
   j++;
  }
  index++;
 	}
 if(i>mid)
 {
  while(j<=end)
  {
   temp[index]=a[j];
   j++;
   index++;
  }
 }
 else
 {
  while(i<=mid)
  {
   temp[index]=a[i];
   i++;
   index++;
  }
 }
 for(k=beg;k<index;k++)
 a[k]=temp[k];
}

