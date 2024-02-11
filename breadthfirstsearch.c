#include<stdio.h>

int bfs(int);
int n,a[10][10];
int visited[10];
int main()
{
 int i,j,v;

 printf("Enter the no. of nodes in the Graph:\t");
 scanf("%d",&n);
 printf("Enter the adjacency matrix: \n");
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 scanf("%d",&a[i][j]);
 printf("Enter the starting node for Breadth First search:\t");
 scanf("%d",&v);
 for(i=0;i<n;i++)
 visited[i]=0;
 bfs(v);
 return 0;
}
int bfs(int v)
{
 int i,queue[10],front=-1,rear=-1;
 queue[++rear]=v;
 visited[v]=1;
 while(rear!=front)
 {
  v=queue[++front];
  printf("->%c",v+65);
    for(i=0;i<n;i++)
     if(a[v][i]==1 && visited[i]==0)
     {	queue[++rear]=i;
	visited[i]=1;
     }
 }
}
