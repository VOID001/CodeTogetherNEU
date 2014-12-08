#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct team
{
    char str[35];
    int pri;
};
team T[505];
struct people
{
    char name[35];
    char belongteam[35];
    char sex;
    double pts;
};
people P[505];
int isprime[10005],prokind[10005];
int takrace[1005];
bool cmp(const people &a,const people &b)
{
    if(a.pts==b.pts)return strcmp(a.name,b.name)<0;
    return a.pts>b.pts;
}
int main()
{
    memset(isprime,-1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(int i=2;i<10000;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<10000;j=j+i)
            {
                isprime[j]=0;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int pid;
        memset(prokind,0,sizeof(prokind));
        int n,m;
        scanf("%d%d",&n,&m);
        int r,s;
        scanf("%d",&r);
        for(int i=1;i<=r;i++)
        {
            scanf("%d",&pid);
            prokind[pid]=1;
        }
        scanf("%d",&s);
        for(int i=1;i<=s;i++)
        {
            scanf("%d",&pid);
            prokind[pid]=2;
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%s%d",T[i].str,&T[i].pri);
        }
        int solp,takr;
        for(int i=0;i<n;i++)
        {
            P[i].pts=0.0;
            scanf("%s%s%c%d%d",P[i].name,P[i].belongteam,&P[i].sex,&solp,&takr);
            if(P[i].sex=='F')P[i].pts+=33;
            for(int j=0;j<q;j++)
            {
                if(!(strcmp(P[i].belongteam,T[j].str)))
                {
                    if(T[j].pri==1)P[i].pts+=36;
                    else if(T[j].pri==2)P[i].pts+=27;
                    else if(T[j].pri==3)P[i].pts+=18;
                    break;
                }
            }
            for(int j=1;j<=solp;j++)
            {
                scanf("%d",&pid);
                if(isprime[pid])P[i].pts+=1;
                if(prokind[pid]==1)P[i].pts+=2.5;
                else if(prokind[pid]==2)P[i].pts+=1.5;
                else if(!isprime[pid])P[i].pts+=0.3;
            }
            for(int j=0;j<takr;j++)
            {
                scanf("%d",&takrace[j]);
            }
            sort(takrace,takrace+takr);
            if(takr>=3&&takrace[takr-3]>1200)P[i].pts+=1.5*(takrace[takr-3]);
        }
        sort(P,P+n,cmp);
        for(int i=0;i<m;i++)
        {
            printf("%s %.3lf\n",P[i].name,P[i].pts);
        }
    }
    return 0;
}
