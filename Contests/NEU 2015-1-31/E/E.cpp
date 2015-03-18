/*************************************************************************
    > File Name: E.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年01月31日 星期六 13时34分10秒
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

const int maxn=1000005;
int arr[maxn];
int tarr[maxn];

int main(void)
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d",arr+i);
			tarr[i]=arr[i];
		}
		//sort(arr,arr+N);
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			if(arr[i]!=i+1)
			{
				//swap arr[arr[i]-1] arr[i]
				cnt++;
				int t=arr[i];
				int mark1=arr[i];
				arr[i]=arr[mark1-1];
				arr[mark1-1]=t;
			}
		}
		printf("%d\n",cnt);
	}
}
