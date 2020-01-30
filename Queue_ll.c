#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* nptr;
};
struct node* front = NULL;
struct node* rear = NULL;
void enqueue(int x);
int dequeue();
void main()
{
	enqueue(21);
	enqueue(214);
	enqueue(211);
	enqueue(221);

	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	
}
void enqueue(int x)
{
	struct node* temp= (struct node* )malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("No space fro insert");
		exit(0);
	}	
	temp->data=x;
	temp->nptr=NULL;
	if(front == NULL)
		front = temp;
	    rear=temp;
	else
		rear->nptr = temp;	
	rear= temp;
}
int dequeue()
{
	if(front==NULL)
	{
		printf("list is empty\n");
		exit(0) ;	
	}
	int x = front->data;
	if(rear == front)
		rear = front = NULL;
	else
		front = front->nptr;
	return x;
}
