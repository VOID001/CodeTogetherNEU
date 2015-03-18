/*************************************************************************
    > File Name: I.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月11日 星期三 23时16分59秒
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
const int maxn=12;

int N,M;
char board[maxn][maxn];
bool vis[maxn][maxn];
bool inque[maxn][maxn];
int dirx[]={-1,0,1,0};
int diry[]={0,1,0,-1};
int grassNum;

typedef struct node{
	int x;
	int y;
	int steps;
}Node;

//bool checkOk()
//{
//	for(int i=1;i<=N;i++)
//	{
//		for(int j=1;j<=M;j++)
//		{
//			if(board[i][j]=='#' && !vis[i][j]) return false;
//		}
//	}
//	return true;
//}

int bfs(int x,int y,int i,int j)
{
	if(board[x][y]!='#' || board[i][j]!='#') return 0xffff;					//Not a legal choose
	int tmpGrassNum=grassNum;
	//printf("Start From X=%d Y=%d I=%d J=%d\n",x,y,i,j);
	int maxsteps=0;
	memset(vis,0,sizeof(vis));
	memset(inque,0,sizeof(inque));
	//for(int i=0;i<maxn;i++)
	//{
	//	for(int j=0;j<maxn;j++)
	//	{
	//		tmpboard[i][j]=board[i][j];
	//	}
	//}
	queue<Node> que;
	Node ta,tb;
	ta.x=x;ta.y=y;ta.steps=0;
	tb.x=i;tb.y=j;tb.steps=0;
	que.push(ta);que.push(tb);
	inque[ta.x][ta.y]=1;
	inque[tb.x][tb.y]=1;
	while(!que.empty())
	{
		Node tt=que.front();
		que.pop();
		if(!vis[tt.x][tt.y])
		{
			vis[tt.x][tt.y]=1;
			tmpGrassNum--;
			for(int oo=0;oo<4;oo++)
			{
				int tmpx=tt.x+dirx[oo];
				int tmpy=tt.y+diry[oo];
				if(!vis[tmpx][tmpy] && board[tmpx][tmpy]=='#')
				{
					Node ttmp;
					ttmp.x=tmpx;ttmp.y=tmpy;
					if(!inque[ttmp.x][ttmp.y])
					{
						ttmp.steps=tt.steps+1;
						if(ttmp.steps>maxsteps) maxsteps=ttmp.steps;
						que.push(ttmp);
						inque[ttmp.x][ttmp.y]=1;
					}
				}
			}
		}
	}
	if(!tmpGrassNum)
	{
		return maxsteps;
	}
	return 0xffff;
}

void boardinit()
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			board[i][j]='.';
		}
	}
	return ;
}

//void debug()
//{
//	for(int i=0;i<maxn;i++)
//	{
//		for(int j=0;j<maxn;j++)
//		{
//			printf("%c",board[i][j]);
//		}
//		printf("\n");
//	}
//	return ;
//}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int oo=1;oo<=T;oo++)
	{
		grassNum=0;
		scanf("%d%d",&N,&M);
		boardinit();
		for(int i=1;i<=N;i++)
		{
			getchar();
			for(int j=1;j<=M;j++)
			{
				scanf("%c",&board[i][j]);	
				if(board[i][j]=='#') grassNum++;
			}
		}
		//=====DEBUG=====
		//		debug();
		//===END DEBUG===
		int minstep=0xffff;
		for(int ooi=0;ooi<N*M;ooi++)
		{
			int i,j,x,y;
			for(int ooj=ooi;ooj<N*M;ooj++)
			{
				i=ooi/M+1;
				j=ooi%M+1;
				x=ooj/M+1;
				y=ooj%M+1;
				int tmp=bfs(i,j,x,y);
				if(minstep>tmp) minstep=tmp;
			}
		}
		printf("Case %d: %d\n",oo,minstep==0xffff?-1:minstep);
	}
	return 0;
}
