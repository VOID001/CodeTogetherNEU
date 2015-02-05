/*************************************************************************
    > File Name: F.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年02月05日 星期四 16时22分06秒
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

const int maxn=10005;

bool isp[maxn];
bool vis[maxn];

struct Node{
	int digi[4];
	int cost;
	int val;
};

queue<Node> que;

void genPrime(int num)
{
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;
	isp[2]=1;
	for(int i=4;i<num;i+=2) isp[i]=0;
	for(int i=3;i<=num;i+=2)
	{
		if(isp[i])
		{
			for(int j=i+i;j<=num;j+=i)
			{
				isp[j]=0;
			}
		}
	}
	return ;
}

int bfs(int start,int end)
{
	while(!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));
	Node t;
	t.val=start;
	vis[start]=1;
	for(int i=3;i>=0;i--)
	{
		t.digi[i]=start%10;
		start/=10;
	}
	t.cost=0;
	que.push(t);
	while(!que.empty())
	{
		Node tmp=que.front();
		que.pop();
		if(tmp.val==end) return tmp.cost;
		for(int i=0;i<4;i++)
		{
			for(int j=(i==0?1:0);j<=9;j++)
			{
				Node T=tmp;
				T.digi[i]=j;
				T.val=0;
				for(int k=0;k<4;k++)
				{
					T.val=T.val*10+T.digi[k];
				}
				if(!vis[T.val] && isp[T.val])
				{
					vis[T.val]=1;
					T.cost++;
					que.push(T);
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	genPrime(maxn);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int st,ed;
		scanf("%d%d",&st,&ed);
		int res=bfs(st,ed);
		if(res==-1) printf("Impossible\n");
		else printf("%d\n",res);
	}
	return 0;
}
