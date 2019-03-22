#include<stdio.h>
int a[100];
int main()
{
  int n, i= 0 , j , swapped;
  printf("Enter the number of elements\n");
  scanf("%d", &n);

  for(i = 0 ; i < n ; i++)
    {
      printf("enter element no %d\n",i+1);
      scanf("%d", &a[i]);
    }

  for(j = 0 ; j < n ; j++)
    {
      int swapped = 0;
      i = 0 ;
      while( i < n-1)
	{
	  if(a[i] > a[i+1])
	    {
	      int temp = a[i];
	      a[i] = a[i+j];
	      a[i+j] = temp;
	      swapped = 1;
	    }
	  i++;
	}
      if(!swapped)
	break;
    }

  for(i = 0 ; i < n ; i++)
    {
      printf(" %d, \n",a[i]);
    }
  return 0;
}
