/*
Once upon a time, the Earth was a flat rectangular landmass. And there was no life. It was then that the sky lit up with meteorites falling from out of space. Wherever they fell on the planet, a river was born, which flowed in all 4 directions (North, East, West, South), till the waters reached the edge of the Earth and simply fell off into space.
Now, these rivers criss-crossed and divided the one huge landmass (Pangaea) into many smaller landmasses. Now the lifeless (there was no life, remember?), want to know the number of landmasses on the planet after all the meteorites have fallen. They also want to know the area of the smallest and largest landmass. Can you help the lifeless in this question?

First line contains T which is the number of test cases.
First line of every test case contains 3 integers N, M, Q where N and M are coordinates of the bottom right corner of the planet and Q is the number of meteorites.
The next Q lines contains the coordinates X, Y where each of the meteorites fell.
Output:

For each test case, output a line containing 3 integers indicating the number of regions, the minimum area and the maximum area.

Constraints:

1<= T <= 10
2 <= N, M <= 10^5
0 <= Q <= 10^5
1 <= X <= N
1 <= Y <= M
0 <= sum of Q over all test cases <= 10^5

TEST CASE 1 
INPUT

1
5 5 2
2 3
4 4
OUTPUT
9 1 4

TEST CASE 2
INPUT

1
5 4 2
2 2
5 5

OUTPUT
6 1 6
*/


#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MIN 10001
void quicksort(int b[], int low, int high);
 int partition( int b[], int low, int high);
int main()
{
    int t,n,m,i,q,countx,county,region,minx,miny,maxx,maxy;
    scanf("%d",&t);
    while(t--)
    {
        countx=0;
        county=0;
        scanf("%d %d %d",&n,&m,&q);
        if(q==0)
         printf("%d %d %d\n",1,(n-1)*(m-1),(n-1)*(m-1));
        else
        {
      int x[q+2],y[q+2];
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        x[q]=1;
        y[q]=1;
        x[q+1]=n;
        y[q+1]=m;
        quicksort(x,0,q+1);
        quicksort(y,0,q+1);
        for(i=0;i<q+2;i++)
        {
            countx++;
            while(x[i]==x[i+1]&&i<q+1)
            i++;
        }
        for(i=0;i<q+2;i++)
        {
            county++;
            while(y[i]==y[i+1]&&i<q+1)
            i++;
        }
     
        region=(countx-1)*(county-1);
            minx=MIN;
            miny=MIN;
        for(i=0;i<q+1;i++)
        {
            if((x[i+1]-x[i])!=0&&((x[i+1]-x[i])<minx))
            minx=(x[i+1]-x[i]);
            if((y[i+1]-y[i])!=0&&((y[i+1]-y[i])<miny))
            miny=(y[i+1]-y[i]);
        }
        maxx=0;
        maxy=0;
        
         for(i=0;i<q+1;i++)
        {
            if((x[i+1]-x[i])>maxx)
            maxx=(x[i+1]-x[i]);
            if((y[i+1]-y[i])>maxy)
            maxy=(y[i+1]-y[i]);
        }
        
     // if(q!=0)
        printf("%d %d %d\n",region,(minx*miny),(maxx*maxy));
        }
    
    }
    return 0;
}
void quicksort( int b[],int low, int high)
{
    if(low<high)
    {
        int j=partition(b,low,high);
        quicksort(b,low,j);
        quicksort(b,j+1,high);
    }
}
 int partition( int b[], int low, int high)
{
     int temp,up,down,t,x;
    t=low+rand()%(high-low+1);
    temp=b[t];
    b[t]=b[low];
    b[low]=temp;
    x=b[low];
    down=low-1;
    up=high+1;
    while(1)
    {
        do
        {
            down++;
        }while(b[down]<x);
        do
        {
            up--;
        }while(b[up]>x);
        if(down<up)
        {
            temp=b[down];
            b[down]=b[up];
            b[up]=temp;
        }
        else
        {
            temp=b[low];
            b[low]=b[up];
            b[up]=temp;
            return up;
            
        }
    }
}