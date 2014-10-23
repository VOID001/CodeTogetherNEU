#include<stdio.h>
#include<string.h>
#include<math.h>

const double esp=1e-9;

double dab(double a)
{
    return a-esp>0?a:-a;
}

bool in(double x)
{
    if((x>0||dab(x-0)<esp) && (x<100||dab(x-100)<esp)) return 1;
    else return 0;
}

int main(void)
{
    double x1,y1,x2,y2;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        if(dab(x1-x2)<esp && in(x1))
        {
            printf("100.00\n");
        }
        else if(dab(y1-y2)<esp && in(y2))
        {
            printf("100.00\n");
        }
        else
        {
            double k=(y1-y2)/(x1-x2);
            double x0=(k*x1-y1)/k;
            double x100=(100+k*x1-y1)/k;
            double y0=y1-k*x1;
            double y100=y1+100*k-k*x1;
            double dist=0;
            if(in(x0) && in(x100))
            {
                dist=sqrt((x100-x0)*(x100-x0)+100*100);
            }
            else if(in(y0) && in(y100))
            {
                dist=sqrt((y100-y0)*(y100-y0)+100*100);
            }
            else if(in(x0) && in(y0))
            {
                dist=sqrt(x0*x0+y0*y0);
            }
            else if(in(x0)&& in (y100))
            {
                dist=sqrt((100-x0)*(100-x0)+(100-y0)*(100-y0));
            }
            else if(in(x100) && in(y0))
            {
                dist=sqrt((100-y0)*(100-y0)+x100*x100);
            }
            else if(in(x100) && in(y100))
            {
                dist=sqrt(x100*x100+(100-y100)*(100-y100));
            }
            else dist = 0;
            printf("%.2lf\n",dist);
        }
    }
    return 0;
}




