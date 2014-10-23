#include<stdio.h>
int main()
{
    int t;
    long long x1,x2,x3,x4,y1,y2,y3,y4,sum;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&x3,&y3,&x2,&y2,&x4,&y4);
        int k;
        if(x1>x2)
        {
            k=x1;
            x1=x2;
            x2=k;
        }
        if(y1>y2)
        {
            k=y1;
            y1=y2;
            y2=k;
        }
        if(x3>x4)
        {
            k=x3;
            x3=x4;
            x4=k;
        }
        if(y3>y4)
        {
            k=y3;
            y3=y4;
            y4=k;
        }
        sum=(x2-x1)*(y2-y1)+(x4-x3)*(y4-y3);
        long long dx,dy;
        if(x3>=x2||y3>=y2)
        {
            dx=0;
            dy=0;
        }
        else
        {
            if(x3<x1)dx=-x1;
            else dx=-x3;
            if(y3<y1)dy=-y1;
            else dy=-y3;
            if(x4<x2)dx=dx+x4;
            else dx=dx+x2;
            if(y4<y2)dy=dy+y4;
            else dy=dy+y2;
        }
        sum=sum-dx*dy;
        printf("%lld\n",sum);
    }
}
