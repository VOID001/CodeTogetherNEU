#include<stdio.h>
#include<string.h>
#define MAX 602

long long dp[MAX][MAX];
long long A(int n,int m)
{
    if(dp[n][m]>=0) return dp[n][m];
    else
    {
        if(m==1) return 1;
        if(m==n) return 1;
        if(n<m) return 0;
        else return dp[n][m]=A(n-1,m-1)+A(n-m,m);
    }
}

int main(void)
{
    int n,m;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        long long res=A(n+m,m);
        printf("%lld\n",res);
    }
    return 0;
}
