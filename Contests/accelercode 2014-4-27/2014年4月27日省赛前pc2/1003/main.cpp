#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[1000000];
int f(int n);

int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        int res=f(n);
        if(n==1) printf("1\n");
        else
        {
            printf("%d\n",res-1==0?n:res-1);
        }
    }
    return 0;
}

int f(int n)
{
    if(dp[n]>0) return dp[n];
    else
    {
        if (n==1) return 1;
        if(!(n%2)) return dp[n]=2*f(n/2)-1;
        if(n%2) return dp[n]=2*f(n/2)+1;
    }

}
