/*************************************************************************
    > File Name: 1232.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月20日 星期四 13时04分33秒
	> Description: An obiviously Union Find Set
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

const int maxv=1010;
int father[maxv];

int findroot(int i)
{
	if(father[i]!=i)
	{
		father[i]=findroot(father[i]);
	}
	return father[i];
}

void UF_connect(int a,int b)
{
	int x=findroot(a);
	int y=findroot(b);
	if(x!=y)
	{
		father[x]=y;
	}
	return ;
}

int main(void)
{
	int m,n;
	while(scanf("%d",&m) && m)
	{
		scanf("%d",&n);
		//Initialize UF Set
		for(int i=1;i<=m;i++)
		{
			father[i]=i;
		}

		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			UF_connect(a,b);
		}
		for(int i=1;i<=m;i++)
		{
			father[i]=findroot(i);
		}
		int count=0;
		for(int i=1;i<=m;i++)
		{
			if(father[i]==i) count++;
		}	
		printf("%d\n",count-1);
	}
	return 0;
}
