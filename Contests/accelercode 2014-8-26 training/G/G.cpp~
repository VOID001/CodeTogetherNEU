#include <iostream>
#include<cstdio>
#include<cmath>
#define maxn 10010
typedef long long LL;
using namespace std;
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        LL sum=0;
        for(int i=0;i<n;i++)
        {
            int p,q;
            scanf("%d%d",&p,&q);
            a[i]=p-q;
            sum+=a[i];
        }
        int ok=1;
        for(int i=0;i<n;i++)
        {
            if(2*a[i]>sum)
            {
                ok=0;
                break;
            }
        }
        if(sum%2==1) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
