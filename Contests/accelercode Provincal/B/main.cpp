#include<stdio.h>

int main(void)
{
    int a[6]={11,111,1111,11111,111111,1111111};
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        int  ok=1,cnt=0;
        for(int k=0;k<6;k++)
        {
            if(k==5)
            {
                if(a[k]<2*x||a[k]>2*y)break;
                if(x+y<a[k])cnt+=(2*y-a[k])/2+1;
                else cnt+=(a[k]-2*x)/2+1;
            }
            else
            {
                for(int i=1;i<=9;i++)
                {
                    if(i*a[k]< 2*x)continue;
                    if(i*a[k]>2*y)
                    {
                        ok=0;
                        break;

                    }
                    if(x+y<i*a[k])cnt+=(2*y-i*a[k])/2+1;
                    else cnt+=(i*a[k]-2*x)/2+1;
                }
            }
            if(ok==0)break;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
