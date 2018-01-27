/*
Divide the problem into a number of subproblems
There must be base case (to stop recursion).
Conquer (solve) each subproblem recursively
Combine (merge) solutions to subproblems into a
solution to the original problem 

Nontrivial strategy:
1. Split the array in half
2. Find the MAX and MIN of both halves
3. Compare the 2 MAXes and compare the 2 MINs to get
overall MAX and MIN.

TEST CASE 1 
INPUT
4
2 4 1 10

OUTPUT
Minimum element is 1
Maximum element is 10

TEST CASE 2
INPUT
3
12 10 2
OUTPUT

Minimum element is 2
Maximum element is 12
*/

/* structure is used to return two values from minMax() */
#include<stdio.h>
struct pair 
{
  int min;
  int max;
};  
 
struct pair getMinMax(int arr[], int n)
{
  struct pair minmax;     
  int i;
   
  /*If one element then return it as min and max both*/
  if (n == 1)
  {
     minmax.max = arr[0];
     minmax.min = arr[0];     
     return minmax;
  }    
 
  /* If more than one elements, then initialize min 
      and max*/
  if (arr[0] > arr[1])  
  {
      minmax.max = arr[0];
      minmax.min = arr[1];
  }  
  else
  {
      minmax.max = arr[1];
      minmax.min = arr[0];
  }    
 
  for (i = 2; i<n; i++)
  {
    if (arr[i] >  minmax.max)      
      minmax.max = arr[i];
   
    else if (arr[i] <  minmax.min)      
      minmax.min = arr[i];
  }
   
  return minmax;
}
 
int main()
{
  int arr[100];
 int i,n;
  scanf("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d",&arr[i]);
  struct pair minmax = getMinMax (arr, n);
  printf("Minimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
return 0;}