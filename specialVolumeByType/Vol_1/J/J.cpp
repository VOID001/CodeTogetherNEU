/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月14日 星期六 11时16分52秒
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
//#define DEBUG
using namespace std;
const int maxn=1005;

typedef struct node{
	int x;
	int y;
	int val;
}Node;

int T;
int R,C;
int fireboard[maxn][maxn];
int dir[][4]={{0,1,0,-1},{-1,0,1,0}};
char board[maxn][maxn];
queue<Node> fireque;
queue<Node> que;


bool validate(int x,int y)
{
	if(x>=1 && x<=R)
		if(y>=1 && y<=C)
			if(board[x][y]!='#')
				return true;
	return false;
}

void bfs_fire(int x,int y)
{
	bool vis[maxn][maxn]={{0}};
	bool inque[maxn][maxn]={{0}};
	while(!que.empty()) que.pop();
	Node tmp;
	tmp.x=x;tmp.y=y;tmp.val=0;
	que.push(tmp);
	inque[x][y]=1;
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		if(!vis[tmp.x][tmp.y])
		{
			if(fireboard[tmp.x][tmp.y]>tmp.val) fireboard[tmp.x][tmp.y]=tmp.val;
			vis[tmp.x][tmp.y]=1;
			Node ttmp;
			for(int i=0;i<4;i++)
			{
				ttmp.x=tmp.x+dir[0][i];
				ttmp.y=tmp.y+dir[1][i];
				if(!inque[ttmp.x][ttmp.y] && validate(ttmp.x,ttmp.y))
				{
					ttmp.val=tmp.val+1;
					que.push(ttmp);
					inque[ttmp.x][ttmp.y]=1;
				}
			}
		}
	}
#ifdef DEBUG
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			printf("%3d",fireboard[i][j]);
		}
		printf("\n");
	}
	printf("\n");
#endif
	return ;
}

int bfs_joe(int x,int y)
{
	bool vis[maxn][maxn]={{0}};
	bool inque[maxn][maxn]={{0}};
	while(!que.empty()) que.pop();
	Node tmp;
	tmp.x=x;tmp.y=y;tmp.val=0;
	que.push(tmp);
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		if(!vis[tmp.x][tmp.y])
		{
			if(tmp.x>R || tmp.y>C || tmp.x<1 || tmp.y<1) return tmp.val;
			vis[tmp.x][tmp.y]=1;
			Node ttmp;
			for(int i=0;i<4;i++)
			{
				ttmp.x=tmp.x+dir[0][i];
				ttmp.y=tmp.y+dir[1][i];
				ttmp.val=tmp.val+1;
				//if(!inque[ttmp.x][ttmp.y] && (ttmp.x>=1 && ttmp.x<=R && ttmp.y<=C && ttmp.y>=1 && ttmp.val<fireboard[ttmp.x][ttmp.y] && fireboard[ttmp.x][ttmp.y]!=-1)||(ttmp.x>R || ttmp.y>C|| ttmp.x<1 || ttmp.y<1))
				if(!inque[ttmp.x][ttmp.y])
				{
					if(ttmp.x>=1 && ttmp.x<=R && ttmp.y>=1 && ttmp.y<=C && ttmp.val<fireboard[ttmp.x][ttmp.y] && fireboard[ttmp.x][ttmp.y]!=-1)
					{
						que.push(ttmp);
						inque[ttmp.x][ttmp.y]=1;
					}
					else if(ttmp.x>R || ttmp.y>C || ttmp.x<1 || ttmp.y<1)
						return ttmp.val;
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int oo=1;oo<=T;oo++)
	{
		while(!fireque.empty()) fireque.pop();
		scanf("%d%d",&R,&C);
		//initboard();
		int joex;
		int joey;
		int firex;
		int firey;
		for(int i=1;i<=R;i++)
		{
			getchar();
			for(int j=1;j<=C;j++)
			{
				scanf("%c",&board[i][j]);
				if(board[i][j]=='#') fireboard[i][j]=-1;
				if(board[i][j]=='.') fireboard[i][j]=9999;
				if(board[i][j]=='F')
				{
					Node tmp;
					tmp.x=i;tmp.y=j;
					fireque.push(tmp);
					fireboard[i][j]=9999;
				}
				if(board[i][j]=='J')
				{
					joex=i;
					joey=j;
				}
			}
		}
		while(!fireque.empty())						//初始情况不止一处起火
		{
			Node tmp=fireque.front();
			fireque.pop();
			bfs_fire(tmp.x,tmp.y);
		}
		int res=bfs_joe(joex,joey);
		if(res==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",res);
	}
	return 0;
}
