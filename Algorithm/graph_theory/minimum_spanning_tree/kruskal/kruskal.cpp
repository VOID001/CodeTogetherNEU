/*************************************************************************
    > File Name: kruskal.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Tue 28 Jul 2015 10:29:21 AM CST
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

const int maxn = 1000;

struct Edge{
	int u;
	int v;
	int weight;
};

int id[1000];
int sz[1000];
int m, n;
int UF_count;
vector<int> G[maxn];
vector<Edge> edgev;
vector<Edge> resultv;

bool cmp(Edge a, Edge b)
{
	return a.weight<b.weight;
}

int UF_find(int u)
{
	while(u != id[u]) u = id[u];
	return u;
}

void UF_union(int u,int v)
{
	int i = UF_find(u);
	int j = UF_find(v);
	if(i == j) return ;
	if(sz[i] > sz[j])
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

bool UF_connected(int u, int v)
{
	return UF_find(u) == UF_find(v);
}

void UF_init()
{
	for(int i = 0; i <= n; i++)
	{
		sz[i] = 1;
		id[i] = i;
	}
	UF_count = n;
}

int main(void)
{
	printf("MST Demo -- Kruskal\n");
	printf("Input n and m ( n for number of vertices , m for number of edges )\n");
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 0 ; i <= n; i++) G[i].clear();
		edgev.clear();
		resultv.clear();
		UF_init();
		int u,v,w;
		int tmp = m;
		while( tmp-- )
		{
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(v);
			G[v].push_back(u);
			Edge etmp;
			etmp.u = u;
			etmp.v = v;
			etmp.weight = w;
			edgev.push_back(etmp);
		}
		sort(edgev.begin(),edgev.end(),cmp);
		int minweigh = 0;
		for(vector<Edge>::iterator ii = edgev.begin(); ii != edgev.end(); ii++)
		{
			u = (*ii).u;
			v = (*ii).v;
			if(!UF_connected(u,v))
			{
				resultv.push_back(*ii);
				minweigh += (*ii).weight;
				UF_union(u,v);
			}
		}
		printf("The result is:\n");
		for(int i = 0; i < resultv.size(); i++)
		{
			printf("(%d,%d)\n",resultv[i].u,resultv[i].v);
		}
	}
}
