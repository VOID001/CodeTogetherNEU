#include<stdio.h>
int main(void)
{
    long long a,b;
    long long sub;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
            sub= b-a>=0?b-a:a-b;
            printf("%lld\n",sub);
    }
    return 0;
}
