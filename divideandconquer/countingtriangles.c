/*
You are given n triangles.
You are required to find how many triangles are unique out of given triangles. For each triangle you are given three integers a,b,c , the sides of a triangle.
A triangle is said to be unique if there is no other triangle with same set of sides.
Note : It is always possible to form triangle with given sides.

INPUT:
First line contains n, the number of triangles. Each of next n lines contain three integers a,b,c (sides of a triangle).
Output:
print single integer, the number of unique triangles.

Constraints:

1 <= n <= 10^5
1 <= a,b,c <= 10^15

TEST CASE 1 
INPUT

3
1 2 3
2 3 4
2 4 3

OUTPUT
1

TEST CASE 2
INPUT

5
7 6 5
5 7 6
8 2 9
2 3 4
2 4 3

OUTPUT

1
*/

#include<stdio.h>

void swap(long long int *a, long long int *b)
{
 	 long long int t;
 	 t=*a;
 	 *a=*b;
 	 *b=t;
}
 
void qsort(long long int items[][4], long long int left, long long int right)
{
     register long long int i,j,k;
     long long int x, y;
     
     i = left; j = right;
     x = items[(left+right)/2][3];
     do 
     {
        while((items[i][3] < x) && (i < right)) 
           i++;
        while((x < items[j][3]) && (j > left))
           j--;
        if(i <= j) 
        {
             y = items[i][0];items[i][0] = items[j][0];items[j][0] = y;
			 y = items[i][1];items[i][1] = items[j][1];items[j][1] = y;
			 y = items[i][2];items[i][2] = items[j][2];items[j][2] = y;
			 y = items[i][3];items[i][3] = items[j][3];items[j][3] = y;
             i++;
             j--;
        }
     } while(i <= j);
 
     if(left < j) 
             qsort(items, left, j);
     if(i < right) 
             qsort(items, i, right);
}
 
int main()
{
    long long int i,k,j,n,z,g,count=0;
    long long int p,q,r;
    long long int arr[100000][4]={0};
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
            scanf("%lld %lld %lld",&arr[i][0],&arr[i][1],&arr[i][2]);
            arr[i][3]=arr[i][0]+arr[i][1]+arr[i][2];
            if (arr[i][0] > arr[i][1]) swap(&arr[i][0],&arr[i][1]);
			if (arr[i][1] > arr[i][2]) swap(&arr[i][1],&arr[i][2]);
			if (arr[i][0] > arr[i][1]) swap(&arr[i][0],&arr[i][1]);
    }
    qsort(arr,0,n-1);
    i=0;
    while(1)
    {
	 		p=arr[i][0];
	 		q=arr[i][1];
	 		r=arr[i][2];
	 		k=arr[i][3];
	 		j=i;
	 		z=0;
	 		if(p==0)
	   		{
			 		++i;
			 		if(i==n)
			 		    break;
   			        else
			 			continue;
	 		}
			while(arr[++i][3]==k && i<n)
			{
			 					 if(arr[i][0]!=0 && arr[i][0]==p && arr[i][1]==q && arr[i][2]==r)
			 					 {
	                                arr[i][0]=0;
			 					    z++;
							     }
		 	}
		 	if(z!=i-1-j && z>=1)
		 	{
		            i=j+1;
		            continue;
			}
			else if(z==0)
			{
			        count++;
			        if(i!=j+1)
			        {
			        		  i=j+1;
			        		  continue;  
	                }	  
			}
            if(i==n)
            		break;
	}
    printf("%lld",count);
    return 0;
}