#include<stdio.h>

void SelectionSort(int a[], int size);

int main()
{
   int b[100];
   int n;
   printf("Welcome to bubble sort; give array size \n");
   scanf("%d", &n); 
   printf("\n  Enter %d integers \n", n);
   
   for(int i=0; i<n; ++i)
      scanf("%d", &b[i]); 

    SelectionSort(b, n);

   printf("The Array:\n");
    for(int i=0; i<n; ++i)
      printf("%d ", b[i]); 


  return(0);
}


void SelectionSort(int a[], int size)
{
   int max, imax, temp;
   
  for(int i=0; i<size-1; ++i)
  {
     max=a[0];
     imax=0;
    for(int j=1; j<size-i; j++)
      if(a[j] > max)
      {
          max=a[j];
          imax=j;
      }

       temp=a[imax];
       a[imax]=a[size-i-1];
       a[size-i-1]=temp;    
     //swap a[imax] with a[size-i-1];
 
  }
}




