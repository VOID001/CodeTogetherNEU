/*************************************************************************
    > File Name: UF.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 29 Jul 2015 09:20:31 AM CST
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

const int maxn = 5000000;

int id[maxn];
int sz[maxn];
int UF_count;
int N;

int UF_find(int p)
{
	while(p != id[p]) p = id[p];
	return p;
}

void UF_union(int p, int q)
{
	int i = UF_find(p);
	int j = UF_find(q);
	if(i == j) return;
	if(sz[i] > sz[j])		//i is the bigger tree
	{
		id[j] = i;
		sz[i] += sz[j];
	}
	else
	{
		id[i] = j;
		sz[j] += sz[i];
	}
	UF_count --;
	return ;
}

void UF_init()
{
	for(int i = 1; i <= N; i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
	UF_count = N;
}

int main(void)
{
	scanf("%d",&N);
	int u,v;
	UF_init();
	while(scanf("%d%d",&u,&v)!=EOF)
	{
		UF_union(u,v);
	}
	printf("%d\n",UF_count);
	return 0;
} 

