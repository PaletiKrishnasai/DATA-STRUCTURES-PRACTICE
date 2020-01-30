#include<stdio.h>
#include<stdlib.h>
#define hsize 10
struct node
{
	int data;
	struct node* next;
};
struct node *head[hsize]={NULL},*c;
void insert();
void delete();
void search();
void display();
void main()
{
int opt,key,i;
while(1)
{
printf("\npress \t 1. insert \t 2. display \t 3. search \t 4. delete \n");
scanf("%d",&opt);
switch(opt)
{
case 1 : insert();break;
case 2 : display();break;
case 3 : search();break;
case 4 : delete();break;
default : exit(0);

}

}


}



void insert()
{
 int i,key;
 printf("\nenter the value to insert\n");
 scanf("%d",&key);
 i=key%hsize;
 struct node *new=(struct node*)malloc(sizeof(struct node));
 new->data=key;
 new->next=NULL;
 if(head[i]==NULL)
 head[i]=new;
 else
 {
  c=head[i];
  while(c->next!=NULL)
  {
   c=c->next;
  }
  c->next=new;

 }
}

void search()
{
int key,in;
printf("\nenter the element you want to search\n");
scanf("%d",&key);
in=key%hsize;
if(head[in]==NULL)
printf("\nNOT FOUND\n");
else
{
for(c=head[in];c!=NULL;c=c->next)
 {
 	if(c->data==key)
 	printf("\nFOUND\n");
 	break;
 	}
 	//else
 	}
	if(c==NULL)
	  printf("\nNOT FOUND\n");
	  }
	  
	  
void display()
{
int i;
for(i=0;i<hsize;i++)
{
printf("\nentries at index %d\n ",i);
if(head[i]==NULL)
{
printf("NULL");

}
else
{
for(c=head[i];c!=NULL;c=c->next)
printf("%d->",(c->data));
}
}
}
	  
void delete()
{

int key,ins;
printf("\nenter element u want to delete\n");
scanf("%d",&key);
ins=key%hsize;
c=NULL;
struct node* ptr=head[ins];
if(ptr->data==key)
head[ins]=ptr->next;
else
{
while(ptr!=NULL)
{
if(ptr->data==key)
	{
		c->next=ptr->next;
	}
	c=ptr;
	ptr=ptr->next;
			
}
}
}
