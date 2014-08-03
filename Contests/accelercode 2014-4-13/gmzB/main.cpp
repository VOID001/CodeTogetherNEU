#include<stdio.h>
#include<string.h>
#include<algorithm>
const int MAX=25;


double C(int x)
{
    double sum=1;
    for(int i=1;i<=x;i++)
    {
        sum*=i;
    }
    return sum;
}


int main(void)
{
    int cases;
    int N,k,r;
    double gift[MAX];
    int cnt[25];
    int send[25];
    double pro=1;
    scanf("%d",&cases);
    while(cases--)
    {
        pro=1;
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d",&N,&k,&r);
        for(int i=0;i<N;i++)
        {
            scanf("%lf",&gift[i]);
        }
        for(int i=0;i<r;i++)
        {
            scanf("%d",&send[i]);
            cnt[send[i]]++;
            pro*=gift[send[i]];
        }
        pro*=C(N);
        for(int i=1;i<=N;i++)
        {
            if(!cnt[i]) continue;
            pro/=C(cnt[i]);
        }
        printf("%lf\n",pro);
    }
}
