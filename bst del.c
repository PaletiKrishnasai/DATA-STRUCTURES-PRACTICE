#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* lptr;
	int data;
	struct node* rptr;
};
// create an empty tree
struct node* tptr = NULL;
void insert(int x);
void inorder(struct node* ptr);
void postorder(struct node* ptr);
void preorder(struct node* ptr);
void treesort();
int delete(int x);
void main()
{
	insert(50);
	insert(40);
	insert(60);
	insert(30);
	insert(45);
	insert(70);
	insert(40);
	printf("\n%d\n",delete(45));
	inorder(tptr);
	printf("\nPost order ");
	postorder(tptr);
	printf("\nPre order ");
	preorder(tptr);

//	treesort();
}
void insert(int x)
{
// create node
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->lptr = temp->rptr = NULL;
//	insert the first node
	if(tptr == NULL)
		tptr = temp;
// insert non-first node	
	else
	{
		struct node* ptr = tptr;
		struct node* pptr = NULL;		
		while(ptr != NULL)
		{
			pptr = ptr;
			if(x<ptr->data)
				ptr = ptr->lptr;
			else 
				ptr = ptr->rptr;
		}
		if(x<pptr->data)
			pptr->lptr = temp;
		else 
			pptr->rptr = temp;
	}
}
void inorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->lptr);
		printf("%d ",ptr->data);
		inorder(ptr->rptr);
	}
}
void postorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		printf("%d ",ptr->data);
	}
}
void preorder(struct node* ptr)
{
	if(ptr != NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lptr);
		preorder(ptr->rptr);
	}
}
void treesort()
{
	int n,i;
	printf("Enter the array size :");
	scanf("%d",&n);	
	int a[n];
	for( i = 0;i < n;++i)
		scanf("%d",&a[i]);
	for( i = 0; i<n ; ++i)
		insert(a[i]);
	inorder(tptr);
}

int delete(int x)

{
	struct node *ptr=tptr,*pptr=NULL;

	while(ptr->data!=x)
	{	pptr=ptr;
		if(x<ptr->data)
				
			ptr=ptr->lptr;
		else
			ptr=ptr->rptr;
		
	}
	//case 1
	
	if((ptr->lptr==NULL) &&	(ptr->rptr==NULL))
	{	if(pptr==NULL)
		tptr=NULL;
		else if(x<pptr->data)
		pptr->lptr=NULL;
		else
		pptr->rptr=NULL;
	}

	//case 3
	//find successor of x
	else if((ptr->lptr!=NULL)  &&  (ptr->rptr!=NULL))
	{
		
		struct node *xsucc=ptr->rptr;
		struct node *pxsucc=ptr;	
		while(xsucc->lptr!=NULL)
	{
			pxsucc=xsucc;
			xsucc=xsucc->lptr;
		
	}
		ptr->data=xsucc->data;
		if(xsucc->data<pxsucc->data)
		pxsucc->lptr=xsucc->rptr;
		else
		pxsucc->rptr=xsucc->rptr;
	}	

	//case 2	
	else

	{	
		if(ptr->lptr!=NULL)
		{
			if(x<pptr->data)
				pptr->lptr=ptr->lptr;	
			else
				pptr->rptr=ptr->lptr;
		}
		else

		{				
		if(x<pptr->data)
		pptr->lptr=ptr->rptr;
		else
		pptr->rptr=ptr->rptr;
		}				
	}
return x;
}
