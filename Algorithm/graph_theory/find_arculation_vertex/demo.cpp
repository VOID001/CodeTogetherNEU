/*************************************************************************
    > File Name: demo.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Tue May 12 16:43:45 2015
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
vector<int> G[maxn];
int pre[maxn];
int noden;
int edgen;
int dfs_clock;
bool iscut[maxn];
int low[maxn];

void getInput()
{
	printf("Please input the number of nodes: ");
	scanf("%d",&noden);
	printf("Please input the number of edges: ");
	scanf("%d",&edgen);
	printf("Now Please input the edges in format (u,v)\n");
	int a,b;
	FORi(0,edgen)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	return ;
}

void init()
{
	MEMSET0(pre);
	FORi(0,maxn)
	{
		G[i].clear();
	}
	dfs_clock = 0;
	MEMSET0(iscut);
	MEMSET0(low);
	return ;
}


int dfs(int u, int fa)
{
	printf("Visiting %d ,father is %d\n",u,fa);
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(!pre[v])
		{
			child++;
			int lowv = dfs(v,u);
			printf("Visiting %d ,father is %d\n",u,fa);
			lowu = min(lowv,lowu);
			if(lowv >= pre[u])
			{
				printf("Judge %d OK\n",v);
				iscut[u] = true;
				if(lowv > pre[u])
				{
					printf("(%d,%d) is Bridge\n",u,v);
				}
			}
		}
		else if(pre[v] < pre[u] && v != fa)
		{
			lowu = min(lowu,pre[v]);
		}
	}
	if(fa < 0 && child == 1) iscut[u] = 0;
	low[u] = lowu;
	dfs_clock++;
	return lowu;
}

void calcArcuVex()
{
	dfs(1,-1);
	FORi(1,noden+1)
	{
		if(iscut[i])
		{
			printf("Node No.%d is Articul\n",i);
		}
	}
	FORi(1,noden+1)
	{
		printf("%d ",low[i]);
	}
	printf("\n");
	FORi(1,noden+1)
	{
		printf("%d ",pre[i]);
	}
	printf("\n");
	return ;
}

int main(void)
{
	init();
	getInput();
	calcArcuVex();

	return 0;
}

//Sample Graph
//
// [1] --- [2]
//  | \     |
//  |  \    |	
//  |   \   | 	
//  |    \  |  	
//  |     \ |  	
// [3] --- [4]
//  |     / |
//  |    /  | 	
//  |   /   |	
//  |  /    |           
//  | /     |           
// [5]     [6]
//                      
//                      
// Node 4 is articul
// Edge (4,6) is Bridge
//                      
//                      
