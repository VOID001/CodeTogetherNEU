#include<stdio.h>
#include<string.h>

#define MAX 105
int main(void)
{
    int c;
    int cnt;
    char map[MAX];
    scanf("%d",&c);
    for(int i=1;i<=c;i++)
    {
        cnt =0;
        int row,col;
        scanf("%d%d",&row,&col);
        for(int j=0;j<row;j++)
        {
                scanf("%s",map);
                for(int k=0;k<col;k++)
                    if(map[k]=='O') cnt++;

        }
        printf("Case %d: %s\n",i,cnt%2?"Maze":"Fat brother");
    }
    return 0;
}
