/*************************************************************************
    > File Name: F.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月18日 星期一 13时31分21秒
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

LL dp[110][110][2];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int no;
		int digi;
		int wei;
		scanf("%d%d%d",&no,&digi,&wei);
		dp[1][0][1]=dp[1][0][0]=1;
		for(int i=2;i<=digi;i++)
		{
			for(int j=0;j<=i-1;j++)
			{
				if(j==0) 
					dp[i][j][1]=dp[i-1][j][0];
				else
				{
					dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j][0];
				}
				dp[i][j][0]=dp[i-1][j][1]+dp[i-1][j][0];
			}
		}
		printf("%d %lld\n",no,dp[digi][wei][0]+dp[digi][wei][1]);
	}
	return 0;
}
