/*************************************************************************
    > File Name: tarjan.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
	> Content: A Tarjan Algorithm Demo
    > Created Time: Thu May  7 09:11:17 2015
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
const int maxn=1000;

vector<int> G[maxn];
stack<int> S;
bool vis[maxn];
int edgen,noden;
int dfs_clock=0;
int dfn[maxn];
int low[maxn];
int sccno[maxn];
int scc_num=0;

void getInput()
{
	int cnt=0;
	printf("Please input the Number of Nodes ");
	scanf("%d",&noden);
	printf("Please input the Number of Edges (Number starts from 1) ");
	scanf("%d",&edgen);
	printf("Now please input the %d edge(s) in format (u v) without ()\n");
	int u,v;
	FORi(1,edgen+1)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	return ;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfs_clock;
	S.push(u);
	for(int i = 0;i < G[u].size();i++)		//DFS into Graph
	{
		int v = G[u][i];
		if(!low[v])							//Haven't be visited yet
		{
			tarjan(v);
			low[u] = min(low[v],low[u]);
		}
		else if(!sccno[v])					//u is not in any SCC now
		{
			low[u] = min(dfn[v],low[u]);
		}
	}
	if(dfn[u] == low[u])
	{
		scc_num++;							//Found the root of a SCC,pop them out
		printf("The No.%d SCC found, Below are the nodes in it\n",scc_num);
		for(;;)
		{
			int tmp = S.top();
			S.pop();
			sccno[tmp] = scc_num;
			printf("%d ",tmp);
			if(tmp == u) break;
		}
		printf("\n");
	}
	return ;
}

void init()
{
	MEMSET0(low);
	MEMSET0(vis);
	MEMSET0(dfn);
	MEMSET0(sccno);
	FORi(0,maxn) G[i].clear();
	scc_num=0;
	dfs_clock=0;
}

int main(void)
{
	init();
	getInput();
	FORi(1,noden+1)
	{
		if(!dfn[i])
			tarjan(i);
	}
	return 0;
}

