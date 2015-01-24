/*************************************************************************
    > File Name: 1043.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年01月24日 星期六 08时25分36秒
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

const int maxn=1000000;

int fac[10]={1,1,2,6,24,120,720,5040,40320};				//fac Arr
int next[maxn];
char dir[maxn];
int move[4][2]={0,1,1,0,0,-1,-1,0};
char mo[5]="lurd";

typedef struct node{
	int x,y;
	char mat[3][3];
}Node;

Node p,q;

bool inner(const Node& n)
{
	if(n.x>=0 && n.x<3 && n.y>=0 && n.y<3) return true;
	return false;
}

int hash(const Node& n)
{
	char tmp[9];
	int ans=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			tmp[i*3+j]=n.mat[i][j];
			int d=0;
			for(int k=0;k<i*3+j;k++)
			{
				if(tmp[k]>n.mat[i][j])
				{
					d++;
				}
			}
			ans+=fac[i*3+j]*d;
		}
	}
	return ans;
}

void bfs()
{
	memset(next,-1,sizeof(next));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			p.mat[i][j]='1'+i*3+j;
		}
	}
	p.mat[2][2]='0';
	p.x=p.y=2;
	int h=hash(p);
	next[h]=-2;
	dir[h]='\n';
	queue<Node> que;
	que.push(p);
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		h=hash(p);
		for(int i=0;i<4;i++)
		{
			q=p;
			q.x=q.x+move[i][0];
			q.y=q.y+move[i][1];
			if(inner(q))
			{
				int tmp=q.mat[p.x][p.y];
				q.mat[p.x][p.y]=q.mat[q.x][q.y];
				q.mat[q.x][q.y]=tmp;
				int hh=hash(q);
				if(next[hh]==-1)
				{
					next[hh]=h;
					dir[hh]=mo[i];
					que.push(q);
				}
			}
		}
	}
	return ;
}

int main(void)
{
	bfs();
	char t[2];
	while(scanf("%s",t)!=EOF)
	{
		if(t[0]=='x') t[0]='0';		//at first I forget to change the 'x' in the first column to '0' so made a mistake
		p.mat[0][0]=t[0];
		scanf("%s",t);
		if(t[0]=='x') t[0]='0';
		p.mat[0][1]=t[0];
		scanf("%s",t);
		if(t[0]=='x') t[0]='0';
		p.mat[0][2]=t[0];
		for(int i=1;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%s",t);
				if(t[0]=='x') t[0]='0';
				p.mat[i][j]=t[0];
			}
		}
		//for(int i=0;i<3;i++)
		//{
		//	for(int j=0;j<3;j++)
		//	{
		//		printf("%c ",p.mat[i][j]);
		//	}
		//	printf("\n");
		//}
		int h=hash(p);
		//printf("%d\n",next[h]);
		if(next[h]==-1)
		{
			printf("unsolvable\n");
		}
		else
		{
			while(next[h]!=-2)
			{
				printf("%c",dir[h]);
				h=next[h];
			}
			printf("\n");
		}
	}
	return 0;
}
