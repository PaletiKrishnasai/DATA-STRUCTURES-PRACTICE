#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* lc;
    struct node* rc;
};
int top=-1;
void push(struct node *t,struct node*stack[])
{
 top++;
 stack[top]=t;
}
struct node* pop(struct node*stack[])
{
struct node*p=stack[top];
top--;
return p;
}
void inorder(struct node* pt)
{
    if(pt!=NULL)
    {
        inorder(pt->lc);
        printf("%d ",pt->data);
        inorder(pt->rc);
    }
}
int main()
{
    int i,n,count=0;
  scanf("%d",&n);
   int arr[n];
   struct node* stack[n];
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  
  struct node* rptr=(struct node*)malloc(sizeof(struct node));
  rptr->data=arr[n-1];
  rptr->lc=rptr->rc=NULL;
  struct node* p=rptr;
  
 i=n-2;
  while(i>=0)
  {

    if(arr[i]>=p->data)
    {
      struct node*temp=(struct node*)malloc(sizeof(struct node));
      temp->lc=temp->rc=NULL;
      temp->data=arr[i];
      p->rc=temp;
      push(p,stack);
      p=temp;
      i--;
    }
      
      
    else if((arr[i]<p->data && arr[i]>=stack[top]->data )|| top==-1)
    {
         struct node*temp=(struct node*)malloc(sizeof(struct node));
         temp->lc=temp->rc=NULL;
         temp->data=arr[i];
         p->lc=temp;
         p=temp;
         i--;

    }

    else
    {
        p=pop(stack);
    }
  }
  inorder(rptr);

}
