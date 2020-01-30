 #include<stdio.h>
#include<stdlib.h>
 struct node
 {
 struct node* lc;
 int data;
 struct node* rc;
 };
 struct node * rptr= NULL;
 
 int count1=0;
 void insert(int x)
 {
   struct node * temp = (struct node *)malloc(sizeof(struct node));
   temp->data=x;
   temp->lc=temp->rc=NULL;
   if(rptr==NULL)
   {
   rptr=temp;
   }
   else
   {
   struct node* ptr=rptr;
   struct node* pptr =NULL;
   while(ptr!=NULL)
   {
     pptr=ptr;
     if(x<ptr->data)
     {
     ptr=ptr->lc;
     }
     else
     {
      ptr=ptr->rc;
     }
   }
   if(x<pptr->data)
      {
      pptr->lc=temp;
      }
   else
   {
   pptr->rc=temp;
   }   
   
   }
 }
 void count(struct node * ptr)
 {
 if(ptr!=NULL)
 {
 
 count(ptr->lc);
  count1++;
 count(ptr->rc);
 }
 }
 int height(struct node * ptr)
 {
   
  if(ptr==NULL)
  {
  return 0;
  }
  else
  {
  int ld = height(ptr->lc);
  int rd = height(ptr->rc);
  if(ld>rd)
   return ld+1;
   else
   {
   return rd+1;
  }
 
 }
 }
 
 int main()
 {
 
 
 insert(10);
 insert(6);
 insert(9);
 insert(8);
  insert(12);
 count(rptr);
 
 printf("%d\n",count1);
 int x=height(rptr);
 printf("%d",x);
 
 }

