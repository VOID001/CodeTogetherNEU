/*************************************************************************
    > File Name: L.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月18日 星期三 17时56分09秒
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

#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

using namespace std;

const int maxn=101;
int dir[][8]={{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
bool vis[maxn][maxn];
int board[maxn][maxn];
int M,N; 

bool validate(int x,int y)
{
	if(x<0 || y<0 || x>=M || y>=N) return false;
	if(board[x][y]==0 || vis[x][y]==1) return false;
	return true;
}

bool dfs(int x,int y)
{
	vis[x][y]=1;
	FORi(0,8)
	{
		int tmpx=x+dir[0][i];
		int tmpy=y+dir[1][i];
		if(validate(tmpx,tmpy))
		{
			dfs(tmpx,tmpy);
		}
	}
	return true;
}

int main(void)
{
	while(scanf("%d%d",&M,&N) && N && M)
	{
		MEMSET0(vis);
		char ch;
		FORi(0,M)
		{
			getchar();
			FORj(0,N)
			{
				scanf("%c",&ch);
				if(ch=='@') board[i][j]=1;
				else if(ch=='*') board[i][j]=0;
			}
		}
		int count=0;
		FORi(0,M)
		{
			FORj(0,N)
			{
				if(!vis[i][j] && board[i][j]==1)
				{
					if(dfs(i,j)) count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
