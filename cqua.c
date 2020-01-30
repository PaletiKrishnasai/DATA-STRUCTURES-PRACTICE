#include<stdio.h>
  
  int front=0,rear=0;
  void enqueue(int A[],int x,int size)
  {
   if((rear+1)%(size+1)==front)
   {
   printf("Array is full");
   }
   else
   {
   
   rear=(rear+1)%(size+1);
    A[rear]=x;
   
   }
  }
  
  void dequeue(int A[],int size)
  {
  if(front==rear)
  {
  printf("Array is empty");
  }


  else
  {
  front=(front+1)%(size+1);
  }
  }
  
  
int main()
 {
 
 printf("Enter the size of the array");
 int size;
 scanf("%d",&size);
 int j=size+1;
 int A[size+1];
 enqueue(A,7,size);
 enqueue(A,7,size);
 enqueue(A,7,size);
  enqueue(A,7,size);
   enqueue(A,7,size);
   
 dequeue(A,size);
  dequeue(A,size);
   dequeue(A,size);
    dequeue(A,size);
     enqueue(A,7,size);
 while(front!=rear)
 {
 front=(front+1)%(size+1);
 printf("%d",A[front]);
 }
 }
 
