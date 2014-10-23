#include<stdio.h>
int main()
{
    //freopen("out","w",stdout);
    int T;
    scanf("%d",&T);
    int i;
    for(i=1;i<=T;i++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        int cnt=0;
        while(a>b)
        {
            //long long x=a/2+1;
            //a=a-a%x;
            a=a/2+1;
            cnt++;
            //printf("%lld\n",a);
        }
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}
