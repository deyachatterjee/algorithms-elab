/*
Shizuka, the daughter of Code King, is the most beautiful girl of Candyland. Every other Prince wants to marry her.The Code King invites all the other Prince in the town for a RACE and the winner of the race gets a chance to marry her.
Obviously , the RACE will be full of hurdles. Given the number of Princes N, each with ID (0 to N-1) and their maximum jumping strengths (A[i] : i = 0,1,...,N-1) and the number of hurdles K, each with its height ( D[i] : i = 0,1,...K-1) in the RACE, find the winner !!
The Prince who crosses maximum number of levels wins the RACE. In case of ties, the Prince with minimum ID wins the RACE.
for further clarification refer the testcases.
INPUT:
First line of input contains a single integer t denoting the number of test cases .
first line of each test case contains two space separated integers N and K denoting the total number of Princes and the number of hurdles.
The second line of each test case contains N space separated integers A[0],A[1],...,A[N-1] denoting princes jumping strength.
The third line of the each test case contains K space separated integers D[0],D[1],..,D[K-1] denoting height of hurdle i.
OUTPUT:
output a single integer denoting the ID of the winning prince.

CONSTRAINTS:

1<=t<=50
1 <= N <= 10^6
1 <= K <= 10^6
0 <= A[i] <= 10^9
0 <= D[i] <= 10^9

TEST CASE 1 
INPUT
2
5 5
10 20 30 40 50
7 7 7 7 7
7 5 
1 2 3 4 5 6 7
2 1 5 1 8

OUTPUT
0
4
TEST CASE 2
INPUT

1
4 4 
1 2 3 4 
2 1 5 8
OUTPUT
1
*/
#include <stdio.h>
 

int main()
{
    int n,k,i,id,t,j,aux,band;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
 
        int prince[n];
        int hurdle[k];
        for(i=0; i<n; i++)
        {
            scanf("%d",&prince[i]);
        }
        for(i=0; i<k; i++)
        { 
            scanf("%d",&hurdle[i]);
        }
         // quicksort(hurdle,k);
        id=0;
        aux=0;
 
        for(i=0; i<n; i++)
        {
            band=0;
            for(j=aux; j<k; j++)
            {
                if(prince[i]>=hurdle[j])
                    id=i;
                else
                {
                    band=1;
                    aux=j;
                    break;
                }
            }
            if(band==0)
                break;
        }
        printf("%d\n",id);
    }
    return 0;
}
