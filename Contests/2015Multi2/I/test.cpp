/*************************************************************************
    > File Name: test.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 23 Jul 2015 04:52:51 PM CST
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
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int arr[100000];
int main(void)
{
	for(int i=6;i<=50;i++)
	{
		int cnt = i;
		for(int k=1;k<=i;k++) arr[k] = i;
		for(int j = 0;j < i -1 ;j ++)
		{
			char op[2];
			int a;
			int b;
			scanf("%d %s %d",&a,op,&b);
			if(op[0] == '+')
			{
				arr[++cnt] = arr[a]+arr[b];
			}
			else if(op [0] == '-')
			{
				arr[++cnt] = arr[a]-arr[b];
			}
			else if(op [0] == '*')
			{
				arr[++cnt] = arr[a]*arr[b];
			}
			else if(op [0] == '/')
			{
				arr[++cnt] = arr[a]/arr[b];
			}
		}
		printf("Case %d ",i);
		if( arr[2*i-1] == 24 ) printf("OK\n");
		else printf("NO\n");
	}
}
