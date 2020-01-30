#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
};


void insert(struct node* head[])
{
int v1,v2;
struct node *p;
struct node *temp;
printf("Enter the vertices v1 and v2\n");
scanf("%d%d",&v1,&v2);
temp=(struct node*)malloc(sizeof(struct node));
temp->data=v2;
temp->next=NULL;
p=head[v1];
if(p==NULL)
{
head[v1]=temp;
}
else
{
while(p->next!=NULL)
  p=p->next;
  p->next=temp;
}

temp=(struct node*)malloc(sizeof(struct node));
temp->data=v1;
temp->next=NULL;
p=head[v2];
if(p==NULL)
{
head[v2]=temp;
}
else
{
while(p->next!=NULL)
  p=p->next;
  
  p->next=temp;
}
}

int top=-1;
void push(struct node* head[],int visited[],int x,int stack[])
{
  visited[x]=1;
top++;
stack[top]=x;
}

int pop(int stack[])

{
 int y=stack[top];
 top--;
 return y;
}
int  DFS(struct node* head[],int j,int visited[])
  {

   struct node*adj;
   visited[j]=1;
  
   adj=head[j];
   while(adj!=NULL)
   {
     if(visited[adj->data]==0)
     {
       DFS(head,adj->data,visited);
     }
   
     adj=adj->next;
   }
  }

int flag1=0;

  int  DFSR(struct node* head[],int j,int visited[],int parent)
  {

   struct node*adj;
   visited[j]=1;
  
   adj=head[j];
   while(adj!=NULL)
   {
     if(visited[adj->data]==0 && adj->data!=parent && flag1!=1)
     {
      parent=j;
   DFSR(head,adj->data,visited,parent);
     }
     else if(visited[adj->data]==1 && adj->data!=parent && flag1!=1)
     {
        flag1=1;
        break;
     }
     adj=adj->next;
   }
  }







int main()
{
int n,i;
printf("Enter the number of vertices or nodes\n");
scanf("%d",&n);
struct node* head[n];
int visited[n];
int stack[n];
for(i=0;i<n;i++)
{
head[i]=NULL;
visited[i]=0;
}

char ch='y';
while(ch=='y')
{
 printf("Enter y if you want to add a link between v1 and v2 else enter n\n");
 scanf(" %c",&ch);
 if(ch=='y')
 {
 insert(head);
 }
}
ch='y';
while(ch=='y')
{
 printf("Enter y if you want to add new node else enter n\n");
 scanf(" %c",&ch);
 if(ch=='y')
 {
   n++;
   struct node* temp1[n];
   for(i=0;i<n-1;i++)
   {
   temp1[i]=head[i];
   }
   temp1[n-1]=NULL;
   struct node*head[n];
   for(i=0;i<n;i++)
   {
   head[i]=temp1[i];
   }
 }
}
  
DFS(head,0,visited);
  

int flag=0;

  for(i=0;i<n;i++)
  {
  if(visited[i]==0)
  {
    flag=1;
    printf("The graph is not connected\n");
    break;
  }
  }
  if(flag==0)
  {
    printf("The graph is connected\n");
  }

for(i=0;i<n;i++)
{
  visited[i]=0;
}

DFSR(head,0,visited,0);

if(flag1==0)
{
  printf("The graph is not cyclic\n");
}
else
{
  printf("The graph is cyclic\n");
}

}
