#include<stdio.h>
#include<string.h>
#define MAX 1000001
typedef long long LL;
bool isp[MAX];
int prime[300000];
void is_prime()
{
    memset(isp,1,sizeof(isp));
    isp[0]=isp[1]=0;
    prime[1]=2;
    int cnt=2;
    for(LL oo=2;oo<=MAX;oo++) isp[oo]=oo%2;
    for(LL oo=3;oo<=MAX;oo+=2)
    {
        if(isp[oo])
        {
            prime[cnt++]=oo;
            for(LL t=oo*oo;t<=MAX;t+=oo) isp[t]=0;
        }
    }
    return ;
}
int main()
{
    int ans,n;
    is_prime();
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        int i=1;
        while(n!=1)
        {
            if(n%prime[i]==0)
            {
                ans++;
                while(n%prime[i]==0)n=n/prime[i];
            }
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


