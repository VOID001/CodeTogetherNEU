/*************************************************************************
    > File Name: K.cpp > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2015年03月16日 星期一 17时58分33秒
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
const int maxn=6;

typedef struct node{
	int x,y;
	int prex,prey;
}Node;

int board[maxn][maxn];
int dir[][4]={{-1,0,1,0},{0,1,0,-1}};
bool vis[maxn][maxn];
bool inque[maxn][maxn];
queue<Node> que;
vector<Node> vec;

const Node& getPrev(const Node& nd);

int bfs()
{
	while(!que.empty()) que.pop();
	vec.clear();
	memset(vis,0,sizeof(vis));
	memset(inque,0,sizeof(inque));
	Node tmp;
	tmp.x=tmp.y=0;
	tmp.prex=tmp.prey=-1;
	inque[0][0]=1;
	que.push(tmp);
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		if(!vis[tmp.x][tmp.y])
		{
			vec.push_back(tmp);
			vis[tmp.x][tmp.y]=1;
			if(tmp.x==4 && tmp.y==4) return vec.size();
			Node ttmp;
			for(int i=0;i<4;i++)
			{
				ttmp.x=tmp.x+dir[0][i];
				ttmp.y=tmp.y+dir[1][i];
				ttmp.prex=tmp.x;
				ttmp.prey=tmp.y;
				if(board[ttmp.x][ttmp.y]==0 && !vis[ttmp.x][ttmp.y] && !inque[ttmp.x][ttmp.y] && ttmp.x>=0 && ttmp.x<5 && ttmp.y>=0 && ttmp.y<5)
				{
					que.push(ttmp);
					inque[ttmp.x][ttmp.y]=1;
				}
			}
		}
	}
	return vec.size();
}

void printResult(const Node& nd)
{
	if(nd.x!=0 || nd.y!=0)
	printResult(getPrev(nd));
	printf("(%d, %d)\n",nd.x,nd.y);

}

const Node& getPrev(const Node& nd)
{
	for(vector<Node>::iterator it=vec.begin();it!=vec.end();it++)
	{
		if((*it).x==nd.prex && (*it).y==nd.prey)
			return *it;
	}
}

int main(void)
{
	while(1)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				int res=scanf("%d",&board[i][j]);
				if(res==EOF) return 0;
			}
		}
		int curr=bfs();
		//printf("%d\n",curr);
		printResult(vec[curr-1]);
	}
	return 0;

}
