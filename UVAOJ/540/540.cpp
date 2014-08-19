/*************************************************************************
  > File Name: 540.cpp
  > Author: VOID_133
  > QQ: 393952764
  > Mail: zhangjianqiu13@gmail.com
  > Created Time: 2014年08月16日 星期六 10时00分34秒
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

const int maxn=1001;
typedef queue<int> Queue;

//bool teamInQueue[maxn];

int main(void)
{
	int n;
	int id;
	int teamID;
	int cnt=1;
	while(scanf("%d",&n) && n)
	{
		//while(!teamque.empty()) teamque.pop();
		//for(int i=0;i<maxn;i++) {while(!que[i].empty()) {que.pop();}}
		//teamMap.clear();
		//memset(teamInQueue,0,sizeof(teamInQueue));
		map<int,int> teamMap;
		for(int i=1;i<=n;i++)
		{
			int num;
			scanf("%d",&num);
			for(int j=1;j<=num;j++)
			{
				scanf("%d",&id);
				teamMap[id]=i;
			}
		}
		printf("Scenario #%d\n",cnt++);
		//建立映射关系
		char op[10];
		Queue teamque;
		Queue que[maxn];
		while(scanf("%s",op) && op[0]!='S')
		{
			if(op[0]=='E')
			{
				scanf("%d",&id);
				teamID=teamMap[id];
				//cout<<"ID No"<<id<<" is from Team#"<<teamID<<endl;
				if(que[teamID].empty())
				{
					teamque.push(teamID);                  //进团队队列
					que[teamID].push(id);                  //进该团队
				}
				else
				{
					que[teamID].push(id);
				}
			}
			else if(op[0]=='D')
			{
				if(!teamque.empty())
				{
					teamID=teamque.front();
					int outid=que[teamID].front();
					que[teamID].pop();
					cout<<outid<<endl;
					if(que[teamID].empty()) teamque.pop();
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

