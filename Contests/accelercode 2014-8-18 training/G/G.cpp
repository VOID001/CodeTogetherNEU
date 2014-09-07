#include <iostream>
#include <algorithm>
#include<cstdio>
using namespace std;
#define maxn 52
#define INF 1e30
struct Point
{
    double x,y;
}p[maxn];
Point ans[maxn];
int n,res[maxn],top;
bool cmpn(const Point &a,const Point &b)
{
    if(a.y==b.y) return  a.x<b.x;
    return a.y<b.y;
}
bool mult(const Point sp,const Point ep,const Point op)
{
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool anscmp(const Point &a,const Point &b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}
void Graham(){
    int i,len;
    top=1;
    sort(p,p+n,cmpn);
    if(n==0) return ;res[0]=0;
    if(n==1) return ;res[1]=1;
    if(n==2) return ;res[2]=2;
    for(i=2;i<n;i++)
    {
        while(top&&mult(p[i],p[res[top]],p[res[top-1]])) top--;
        res[++top]=i;
    }
    len=top;
    res[++top]=n-2;
    for(i=n-3;i>=0;i--)
    {
        while(top-len&&mult(p[i],p[res[top]],p[res[top-1]])) top--;
        res[++top]=i;
    }
}
int main()
{
    int P;
    scanf("%d",&P);
    while(P--)
    {
        int index;
        scanf("%d%d",&index,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        Graham();
        int s,i;
        for(s=0;s<=top;s++)
            if(!p[res[s]].x&&!p[res[s]].y) break;
        int ii=0;
        int ansnum=0;
        double maxy=-INF;
        double minx=INF;
        for(i=s;i<top;i++)
        {
               printf("(%.lf,%.lf)\n",p[res[i]].x,p[res[i]].y);
               ans[ii].x=p[res[i]].x;
               ans[ii].y=p[res[i]].y;
               if(ans[ii].y>maxy)
               {
                   ansnum=ii;
                   maxy=ans[ii].y;
                   minx=ans[ii].x;
               }
               else if(ans[ii].y==maxy&&ans[ii].x<minx)
               {
                   ansnum=ii;
                   minx=ans[ii].x;
               }
               ii++;
        }
        for(i=0;i<s;i++)
        {
               //printf("(%.lf,%.lf)\n",p[res[i]].x,p[res[i]].y);
               if(i<s-1)
               {
                    ans[ii].x=p[res[i]].x;
                    ans[ii].y=p[res[i]].y;
                    if(ans[ii].y>maxy)
                    {
                        ansnum=ii;
                        maxy=ans[ii].y;
                        minx=ans[ii].x;
                    }
                    else if(ans[ii].y==maxy&&ans[ii].x<minx)
                    {
                        ansnum=ii;
                        minx=ans[ii].x;
                    }
                    ii++;
               }
        }
        //sort(ans,ans+ii,anscmp);
		printf("%d %d\n",index,ii);
        for(int k=ansnum;k>=0;k--)
        {
            printf("%.lf %.lf\n",ans[k].x,ans[k].y);
        }
        for(int k=ii-1;k>ansnum;k--)
        {
            printf("%.lf %.lf\n",ans[k].x,ans[k].y);
        }
    }
    return 0;
}
