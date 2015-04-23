/*************************************************************************
    > File Name: N.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月19日 星期四 10时47分55秒
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

const int maxn=205;
int N,M;
char board[maxn][maxn];
int timeY[maxn][maxn];
int timeM[maxn][maxn];
bool vis[maxn][maxn];
bool inque[maxn][maxn];
int dir[][4]={{0,1,0,-1},{1,0,-1,0}};
typedef struct node{
	int x;
	int y;
	int step;
}Node;
queue<Node> que;
queue<pair<int,int> > KFCs;


bool validate(int x,int y)
{
	if(x<0 || y<0 || x>=N || y>=M) return false;
	if(board[x][y]=='#') return false;
	return true;
}

void bfsY(int x,int y)
{
	while(!que.empty()) que.pop();
	MEMSET0(vis);
	MEMSET0(inque);
	MEMSET0(timeY);

	Node tmp;
	tmp.x=x;
	tmp.y=y;
	tmp.step=0;
	que.push(tmp);

	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		if(!vis[tmp.x][tmp.y])
		{
			vis[tmp.x][tmp.y]=1;
			timeY[tmp.x][tmp.y]=tmp.step;
			Node ttmp;
			FORi(0,4)
			{
				ttmp.x=tmp.x+dir[0][i];
				ttmp.y=tmp.y+dir[1][i];
				ttmp.step=tmp.step+1;
				if(!inque[ttmp.x][ttmp.y] && validate(ttmp.x,ttmp.y))
				{
					que.push(ttmp);
					inque[ttmp.x][ttmp.y]=1;
				}
			}
		}
	}
	return ;
}

void bfsM(int x,int y)
{
	while(!que.empty()) que.pop();
	MEMSET0(vis);
	MEMSET0(inque);
	MEMSET0(timeM);

	Node tmp;
	tmp.x=x;
	tmp.y=y;
	tmp.step=0;
	que.push(tmp);

	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		if(!vis[tmp.x][tmp.y])
		{
			vis[tmp.x][tmp.y]=1;
			timeM[tmp.x][tmp.y]=tmp.step;
			Node ttmp;
			FORi(0,4)
			{
				ttmp.x=tmp.x+dir[0][i];
				ttmp.y=tmp.y+dir[1][i];
				ttmp.step=tmp.step+1;
				if(!inque[ttmp.x][ttmp.y] && validate(ttmp.x,ttmp.y))
				{
					que.push(ttmp);
					inque[ttmp.x][ttmp.y]=1;
				}
			}
		}
	}
	return ;

}

int main(void)
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		int Yx,Yy,Mx,My;
		while(!KFCs.empty())  KFCs.pop();
		FORi(0,N)
		{
			getchar();
			FORj(0,M)
			{
				scanf("%c",&board[i][j]);
				if(board[i][j]=='Y')
				{
					Yx=i;Yy=j;
				}
				if(board[i][j]=='M')
				{
					Mx=i;My=j;
				}
				if(board[i][j]=='@')
				{
					KFCs.push(make_pair(i,j));
				}
				
			}
		}
		bfsY(Yx,Yy);
		bfsM(Mx,My);
		int minn=99999;
		FORi(0,N)
		{
			FORj(0,M)
			{
				timeY[i][j]+=timeM[i][j];
			}
		}
		while(!KFCs.empty())
		{
			pair<int ,int> p=KFCs.front();
			KFCs.pop();
			if(timeY[p.first][p.second]<minn && timeY[p.first][p.second]!=0) minn=timeY[p.first][p.second];
		}
		printf("%d\n",minn*11);
	}
	return 0;
}



