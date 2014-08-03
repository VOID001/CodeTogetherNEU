#include<stdio.h>
#include<string.h>

const int max_n=110;

int dp[max_n][max_n];
char s1[max_n],s2[max_n];

int max(int a,int b)
{
    return a>b?a:b;
}



int main(void)
{
    int i,j;
    int a,b;
    int arr1[max_n],arr2[max_n];
    int arrans[max_n];
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(arrans,0,sizeof(arrans));
        int cnt=1;
        for(int oo=0;oo<a;oo++)
            scanf("%d",&arr1[oo]);
        for(int oo=0;oo<b;oo++)
            scanf("%d",&arr2[oo]);
        for(i=0;i<a;i++)
            for(int j=0;j<b;j++)
        {
            if(arr1[i]==arr2[j] && arrans[cnt]<arr1[i]) {dp[i+1][j+1]=dp[i][j]+1;arrans[cnt++]=arr1[i];}
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        printf("%d\n",dp[a][b]);
    }
    return 0;
}
