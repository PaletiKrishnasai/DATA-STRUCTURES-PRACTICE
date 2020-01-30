#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
};
struct node*  insert (struct node* p,int temp)
 {
  struct node *t;
   t=(struct node *)malloc(sizeof(struct node));
   t->next=NULL;
   t->data=temp;
   p->next=t;
   p=t;
   return p;
 }
  int main()
  {
    int n,temp,x,i,result;
    printf("Enter the degree of the polynomial\n");
     scanf("%d",&n);
     printf("Enter the coefficients\n");
     scanf("%d",&temp);
     struct node * head=(struct node *)malloc(sizeof(struct node));
     head->data=temp;
     head->next=NULL;

     struct node* p=head;
     for(i=0;i<n;i++)
     {
     scanf("%d",&temp);
     p=insert(p,temp);
     }
      struct node *q;
      q=head;
     printf("Enter the value of X");
     scanf("%d",&x);
     while(q!=NULL)
     {
     result=pow(x,n)*(q->data)+result;
     q=q->next;
     n--;
    
     
     }
     printf("%d",result);
     
  }
