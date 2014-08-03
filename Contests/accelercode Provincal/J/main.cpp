#include<stdio.h>
#include<algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}


int a[10010];
int main()
{
    int n,ok;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        ok=1;
        sort(a,a+n,cmp);
        if(a[0]>=n)
        {
            printf("NO\n");
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=i+a[i];j++)
            {
                if(a[i+a[i]]==0)
                {
                    ok=0;
                    break;
                }
                if(a[j]==a[i+a[i]])
                {
                    int k=i+a[i];
                    {
                        while(k!=n-1&&a[k+1==a[k]])k++;
                    }
                    a[k]--;
                }
                else a[j]--;
            }
            if(ok==0)break;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
