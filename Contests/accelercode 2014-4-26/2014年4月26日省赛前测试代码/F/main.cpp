#include<stdio.h>

int main(void)
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int t;
        int num=0;
        int flaga=1;
        while(b)
        {
            t=a/b;
            if(flaga==1 && t== 1 ) num++;
            else
            {
                flaga=0;
                break;
            }
            int tt;
            tt=a;
            a=b;
            b=tt%b;
        }
        if(flaga==1)
        {
            if(num%2) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            if(num%2) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}
