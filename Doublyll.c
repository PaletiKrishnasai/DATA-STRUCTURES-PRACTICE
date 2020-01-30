#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* pptr;
	struct node* nptr;
};
struct node* hptr = NULL; // empty doubly linked list is created
void insert(int x, int pos);
int delete(int pos);
int search(int x);
void main()
{
	insert(22,0);
	insert(12,1);
	insert(21,2);
	insert(2,1);
	printf("%d\n",search(12));
	printf("%d\n",search(122));
	
}
void insert(int x, int pos)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	int i=0;
	struct node* thptr = hptr;
	if(hptr ==NULL)
	{
		temp->nptr = NULL;
		temp->pptr = NULL;
		hptr = temp;
	}
	else if (pos == 0)
	{
		temp->nptr = hptr;
		hptr->pptr = temp;	
		hptr = temp;
		temp->pptr=NULL;	
	}
	else
	{
		while(i<pos-1)
		{	
			thptr = thptr->nptr;
			++i;
		}
		temp->nptr = thptr->nptr;
		temp->pptr = thptr;
		if(thptr->nptr != NULL)
			(thptr->nptr)->pptr = temp;				
		thptr->nptr = temp;
	}
}
int search(int x)
{
	int flag=0;
	struct node* thptr = hptr;
	while(thptr != NULL)
	{
		if(x == thptr->data)	
		{
			flag=1;	
			break;
		}
		else
			thptr = thptr->nptr;
	}
	return flag;
}
