#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#define inf 1<<25
using namespace std;

int fire[1010][1010];
int dis[1010][1010];
int r,c;
char map[1010][1010];
int sx,sy;
int fx,fy;
int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

bool judge(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c)
    {
        return true;
    }
    return false;
}

bool is_ok(int x,int y)
{
    if(x==0||x==r-1||y==0||y==c-1)
    {
        return true;
    }
    return false;
}

void bfs1()
{
    int i,j;
    queue<int> q;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(map[i][j]=='F')
            {
                q.push(i*c+j);
                fire[i][j]=0;
            }
        }
    }

    int x,y;
    int nx,ny;
    while(!q.empty())
    {
        int pre,cur;
        pre=q.front();
        q.pop();
        x=pre/c,y=pre%c;
        for(i=0; i<4; i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(!judge(nx,ny))
            {
                continue;
            }
            if(map[nx][ny]=='#')
            {
                continue;
            }

            if(fire[x][y]+1<fire[nx][ny])
            {
                fire[nx][ny]=fire[x][y]+1;
                q.push(nx*c+ny);
            }
        }
    }
}

void bfs2()
{
    int i,j;
    queue<int> q;
    memset(dis,-1,sizeof(dis));
    dis[sx][sy]=0;
    q.push(sx*c+sy);
    int nx,ny;
    int x,y;
    int cur,pre;
    while(!q.empty())
    {
        pre=q.front();
        q.pop();
        x=pre/c,y=pre%c;
        if(is_ok(x,y))
        {
            printf("%d\n",dis[x][y]+1);
            return;
        }
        for(i=0; i<4; i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(!judge(nx,ny))
            {
                continue;
            }
            if(dis[nx][ny]!=-1)
            {
                continue;
            }
            if(map[nx][ny]=='#'||map[nx][ny]=='F')
            {
                continue;
            }

            if(dis[x][y]+1>=fire[nx][ny])
            {
                continue;
            }
            dis[nx][ny]=dis[x][y]+1;
            q.push(nx*c+ny);
        }
    }
    puts("IMPOSSIBLE");
}

int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int i,j;
    while(T--)
    {
        scanf("%d %d",&r,&c);
        int flag2=0;
        for(i=0; i<r; i++)
        {
            scanf("%s",map[i]);
            for(j=0; j<c; j++)
            {
                fire[i][j]=inf;
                if(map[i][j]=='J')
                {
                    flag2=1;
                    sx=i,sy=j;
                }
            }
        }
        if(flag2==0)
        {
            puts("1");
            continue;
        }

        bfs1();
        bfs2();
    }
    return 0;
}
