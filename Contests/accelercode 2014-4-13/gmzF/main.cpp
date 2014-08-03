#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ans;
int gx,gy;
int n;
int m[10][10];

void dfs(int x,int y)
{
    if(y>4)
    {
        x++;y=1;
        if(x>n)
        {
            ans++;
            return ;
        }
    }
    if(m[x][y])dfs(x,y+1);
    if(!(m[x][y]))
    {
        m[x][y]=1;
        dfs(x,y+1);
        m[x][y]=0;
    }
    if(!m[x][y] && y+1<=4 && !m[x][y+1])
    {
        m[x][y]=m[x][y+1]=1;
        dfs(x,y+2);
        m[x][y]=m[x][y+1]=0;
    }
    if(!m[x][y] && x+1<=n && !m[x+1][y])
    {
        m[x][y]=m[x+1][y]=1;
        dfs(x,y+1);
        m[x][y]=m[x+1][y]=0;
    }
    return ;
}


int main(void)
{

    memset(m,0,sizeof(m));
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=3;j++)
        {
            memset(m,0,sizeof(m));
            m[i][j]=1;m[i+1][j]=1;m[i][j+1]=1;m[i+1][j+1]=1;
            dfs(1,1);

        }
    }
    printf("%d\n",ans);
    }
}
