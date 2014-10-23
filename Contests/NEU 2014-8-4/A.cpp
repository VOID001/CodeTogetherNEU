#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(void)
{
	int arr[15];
	int P;
	cin>>P;
	int N;
	while(P--)
	{
		scanf("%d",&N);
		for(int i=0;i<15;i++)
		{
			scanf("%d",arr+i);
		}
		int islands=0;
		int pre=arr[0];
		for(int i=0;i<15;i++)
		{
			if(arr[i]<pre) islands++;
			pre=arr[i];
		}
		printf("%d %d\n",N,islands);
	}
	return 0;
	
}



