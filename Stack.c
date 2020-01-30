#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr; 
};
struct node *tptr=NULL;// empty stack is created
void push(int x);
int pop();
int main()
{
	push(7);
	push(2);
	push(1);
	push(4);
	push(5);	
	push(3);
	printf("%d ",pop());
	printf("%d ",pop());
	printf("%d ",pop());
	printf("%d ",pop());
	printf("%d ",pop());
	return  0;
}
void push(int x)
{
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->nptr=tptr;
	tptr=temp;
}
int pop()
{
	int x=tptr->data;
	tptr=tptr->nptr;
	return x;
}

