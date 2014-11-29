/*************************************************************************
    > File Name: 1213.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月18日 星期二 09时06分29秒
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

const int maxn=1010;
int father[maxn];
int flag[maxn];

void init()
{
	for(int i=0;i<=maxn;i++)
	{
		father[i]=i;
	}
	return ;
}

int findroot(int i)
{
	if(father[i]!=i)
	{
		father[i]=findroot(father[i]);
	}
	return father[i];
}

void connect(int a,int b)
{
	int x,y;
	x=findroot(a);
	y=findroot(b);
	if(x!=y)
	{
		father[x]=y;
	}
	return ;
}


int main(void)
{
	int T;
	scanf("%d",&T);
	int vexa,vexb;
	while(T--)
	{
		int m,n;
		memset(flag,0,sizeof(flag));
		scanf("%d%d",&m,&n);
		init();
		while(n--)
		{
			scanf("%d%d",&vexa,&vexb);
			connect(vexa,vexb);
		}
		for(int i=1;i<=m;i++)
		{
			flag[findroot(i)]=1;
		}
		int count=0;
		for(int i=1;i<=m;i++)
		{
			if(flag[i]) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
