# include <stdio.h>

# include <stdlib.h>
struct node
{
   int data;
   struct node *lchild, *rchild;
}*root=NULL,*newnode;
int insert(struct node*,struct node*);
int inorder(struct node*);
int preorder(struct node*);
int postorder(struct node*);
void main()
{
   int choice;
   char ans;

   while(1)
   {
      printf("\n1.Create");
      printf("\n2.Recursive Traversals");
      printf("\n3.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
      switch (choice)
      {
	case 1:    do
		   {
		    newnode = (struct node*)malloc(sizeof(struct node));
		    newnode->lchild =newnode->rchild=NULL;
		    printf("\nEnter The Element ");
		    scanf("%d",&newnode->data);
		    if (root == NULL)
		    root = newnode;
		    else
		    insert(root,newnode);
		    printf("\nWant To enter More Elements?(y/n)");
		    ans = getche();
		   } while (ans == 'y'|| ans == 'Y');
		   break;
	case 2:    if (root == NULL)
		   printf("Tree Not Yet Created");
		   else
		   {
		     printf("\nInorder: ");
		     inorder(root);
		     printf("\nPreorder: ");
		     preorder(root);
		     printf("\nPostorder: ");
		     postorder(root);
		   }
		   break;
	case 3:    exit(0);
      }
   }
}

int insert(struct node *root,struct node *newnode)
{
   if(newnode->data <= root->data)
   {
      if (root->lchild == NULL)
	 root->lchild=newnode;
      else
	 insert(root->lchild, newnode);
   }
  else if(newnode->data > root->data)
  {
      if (root->rchild == NULL)
	 root->rchild = newnode;
      else
	 insert(root->rchild, newnode);
   }
}


int inorder(struct node *temp)
{
   if (temp != NULL)
   {
      inorder(temp->lchild);
      printf("->%d", temp->data);
      inorder(temp->rchild);
   }
}


int preorder(struct node *temp)
{
   if (temp != NULL)
    {
      printf("->%d", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}


int postorder(struct node *temp)
{
   if (temp != NULL)
   {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("->%d", temp->data);
   }
}
