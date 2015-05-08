/*************************************************************************
    > File Name: 1236.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Fri May  8 17:59:19 2015
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
const int maxn=10005;

vector<int> G[maxn];
stack<int> S;			//SCC Stack
int in[maxn];
int out[maxn];
int newin[maxn];
int newout[maxn];
int sccno[maxn];
int dfn[maxn];
int low[maxn];
int dfs_clock;
int N;
int minedge;
int scc_count;
int minchose;


void tarjan(int u)
{
	S.push(u);
	low[u]=dfn[u]=dfs_clock++;
	for(int i=0;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(!sccno[v])
		{
			low[u] = min(dfn[v],low[u]);
		}
	}
	if(dfn[u] == low[u])
	{
		scc_count++;
		for(;;)
		{
			int tmp=S.top();
			S.pop();
			sccno[tmp] = scc_count;
			if( tmp == u ) break;
		}
	}
	return ;
}

void compress()					//After tarjan Compress the Graph
{
	FORi(1,N+1)
	{
		for(int j=0;j<G[i].size();j++)
		{
			int tmp = G[i][j];
			if( sccno[tmp] != sccno[i] )		//Not int the same SCC
			{
				newout[sccno[i]]++;
				newin[sccno[tmp]]++;
			}
		}
	}
	return ;
}

void init()
{
	MEMSET0(in);
	MEMSET0(out);
	MEMSET0(newin);
	MEMSET0(newout);
	MEMSET0(sccno);
	MEMSET0(dfn);
	MEMSET0(low);
	while(!S.empty())
		S.pop();
	FORi(0,maxn)
		G[i].clear();
	dfs_clock = 0;
	scc_count = 0;
}

void gao()
{
	FORi(1,N+1)
	{
		if(!dfn[i]) tarjan(i);
	}

	minchose=0;
	int tmpa,tmpb;
	tmpa=tmpb=0;
	compress();
	FORi(1,scc_count+1)
	{
		if(newin[i] == 0)
		{
			minchose++;
			tmpa++;
		}
		if(newout[i] == 0)
		{
			tmpb++;
		}
	}
	minedge = max(tmpa,tmpb);
}

int main(void)
{
	while(scanf("%d",&N)!=EOF)
	{
		init();
		FORi(1,N+1)
		{
			int tmp;
			while(scanf("%d",&tmp) && tmp)
			{
				if(i == tmp) continue;
				G[i].push_back(tmp);
				out[i]++;
				in[tmp]++;
			}
		}
		gao();
		if(scc_count == 1)
			printf("1\n0\n");
		else
			printf("%d\n%d\n",minchose,minedge);
	}
	return 0;
}
