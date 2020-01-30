#include<stdio.h>
#include<string.h>
void bubblesort(char a[],int size)
{
int i=0,j=0,n;
char buff;
n=size;
for(i=0;i<n-1;i++)
 {
 for(j=0;j<n-1-i;j++)
 {
   if(a[j]>a[j+1])
   {
   buff=a[j];
   a[j]=a[j+1];
   a[j+1]=buff;
   }
 }
 }
}

int main()
{
int i,j;
char ar[50];
gets(ar);
int n=strlen(ar);
bubblesort(ar,n);
printf("%s",ar);
}
