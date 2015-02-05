/*************************************************************************
    > File Name: E.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年02月04日 星期三 20时20分28秒
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

const int maxn=205;

struct Node{
	string ans;
	int mod;
};

Node node[maxn];
Node tmp,TMP;
bool dis[maxn];

queue<Node> que;

void bfs(int m)
{
	memset(dis,0,sizeof(dis));
	while(!que.empty()) que.pop();
	tmp.mod=1;
	tmp.ans="1";					//Highest digi must be 1
	que.push(tmp);
	while(!que.empty())
	{
		TMP=tmp=que.front();
		que.pop();
		int x=(tmp.mod*10+0)%m;
		int y=(tmp.mod*10+1)%m;
		if(!x)
		{
			node[m].ans=tmp.ans+"0";
			return ;
		}
		if(!y)
		{
			node[m].ans=tmp.ans+"1";
			return ;
		}
		if(!dis[x])
		{
			tmp.ans=tmp.ans+"0";
			tmp.mod=x;
			que.push(tmp);
			dis[x]=true;
		}
		if(!dis[y])
		{
			TMP.ans=TMP.ans+"1";
			TMP.mod=y;
			que.push(TMP);
			dis[y]=true;
		}
	}
}

int main(void)
{
	node[1].ans="1";
	for(int i=2;i<=200;i++)
	{
		if(i%2==0) node[i].ans=node[i/2].ans+"0";
		else bfs(i);
	}
	int N;
	while(scanf("%d",&N) && N)
	{
		cout<<node[N].ans<<endl;
	}
	return 0;
}
