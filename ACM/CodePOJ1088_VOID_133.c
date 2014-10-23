#include<stdio.h>
#include<string.h>

const int MAX_N=105;
int dp[MAX_N][MAX_N];
int data[MAX_N][MAX_N];
int R,C;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dp_f(int r,int c);
int main(void)
{
    memset(dp,0,sizeof(dp));            //初始化
    scanf("%d%d",&R,&C);                //接收输入
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            scanf("%d",&data[i][j]);
    for(int i=0;i<R;i++)                //对每个格子进行记忆化搜索
        for(int j=0;j<C;j++)
            dp_f(i,j);
    int maxn=0;
    for(int i=0;i<R;i++)                //取最大值
        for(int j=0;j<C;j++)
            if(maxn<dp[i][j]) maxn=dp[i][j];
    printf("%d\n",maxn+1);
    return 0;

}

int dp_f(int r,int c)
{
    if(dp[r][c]) return dp[r][c];
    else
    {
        for(int i=0;i<4;i++)
        {
            if(r+dy[i]<R && r+dy[i]>=0 && c+dx[i]>=0 && c+dx[i]<C)
            {
                if(data[r][c]>data[r+dy[i]][c+dx[i]])
                    if(dp[r][c]<dp_f(r+dy[i],c+dx[i])+1)
                        dp[r][c]=dp_f(r+dy[i],c+dx[i])+1;
            }
        }
        return dp[r][c];
    }
}
