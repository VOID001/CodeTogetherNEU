/*************************************************************************
    > File Name: 3694.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Tue May 12 20:35:51 2015
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

struct Node{
	int x;
	int y;


};

const bool operator < (const Node& a,const Node& b)
{
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

const int maxn = 100005;
vector<int> G[maxn];
set<Node> S;
map<pair<int,int>,int >MP;
int dfs_clock;
int N,M;
int Q;
int low[maxn];
int pre[maxn];
int bridgenum = 0;

int find_bridge(int u,int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for(int i = 0;i < G[u].size();i++)
	{
		int v = G[u][i];
		if(!pre[v])
		{
			child ++;
			int lowv = find_bridge(v,u);
			lowu = min(lowu,lowv);
			if(lowv > pre[u])
			{
				int tmp = min(v,u);
				Node ndtt;
				ndtt.x = tmp;
				ndtt.y = v + u - tmp;
				if(MP[make_pair(ndtt.x,ndtt.y)] == 1)
				{
					if(!S.count(ndtt))
					{
				//		printf("Bridge found (%d,%d)\n",ndtt.x,ndtt.y);
						S.insert(ndtt);
					}
				}
			}
		}
		else if(pre[v] < pre[u] && v != fa)
		{
			lowu = min(lowu,pre[v]);
		}
	}
	low[u] = lowu;
	return low[u];
}



int main(void)
{
	int cnt = 1;
	while(scanf("%d%d",&N,&M) && (N || M))
	{
		FORi(0,N)
		{
			G[i].clear();
		}
		MP.clear();
		dfs_clock = 0;
		int u,v;

		FORi(0,M)
		{
			scanf("%d%d",&u,&v);
			MP[make_pair(min(u,v),max(u,v))]++;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		scanf("%d",&Q);
		printf("Case %d:\n",cnt++);
		FORi(0,Q)
		{
			S.clear();
			bridgenum = 0;
			FORj(1,N+1)
			{
				low[j] = 0;
				pre[j] = 0;
			}
			scanf("%d%d",&u,&v);
			MP[make_pair(min(u,v),max(u,v))]++;
			G[u].push_back(v);
			G[v].push_back(u);
			find_bridge(1,-1);
			printf("%d\n",S.size());
		}
		printf("\n");

	}
	return 0;
}
