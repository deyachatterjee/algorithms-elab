/*
Little Mojo owns a match making company, which even to her surprise is an extreme hit. She says that her success rate cannot be matched (Yeah, wordplay!) in the entire match-making industry. She follows an extremely simple algorithm to determine if two people are matches for each other. Her algorithm is not at all complex, and makes no sense - not even to her. But she uses it anyway.
Let's say say that on a given day she decides to select n people - that is, n boys and n girls. She gets the list of n boys and n girls in a random order initially. Then, she arranges the list of girls in ascending order on the basis of their height and boys in descending order of their heights. A girl Ai can be matched to a boy on the same index only, that is, Bi and no one else. Likewise, a girl standing on Ak can be only matched to a boy on the same index Bk and no one else.
Now to determine if the pair would make an ideal pair, she checks if the modulo of their heights is 0, 
i.e., Ai % Bi == 0 or Bi % Ai == 0. Given the number of boys and girls, and their respective heights in non-sorted order, determine the number of ideal pairs Mojo can find.
Input format:
The first line contains number of test cases. Then, the next line contains an integer, n, saying the number of boys and girls. The next line contains the height of girls, followed by the height of boys.
Output format:
Print the number of ideal pairs corresponding to every test case.

Constraints:
1 <= Test Cases <= 10^2
1 <= N <= 10^4 
1 <= A i , B i <= 10^5

TEST CASE 1 
INPUT

1
3
2 2 2
2 2 2

OUTPUT

3
TEST CASE 2
INPUT

2
4
1 6 9 12
4 12 3 9
4
2 2 2 2
2 2 2 2

OUTPUT

2
4
*/
#include<stdio.h>
 
void swap(int[],int,int);
void quicksort(int[],int,int);
 
inline int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while (!('0' <= c && c <= '9')) {
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}
 
int main()
{
int t,i,c,b[10001],g[10001],a,n;
t=readint();
while(t--)
{
	c=0;
	n=readint();
	for(i=0;i<n;i++)
	b[i]=readint();
	for(i=0;i<n;i++)
	g[i]=readint();
	quicksort(g,0,n-1);
	quicksort(b,0,n-1);
	for(i=0;i<n;i++)
	{
		if(g[i]%b[n-1-i]==0 || b[n-1-i]%g[i]==0)
		c++;
	}
	printf("%d\n",c);
}
return 0;
}
 
void quicksort(int arr[],int left,int right)
{
int i, last;
if(left>=right)
return;
swap(arr,left,(left+right)/2);
last=left;
for(i=left+1;i<=right;i++)
if(arr[i]<arr[left])
swap(arr,++last,i);
swap(arr,left,last);
quicksort(arr,left,last-1);
quicksort(arr,last+1,right);
}
 
void swap(int arr[],int i,int j)
{
int temp;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}