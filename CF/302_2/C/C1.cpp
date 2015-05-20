/*************************************************************************
    > File Name: C1.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Wed May 20 11:37:35 2015
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
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

const int maxn = 502;
long long mod;
long long dp[maxn][maxn];
int n,m,b;
int arr[maxn];

int main(void)
{
	while(scanf("%d%d%d%I64d",&n,&m,&b,&mod)!=EOF)
	{
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",arr+i);
		}
		dp[0][0]=1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1;j<= m; j++)
			{
				for(int k=0; k<=b; k++)
				{
					if(k < arr[i])
					{
						dp[j][k] = dp[j][k];
					}
					else
					{
						dp[j][k] = (dp[j-1][k-arr[i]]+dp[j][k])%mod;
					}
				}
			}
		}
		long long ans=0;
		for(int i=0;i<=b;i++)
			ans= (ans+dp[m][i])%mod;

		printf("%I64d\n",ans);
	}
	return 0;
}
