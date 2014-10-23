/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月28日 星期四 13时16分11秒
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

typedef long long LL;

int dp[31][31][2];
int arr[32];

int main(void)
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",arr+i);
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(j!=i) dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
				if(j!=1)
				{
					if(dp[i-1][j-1][1]+arr[i]<=m) dp[i][j][1]=dp[i-1][j-1][1]+arr[i];
				}
				if((i!=j||j==1) && dp[i-1][j-1][0]+arr[i]> dp[i][j][1] && dp[i-1][j-1][0]+arr[i]<=m) dp[i][j][1]=dp[i-1][j-1][0]+arr[i];
			}
		}
		int maxn=-999999;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=1;j++)
			{
				maxn=max(maxn,dp[n][i][j]);
			}
		}
		printf("%d\n",maxn);
	}
	return 0;

}
