#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
struct node *hptr=NULL;
void insert(int x,int pos);
int search(int x);
int delete(int pos);
void print();
int main()
{
	insert(2,0);	
	insert(20,1);
	insert(10,1);
	insert(12,3);
	insert(23,1);
	insert(25,0); 
	insert(5,4);
	insert(9,4);
	insert(15,4);	
	print();
	
	printf("\n%d\n",search(-40));
	printf("\n%d\n",delete(0));	
	return 2110;
}
void insert(int x, int pos)
{
	struct node *temp =(struct node *) malloc(sizeof(struct node));
	int i=0;
	struct node *thptr=hptr;
	temp->data= x;
	if(pos==0)
	{	
		temp->nptr= hptr;
		hptr=temp;	
	}	
	else
	{
		while(i<pos-1)	
		{		
			thptr=thptr->nptr;
			i++;
		}
		temp->nptr=thptr->nptr;
		thptr->nptr=temp;
	}
}
void print()
{
	struct node *thptr = hptr;
		
	while(thptr != NULL)
	{
		printf("%d\t",thptr->data);
		thptr = thptr -> nptr;
	}
}


int search(int x)

{
	struct node *thptr = hptr;
	int flag=0;	
	while(thptr != NULL)
	{
		//printf("%d\t",thptr->data);
	   if(x==thptr->data)		
	  {  
		  flag=1;	
	     break;
	  }		
	thptr = thptr -> nptr;
	} 
	return flag;
}


int delete(int pos)
{
	int x;
	struct node *thptr=hptr;
	if(pos==0)
	{	x=hptr->data;
		hptr=hptr->nptr;	
	}
	else	
	{
		int i=0;	
		while(i<pos-1)
			{
				thptr=thptr->nptr;
				i+=1;
			}
		x=(thptr->nptr)->data;
		thptr->nptr=(thptr->nptr)->nptr;
	
	}
return x;
}


int isempty()
{
	if(hptr==NULL)
	return 1;
	else
	return 0;
}

int isfull()
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	return 1;
	else
	return 0;
}
