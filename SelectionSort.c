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

