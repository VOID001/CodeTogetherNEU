/*************************************************************************
    > File Name: 1280.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月03日 星期三 16时23分03秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;

const int maxn=5000;

int hasht[10001];						//Max val is 10000

int N,M;
int arr[maxn];

int main(void)
{

	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(hasht,0,sizeof(hasht));

		for(int i=0;i<N;i++)
		{
			scanf("%d",arr+i);	
		}
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				hasht[arr[i]+arr[j]]++;
			}
		}
		int ptr=10000;
		while(M)
		{
			if(hasht[ptr])
			{
				printf("%d%s",ptr,M==1?"":" ");
				hasht[ptr]--;
				M--;
			}
			else ptr--;
		}
		printf("\n");
	}
	return 0;
}
