#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lc;
int data;
struct node *rc;
};
struct node* rptr=NULL;


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
   	struct node* pptr=NULL;
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
   	
   void max1_max2()
   {
   struct node* ptr=rptr;
   struct node* pptr=NULL;
   struct node* tptr=NULL;
   
   while(ptr!=NULL)
   {
   tptr=pptr;
   pptr=ptr;
   ptr=ptr->rc;
   }
   if(pptr->lc==NULL)
   printf("1st max=%d\n 2nd max= %d\n", pptr->data, tptr->data);
   
   else
   {
   	printf("max=%d\n",pptr->data);
   	pptr=pptr->lc;
   	while(pptr!=NULL)
   	{
   		tptr=pptr;
   		if(pptr->rc!=NULL)
   		{
   		pptr=pptr->rc;
   		}
   		else
   		{
   		break;
   		}
   		
   	}
   	printf("2nd max=%d\n",tptr->data);
   }
   
   
   }
   void min1_min2()
   {
   struct node* ptr=rptr;
   struct node* pptr=NULL;
   struct node* tptr=NULL;
   
   while(ptr!=NULL)
   {
   tptr=pptr;
   pptr=ptr;
   ptr=ptr->lc;
   }
   if(pptr->rc==NULL)
   printf("1st min=%d\n 2nd min=%d\n", pptr->data, tptr->data);
   
   else
   {
   	printf("min=%d\n",pptr->data);
   	pptr=pptr->rc;
   	while(pptr!=NULL)
   	{
   		tptr=pptr;
   		if(pptr->lc!=NULL)
   		{
   		pptr=pptr->lc;
   		}
   		else
   		{
   		break;
   		}
   		
   	}
   	printf("2nd min=%d\n",tptr->data);
   }
   
   
   }
   
   
   int main()
   {
   insert(1);
   insert(5);
   insert(3);
   insert(8);
   insert(7);
   
   
   max1_max2();
   
   min1_min2();
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
 
 













































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
