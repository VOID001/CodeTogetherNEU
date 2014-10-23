/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月18日 星期一 15时00分38秒
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

const int INF = 1000000000;

int dp[52][1001];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		//memeset(dp,0,sizeof(dp));
		int no,balls,flor;
		scanf("%d%d%d",&no,&balls,&flor);
		for(int i=0;i<=flor;i++) dp[1][i]=i;
		for(int i=2;i<=balls;i++)
		{
			dp[i][0]=0;
			for(int j=1;j<=flor;j++)
			{
				dp[i][j]=INF;
				for(int k=1;k<=j;k++)
				{
					int tmp=max(dp[i-1][k-1],dp[i][j-k])+1;
					if(tmp<dp[i][j]) dp[i][j]=tmp;
				}
			}
		}
		cout<<no<<" "<<dp[balls][flor]<<endl;
	}
	return 0;
}
