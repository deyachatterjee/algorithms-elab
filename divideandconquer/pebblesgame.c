/*
Given 2N pebbles of N different colors, where there exists exactly 2 pebbles of each color, you need to arrange these pebbles in some order on a table. You may consider the table as an infinite 2D plane.
The pebbles need to be placed under some restrictions :
You can place a pebble of color X, at a coordinate (X,Y) such that Y is not equal to X, and there exist 2 pebbles of color Y.
In short consider you place a pebble of color i at co-ordinate (X,Y). Here, it is necessary that (i=X) , (i!=Y) there exist some other pebbles of color equal to Y.
Now, you need to enclose this arrangement within a boundary , made by a ribbon. Considering that each unit of the ribbon costs M, you need to find the minimum cost in order to make a boundary which encloses any possible arrangement of the pebbles. The ribbon is sold only in units (not in further fractions).
Input Format:
First line consists of an integer T denoting the number of test cases. The First line of each test case consists of two space separated integers denoting N and M.
The next line consists of N space separated integers, where the ith integer is A[i], and denotes that we have been given exactly 2 pebbles of color equal to A[i]. It is guaranteed that A[i]!=A[j], if i!=j

Output Format:
Print the minimum cost as asked in the problem in a separate line for each test case.

Constraints:

1<=T<=50
3<=N<=10^5
1<=M<=10^5
1<=A[i]<=10^6 

where 1<=i<=N


TEST CASE 1 
INPUT

1
3 5
1 2 3

OUTPUT

35
TEST CASE 2
INPUT

1
2 8
1 2 6

OUTPUT
24
*/
#include <stdio.h>
#include<math.h>
int Partition(int A[],int p,int r){
    int x=A[r];
    int i,j;
    i=p-1;
    for(j=p;j<r;++j){
        if(A[j]<x){
            i++;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    int temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}
 
void QuickSort(int A[],int p,int r){
    if(p<r){
        int par=Partition(A,p,r);
        QuickSort(A,p,par-1);
        QuickSort(A,par+1,r);
    }
}
 
int main()
{ 
    int T,N,M;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        int A[N];
        int i;
        for(i=0;i<N;++i)
         scanf("%d",&A[i]);
        QuickSort(A,0,N-1);
        long len;
        len=2*(A[N-2]-A[0])+2*(A[N-1]-A[1]);
        double square=sqrt(2*pow((A[1]-A[0]),2))+sqrt(2*pow((A[N-1]-A[N-2]),2));
        square=len+square;
        long x=(long)square;
        if(square>x)
         x=x+1;
        printf("%ld\n",x*M);
    }
  return 0;
}
