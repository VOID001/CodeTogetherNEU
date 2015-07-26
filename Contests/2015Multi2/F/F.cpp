/*************************************************************************
    > File Name: F.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: Thu 23 Jul 2015 12:30:23 PM CST
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
const int maxn = 9;

vector<int> G[maxn];

typedef struct edge{
	int u;
	int v;
	int rel;		//0 offline 1 online;
	int id;
}Edge;

vector<Edge> Edgev[maxn];
int oncnt[maxn];
int offcnt[maxn];
int deg[maxn];
int totdeg;
int vis[100];

int m,n;
int ID=1;
int totvis;
int ans;

bool check();

void dfs(int u)
{
	if(totvis == m)
	{
		if(check())
		{
			ans++;
		}
		return ;
	}
	for(int i=0;i<Edgev[u].size();i++)
	{
		Edge tmpee = Edgev[u][i];
		if(vis[tmpee.id] == 0)
		{
			if(oncnt[tmpee.u] < deg[tmpee.u]/2)
			{
				tmpee.rel = 1;
				oncnt[tmpee.u]++;
				oncnt[tmpee.v]++;
				vis[tmpee.id] = 1;
				totvis++;
				dfs(tmpee.v);
				tmpee.rel = -1;
				oncnt[tmpee.u]--;
				oncnt[tmpee.v]--;
				vis[tmpee.id] = 0;
				totvis--;
			}
			if(offcnt[tmpee.u] < deg[tmpee.u]/2)
			{
				tmpee.rel = 0;
				offcnt[tmpee.u]++;
				offcnt[tmpee.v]++;
				vis[tmpee.id] = 1;
				totvis++;
				dfs(tmpee.v);
				tmpee.rel = -1;
				offcnt[tmpee.u]--;
				offcnt[tmpee.v]--;
				vis[tmpee.id] = 0;
				totvis--;
			}
			if(offcnt[tmpee.u] > deg[tmpee.u]/2) return;
			if(oncnt[tmpee.u] > deg[tmpee.u]/2) return;
		}
	}
}


bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(oncnt[i] != offcnt[i] || (oncnt[i] + offcnt[i]) != deg[i])
			return false;
	}
	return true;
}
int main(void)
{
	int T;
	int u,v;
	scanf("%d",&T);
	while(T--)
	{
		ID = 1;
		for(int i = 0; i<=9; i++)
		{
			Edgev[i].clear();
		}
		memset(vis,0,sizeof(vis));
		memset(deg,0,sizeof(deg));
		memset(oncnt,0,sizeof(oncnt));
		memset(offcnt,0,sizeof(offcnt));
		totdeg = 0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			G[v].push_back(u);
			G[u].push_back(v);
			deg[v]++;
			deg[u]++;
			totdeg += 2;
			Edge ee;
			ee.u = u;
			ee.v = v;
			ee.rel = -1;		//Init
			ee.id = ID++;
			Edgev[u].push_back(ee);
			Edgev[v].push_back(ee);
		}
		bool KO=true;
		for(int i=1;i<=n;i++)
		{
			if(deg[i]%2) KO=false;
		}
		totvis=0;
		ans = 0;
		if(KO)
		{
			dfs(1);
		}
		printf("%d\n",ans);
	}
	return 0 ;
}

