#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long LL;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        int i;
        int sum=0;
        for(i=l;i<=r;i++)
        {
            sum+=n/i;
        }
        printf("%d\n",sum);
    }
    return 0;
}
