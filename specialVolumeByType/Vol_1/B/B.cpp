/*************************************************************************
  > File Name: B.cpp
  > Author: VOID_133
  > ###################
  > Mail: ###################
  > Created Time: 2015年01月31日 星期六 10时21分32秒
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

const int maxn=31;

string dungeon[maxn][maxn];
bool vis[maxn][maxn][maxn];
int dir[][3]={0,-1,0,0,0,1,0,1,0,0,0,-1,1,0,0,-1,0,0};
// FRNLUD
int L,R,C;

typedef struct node{
	int x;
	int y;
	int z;
	int dist;
}Node;
queue<Node> que;


bool validate(int x,int y,int z)
{
	if(x<0 || x>R-1 || y<0 || y>C-1 || z<0 || z>L-1) return false;
	if(dungeon[z][x][y]=='#') return false;
	if(vis[z][x][y]==1) return false;
	return true;
}

int bfs(int x,int y,int z)
{
	memset(vis,0,sizeof(vis));
	Node n;
	n.x=x;
	n.y=y;
	n.z=z;
	n.dist=0;
	vis[z][x][y]=1;
	que.push(n);
	while(!que.empty())
	{
		Node tmp=que.front();
		//printf("Now at X=%d Y=%d Z=%d\n",tmp.x,tmp.y,tmp.z); //DEBUG
		if(dungeon[tmp.z][tmp.x][tmp.y]=='E') return tmp.dist;
		que.pop();
		for(int i=0;i<6;i++)
		{
			if(validate(tmp.x+dir[i][1],tmp.y+dir[i][2],tmp.z+dir[i][0]))
			{
				Node ttmp;
				ttmp.x=tmp.x+dir[i][1];
				ttmp.y=tmp.y+dir[i][2];
				ttmp.z=tmp.z+dir[i][0];
				ttmp.dist=tmp.dist+1;
				que.push(ttmp);
				vis[ttmp.z][ttmp.x][ttmp.y]=1;
			}
		}
	}
	return -1;
}

int main(void)
{
	int tx,ty,tz;
	while(scanf("%d%d%d",&L,&R,&C) && (L || R || C))
	{
		while(!que.empty()) que.pop();
		for(int i=0;i<L;i++)
		{
			for(int j=0;j<R;j++)
			{
				//scanf("%s",dungeon[i][j]);
				cin>>dungeon[i][j];
				for(int k=0;k<C;k++)
				{
					if(dungeon[i][j][k]=='S')
					{
						tz=i;
						tx=j;
						ty=k;
					}
				}
			}
		}
		int res=bfs(tx,ty,tz);
		if(res==-1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n",res);
	}
	return 0;
}
