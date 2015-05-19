/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Mon May 18 22:32:58 2015
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
int n,m,b;
long long mod;
int a[maxn];
long long dp[2][maxn][maxn];

int main(void)
{
	while(scanf("%d%d%d%I64d",&n,&m,&b,&mod)!=EOF)
	{
		MEMSET0(dp);
		MEMSET0(a);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		dp[0][0][0]=1L;
		dp[1][0][0]=1L;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				//puts("MARK\n");
				for(int k=0;k<=b;k++)
				{
					if(a[i]>k)
					{
						dp[i%2][j][k]=dp[(i-1)%2][j][k]%mod;
					}
					else 
					{
						dp[i%2][j][k]=(dp[(i-1)%2][j][k]+dp[i%2][j-1][k-a[i]])%mod;
					}
				}
			}
		}
		long long ans=0;
		for(int i=0;i<=b;i++)
		{
			ans= ( ans + dp[n%2][m][i] ) % mod;
		}
		ans = ans % mod;
		printf("%I64d\n",ans);
	}
	return 0;
}
