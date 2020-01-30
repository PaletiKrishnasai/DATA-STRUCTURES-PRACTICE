#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int n,i=0,l=0,h,mid;
char j;

char ar[50];

gets(ar);


printf("enter search char");
scanf("%c",&j);
int z=strlen(ar);
h=z-1;
while(l<=h)
{
mid=(l+h)/2;
if(j==ar[mid])
 {
   printf("%d",mid);
   break;
  }
  if(j>ar[mid])
  {
  l=mid+1;
  }
  else
  {
  h=mid-1;
  }
}
if(l>h)
{
printf("Element is absent");
}

return 0;
}

