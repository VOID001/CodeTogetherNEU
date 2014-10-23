#include<stdio.h>
#include<string.h>
#define MAX 35
//#define LOCAL

const double esp=1e-9;
typedef struct point
{
    double x,y;
}point;

point P[MAX];

int wa=0;
int fun(int m,int n,int p,int q);
int main(void)
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        memset(P,0,sizeof(P));
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%lf%lf",&P[j].x,&P[j].y);
        }
        int cnt=0;
        for(int m=0;m<N;m++)
        {
            for(int n=m+1;n<N;n++)
            {
                for(int p=n+1;p<N;p++)
                {
                    for(int q=p+1;q<N;q++)
                    {
                        //Judge
                        wa=0;
                        if(fun(m,n,p,q)==-1) continue;
                        if(fun(m,p,n,q)==-1) continue;
                        if(fun(m,q,p,n)==-1) continue;
                        if(fun(n,p,m,q)==-1) continue;
                        if(fun(n,q,m,p)==-1) continue;
                        if(fun(p,q,m,n)==-1) continue;
                        //
                        if(wa==2) cnt++;
                    }
                }
            }
        }
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}

int fun(int m,int n,int p,int q)
{
    if(P[m].x==P[n].x)
    {
        double tmpj=(P[p].x-P[m].x)*(P[q].x-P[m].x);
        if(tmpj<0) wa++;
        tmpj=tmpj>0?tmpj:-tmpj;
        if(tmpj<esp) return -1;
    }
    else
    {
        double k=(P[m].y-P[n].y)/(P[m].x-P[n].x);
        double tmpi=P[p].y-P[m].y-k*P[p].x+k*P[m].x;
        double tmpk=P[q].y-P[m].y-k*P[q].x+k*P[m].x;
        if(tmpi*tmpk<0) wa++;
        double abstmp=tmpi*tmpk>0?tmpi*tmpk:-tmpi*tmpk;
        if(abstmp<esp) return -1;
    }
    return 0;
}
