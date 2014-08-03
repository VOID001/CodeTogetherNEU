#include<stdio.h>
#include<math.h>

#define MAX 10000
const int eps=1e-9;
int main(void)
{
    int abs(int a,int b);
    int x0,y0,r,x1,y1,x2,y2;
    int k;
    int count=0;
    int b;
    double dis;
    int tests[MAX];
    while(scanf("%d%d%d\n%d%d%d%d",&x0,&y0,&r,&x1,&y1,&x2,&y2)!=EOF)
    {
        if(x1!=x2)
        {
            k=((int)(y1-y2))/(x1-x2);
            b=y1-k*x1;
            dis=fabs((k*x0+b-y0)/(sqrt(k*k+1)));
            //printf("%lf  %lf",dis,int(r));
            if(dis==r)
            {
                tests[count]=1;
            }
            else if(dis<r)
            {
                tests[count]=2;
            }
            else
            {
                tests[count]=0;
            }
        }
        else if(x1==x2)
        {
            if(abs(x0,x1)<r) tests[count]=2;
            else if(abs(x0,x1)==r) tests[count]=1;
            else if(abs(x0,x1)>r) tests[count]=0;
        }
        count++;
    }
    for(int k=0;k<count;k++)
    {
        printf("%d",tests[k]);
        if(k<count-1) printf("\n");
    }
}

int abs(int a,int b)
{
    return a<=b?b-a:a-b;
}
