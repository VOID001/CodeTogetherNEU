#include<stdio.h>
#include<string.h>
#include<math.h>
const double esp=1e-9;
int flaga,flagb,flagc;


double dab(double x)
{
    return x>0?x:-x;
}

double s(double x1,double y1,double x2,double y2,double x0,double y0)
{
    return dab(x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0)/2;
}

int linexx(double x0,double y0,double r,double k,double b,double x1,double y1,double x2,double y2,double d)
{
    double res1,res2;

    if(dab(x1-x2)<esp)
    {
        if(y1>y2) {double tmp=y2;y2=y1;y1=tmp;}
        if(d-r<0)
        {
            res1=y0+sqrt(r-(x1-x0)*(x1-x0));
            res2=y0-sqrt(r-(x1-x0)*(x1-x0));
            if(dab(res1-res2)<esp) return 0;
            //if(((res1 > y1 || dab(res1-y1)<esp )&& (res1 < y2 || dab(res2-y2)<esp ))||((res2 > y1 || dab(res2-y1)<esp )&& (res2 < y2 || dab(res2-y2)<esp ))) return 1;
            if(((res1 > y1 )&& (res1 < y2 ))||((res2 > y1  )&& (res2 < y2))) return 1;
            else return 0;
        }
        else return 0;
    }
    else
    {
        if(x1>x2) {double tmp=x2;x2=x1;x1=tmp;}
        if(d-r<0)
        {
        double delta=sqrt(4*(x0-k*b-k*y0)*(x0-k*b-k*y0)-4*(1+k*k)*(x0*x0+(b-y0)*(b-y0)-r));
        if(dab(delta-0)<esp) return 0;
        res1=(2*(x0-k*b-k*y0)+delta)/((2*(1+k*k)));
        res2=(2*(x0-k*b-k*y0)-delta)/((2*(1+k*k)));
        //if(((res1 > x1 || dab(res1-x1)<esp )&& (res1 < x2 || dab(res2-x2)<esp ))||((res2 > x1 || dab(res2-x1)<esp )&& (res2 < x2 || dab(res2-x2)<esp ))) return 1;
        if(((res1 > y1  )&& (res1 < y2  ))||((res2 > y1  )&& (res2 < y2  ))) return 1;
        else return 0;
        }
        else return 0;
    }
}

int pointii(double x0, double y0 ,double x,double y,double r )
{
    if(dab((x-x0)*(x-x0)+(y-y0)*(y-y0)-r)<esp || (x-x0)*(x-x0)+(y-y0)*(y-y0)-r<0 ) return 1;
    else return 0;
}

int main(void)
{
    double x1,y1,x2,y2,x3,y3,x0,y0,r;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        flaga=flagb=flagc=0;
        double d1,d2,d3;
        double k1,k2,k3;
        double b1,b2,b3;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x0,&y0,&r,&x1,&y1,&x2,&y2,&x3,&y3);
        r=r*r;
        if(dab(x1-x2)<esp) d1=dab(x0-x1);
        else
        {
            k1=(y1-y2)/(x1-x2);
            d1=(k1*(x0-x1)+y1-y0)*(k1*(x0-x1)+y1-y0)/(k1*k1+1);
            b1=y1-k1*x1;
        }
        if(dab(x1-x3)<esp) d1=dab(x0-x1);
        else
        {
            k2=(y1-y3)/(x1-x3);
            d2=(k2*(x0-x1)+y1-y0)*(k2*(x0-x1)+y1-y0)/(k2*k2+1);
            b2=y1-k2*x1;
        }
        if(dab(x3-x2)<esp) d1=dab(x0-x3);
        else
        {
            k3=(y3-y2)/(x3-x2);
            d3=(k3*(x0-x3)+y3-y0)*(k3*(x0-x3)+y3-y0)/(k3*k3+1);
            b3=y2-k3*x2;
        }
        if((d1>r || dab(d1-r)<esp) && (d2>r || dab(d2-r)<esp) && (d3>r || dab(d3-r)<esp) ) flaga=1; //三个
        if(dab(s(x1,y1,x2,y2,x0,y0)+s(x1,y1,x3,y3,x0,y0)+s(x2,y2,x3,y3,x0,y0)-s(x1,y1,x2,y2,x3,y3))<esp) flagb=1;
        if(pointii(x0,y0,x1,y1,r) && pointii(x0,y0,x2,y2,r) && pointii(x0,y0,x3,y3,r)) flagc=1;
        //printf("%d %d",flaga,flagb);
        printf("Case #%d: ",i);

        //flag1=linexx( x0,y0,r,k1,b1,x1,y1,x2,y2,d1);
        //flag2=linexx( x0,y0,r,k2,b2,x1,y1,x3,y3,d2);
        //flag3=linexx( x0,y0,r,k3,b3,x2,y2,x3,y3,d3);
        if(linexx( x0,y0,r,k1,b1,x1,y1,x2,y2,d1) || linexx( x0,y0,r,k2,b2,x1,y1,x3,y3,d2)||linexx( x0,y0,r,k3,b3,x2,y2,x3,y3,d3)) printf("XX\n");
        else if (flaga==1 && flagb==1) printf("II\n");
        else if (flagc==1) printf("II\n");
        else printf("OO\n");
    }
}

/**int linexx(double x0,double y0,double r,double k,double b,double x1,double y1,double x2,double y2,double d)**/
