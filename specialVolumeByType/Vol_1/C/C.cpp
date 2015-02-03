/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2015年02月01日 星期日 21时40分35秒
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

int N,K;

const int maxn=100000;


queue<pair<int,int> > que;
bool vis[100005];

int bfs(int tmp)
{
	memset(vis,0,sizeof(vis));
	int cnt=0;
	que.push(make_pair(tmp,0));
	while(!que.empty())
	{
		pair<int,int> cur=que.front();
		que.pop();
		if(cur.first==K) return cur.second;
		if(cur.first>0 && !vis[cur.first-1]) {que.push(make_pair(cur.first-1,cur.second+1)); vis[cur.first-1]=1;}
		if(cur.first+1<=maxn && !vis[cur.first+1]) {que.push(make_pair(cur.first+1,cur.second+1));vis[cur.first+1]=1;}
		if(cur.first*2<=maxn && !vis[cur.first*2]) {que.push(make_pair(cur.first*2,cur.second+1));vis[cur.first*2]=1;}
	}
	return -1;
}

int main(void)
{
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		while(!que.empty()) que.pop();
		int res=bfs(N);
		printf("%d\n",res);
	}
	return 0;
}
