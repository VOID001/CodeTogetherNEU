/*************************************************************************
    > File Name: 1018~.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月08日 星期一 20时02分33秒
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

const int maxn=105;

int b[maxn];
int p[maxn];
int dp[maxn][maxn*10];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		int n;
		scanf("%d",&n);
		int maxb=-999;
		for(int i=1;i<=n;i++)
		{
			int m;
			scanf("%d",&m);
			for(int k=0;k<m;k++)
			{
				scanf("%d%d",b+k,p+k);
				maxb=max(maxb,b[k]);	
			}
			if(1==i)
			{
				for(int k=0;k<m;k++)
				{
					dp[1][b[k]]=p[k];
				}
				continue;
			}
			for(int k=0;k<=maxb;k++)
			{
				if(dp[i-1][k]!=-1)
				{
					for(int t=0;t<m;t++)
					{
						int minb=min(k,b[t]);
						if(-1 == dp[i][minb])
							dp[i][minb]=dp[i-1][k]+p[t];
						else
							dp[i][minb]=min(dp[i][minb],dp[i-1][k]+p[t]);
					}
				}
			}

		}
		double ans=0;
		for(int i=0;i<=maxb;i++)
		{
			if(dp[n][i]!=-1)
				ans=max(ans,1.0*i/dp[n][i]);
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
