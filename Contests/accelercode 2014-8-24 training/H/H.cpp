/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月24日 星期日 13时25分57秒
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

int width;
int connectn[10011];
int link[10011][3];

int  fac(int n)
{
	if(connectn[n]==0) return 1;
	if(connectn[n]==1) 
		return fac(link[n][0]);
	if(connectn[n]==2)
	{
		int a=fac(link[n][0]);
		int b=fac(link[n][1]);
		if(a==b) return a+1;
		else return max(a,b);
	}
	return 0;
}

int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(connectn,0,sizeof(connectn));
		for(int i=2;i<=n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			link[tmp][connectn[tmp]]=i;
			connectn[tmp]++;
		}
		cout<<fac(1)<<endl;
	}
	return 0;
}
