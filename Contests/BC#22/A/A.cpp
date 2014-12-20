/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月13日 星期六 19时02分18秒
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

typedef long long LL;



int arr[1000];

int conv(int a)
{
	int cnt=0;
	memset(arr,0,sizeof(arr));
	while(a)
	{
		arr[cnt++]=a%2;
		a/=2;
	}
	//for(int i=0;i<cnt;i++) printf("%d",arr[i]);
	//printf("\n");
	int sum=0;
	for(int i=0;i<cnt;i++)
	{
		sum=sum*2+arr[i];
	}
	return sum;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		a=conv(a);
		printf("%d\n",a);
	}
	return 0;
}
