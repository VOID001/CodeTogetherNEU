/*************************************************************************
    > File Name: dijkstra.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月03日 星期一 09时15分15秒
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
#define AUTO if(debug) 
using namespace std;
const int maxn=5000;
const bool debug=true;						//If Debug=True the command line will output DEBUG_INFO
const int inf=1000010;

int graph[maxn][maxn];						//Use a 2-dimensions Array to store the Graph
int visited[maxn];							//Use visited to judge whether the node is visited or not
int shortest_dist[maxn];					//the array is for storing the shortest(tmp) distance from S to i
int n_edge,n_node;

void init()									// n for numbers of Nodes s is the index of the destination
{
	AUTO printf("Please input the number of the nodes (Must >= 2) ");
	scanf("%d",&n_node);
	int node1,node2,dest;
	AUTO printf("The destination is set to Node 2 , You start at Node 1\n");
	AUTO printf("Initializing...\n");
	for(int i=1;i<=n_node;i++)
	{
		for(int j=1;j<=n_node;j++)
		{
			if(i==j) graph[i][j]=0;
			else graph[i][j]=inf;
		}
	}
	memset(visited,0,sizeof(visited));
	AUTO printf("Initialize Complete\n");
	AUTO printf("Please input the number of the edges ");
	scanf("%d",&n_edge);
	AUTO printf("You have set %d edges Now Please input like this :\n first_node sec_node dest \n e.g.: 1 2 4 means there is a path from node 1 to node 2 which length is 4 \n ",n_edge);
	for(int i=0;i<n_edge;i++)
	{
		scanf("%d%d%d",&node1,&node2,&dest);
		graph[node1][node2]=dest;	
		graph[node2][node1]=dest;	
	}
	AUTO printf("All settings done Dijkstra will Start...\n");
}


void dijkstra ()									//Dijkstra is for finding the shortest path from S to any other node
{
	for(int i=1;i<=n_node;i++)
	{
		shortest_dist[i]=graph[1][i];
		AUTO printf("PATH FROM %d to %d is %d \n",1,i,graph[1][i]);
	}
	int curr_node=0;
	visited[1]=1;
	for(int i=1;i<=n_node;i++)
	{
		curr_node=1;	
		int min=inf;
		for(int j=1;j<=n_node;j++)
		{
			if(!visited[j] && shortest_dist[j]<min)
			{
				AUTO printf("shorter path found at %d\n",j);
				curr_node=j;
				min=shortest_dist[j];
			}
		}
		if(min==inf)								//No Path found from S to i
		{
			AUTO printf("NO PATH FOUND min=%d inf=%d \n",min,inf);
			return ;
		}
		visited[curr_node]=1;
		for(int j=1;j<=n_node;j++)
		{
			if(!visited[j] && graph[curr_node][j]!=inf && shortest_dist[curr_node]+graph[curr_node][j]<shortest_dist[j])
			{
				shortest_dist[j]=shortest_dist[curr_node]+graph[curr_node][j];
			}
		}
	}
	return ;
}

void splash()
{
	system("clear");
	printf("**********************************************************\n");
	printf("*                                                        *\n");
	printf("*     #   #    0                                         *\n");
	printf("*      ##                                                *\n");
	printf("*    #   #   O       Dijkstra Demo                       *\n");
	printf("*                                                        *\n");
	printf("*          O                              Ver 1.0        *\n");
	printf("*        o                             By-VOID001        *\n");
	printf("*                                                        *\n");
	printf("**********************************************************\n");
	getchar();
	system("clear");
	return ;
}

int main(void)
{
	AUTO splash();	
	init();
	dijkstra();
	AUTO printf("The shoretest path from node 1 To 2 is ");
	printf("%d\n",shortest_dist[2]);
	return 0;
}
