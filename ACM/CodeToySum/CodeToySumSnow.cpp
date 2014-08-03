#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s 1000000
int b[1000010];
int a[500010];
int c[500010];
int main()
{
    int n,i,k,mark,t;
    while(scanf("%d",&n)!=EOF)
    {
        memset(b,1,sizeof(b));
        mark=-1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            k=a[i];
            b[k]=0;
        }
        printf("%d\n",n);
        t=1;
        for(i=0;i<n;i++)
        {
            if(b[a[i]])continue;
            k=s+1-a[i];
            if(b[k])
            {
                c[++mark]=k;
                if(mark==n-1)break;
            }
            else
            {
                b[k]=1;
                for(;;t++)
                {
                    if(!b[t])continue;
                    k=s+1-t;
                    if(!b[k])continue;
                    c[++mark]=t;
                    c[++mark]=k;
                    if(mark==n-1)break;
                    b[t]=0;
                    b[k]=0;
                    break;
                }
            }
            if(mark==n-1)break;
        }
        for(i=0;i<n;i++)
        {
            printf("%d",c[i]);
            if(i!=n-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
//看过你的发现自己白痴了，直接输出就好了，我居然存到了数组里。。。
