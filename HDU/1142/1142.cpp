/*************************************************************************
    > File Name: 1142.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月13日 星期四 15时34分14秒
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
const int inf=1001000;

int graph[maxv][maxv];
bool visit[maxv];
int shortest_dist[maxv*maxv+10];
int d[maxv];
int N,M;
int dp[maxv];									//记忆话搜索

void init_graph()						//初始化图
{
	memset(visit,0,sizeof(visit));
	memset(dp,0,sizeof(dp));	
	memset(d,0,sizeof(d));	
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(i==j) graph[i][j]=0;
			else graph[i][j]=inf;
		}
	}
}

void dijkstra()
{
	for(int i=1;i<=N;i++)
	{
		shortest_dist[i]=graph[2][i];
	}
	d[2]=0;
	int curr_node=0;
	visit[2]=1;
	for(int i=1;i<=N;i++)
	{
		curr_node=1;
		int min=inf;
		for(int j=1;j<=N;j++)
		{
			if(!visit[j] && shortest_dist[j]<min )
			{
				curr_node=j;
				min=shortest_dist[j];
			}
		}
		if(min==inf)
		{
			return ;
		}
		visit[curr_node]=1;
		d[curr_node]=min;
		for(int j=1;j<=N;j++)
		{
			if(!visit[j] && graph[curr_node][j]!=inf && shortest_dist[curr_node]+graph[curr_node][j]<shortest_dist[j])
			{
				shortest_dist[j]=shortest_dist[curr_node]+graph[curr_node][j];
			}
		}

	}
	return ;
}

int DFS(int node)
{
	if(dp[node]) return dp[node];	
	if(node==2) return 1;
	int sum=0;
	for(int i=1;i<=N;i++)
	{
		if(graph[node][i]!=inf && shortest_dist[node]>shortest_dist[i])
		{
			if(dp[i]) sum+=dp[i];
			else sum+=DFS(i);
		}
	}
	sum+=dp[node];
	dp[node]=sum;
	return dp[node];
}

int main(void)
{
	int vst;
	int ved;
	int vdist;
	while(scanf("%d%d",&N,&M) && N)
	{
		init_graph();
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&vst,&ved,&vdist);
			graph[vst][ved]=vdist;
			graph[ved][vst]=vdist;
		}
		dijkstra();
		printf("%d\n",DFS(1));
	}
	return 0;
}
