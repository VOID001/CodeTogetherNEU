/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月07日 星期日 12时07分00秒
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

int arr[250];

bool cmp(int a,int b)
{
	return a>b;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			scanf("%d",arr+i);
		}
		sort(arr,arr+m,cmp);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=arr[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
