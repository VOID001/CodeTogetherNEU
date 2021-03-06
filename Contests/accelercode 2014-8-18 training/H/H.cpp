#include <iostream>
#include <algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 52
#define INF 2147483645



struct Line
{
    int y;
    int x1,x2;
};
Line line[maxn];
struct Point
{
    int x,y;
}p[maxn];
Point ans[maxn];
Point edge[maxn][2];
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
int multi(const Point& p1,const Point& p2,const Point& p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int isInside(const Point& p,const Point edge[][2],int n)
{
    int i;
    int pre;
    int now;
    for(i=0;i<n;i++)
    {
        now=multi(p,edge[i][1],edge[i][0]);
        if(i>0)
        {
            if(pre*now<=0)
                return 0;
        }
        pre=now;
    }
    return 1;
}
int main()
{
    int P;
    scanf("%d",&P);
    while(P--)
    {
		memset(line,0,sizeof(line));
		memset(p,0,sizeof(p));
		memset(ans,0,sizeof(ans));
		memset(edge,0,sizeof(edge));
		memset(res,0,sizeof(res));
        int index;
        scanf("%d%d",&index,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        Graham();
        int s,i;
        for(s=0;s<=top;s++)
            if(!p[res[s]].x&&!p[res[s]].y) break;
        int ii=0;
        int maxx,maxy,minx,miny;
        maxx=maxy=-INF;
        minx=miny=INF;
        for(i=s;i<top;i++)
        {
               //printf("(%.lf,%.lf)\n",p[res[i]].x,p[res[i]].y);
               ans[ii].x=p[res[i]].x;
               ans[ii].y=p[res[i]].y;
               if(ans[ii].x>maxx) maxx=ans[ii].x;
               if(ans[ii].x<minx) minx=ans[ii].x;
               if(ans[ii].y>maxy) maxy=ans[ii].y;
               if(ans[ii].y<miny) miny=ans[ii].y;
               ii++;
        }
        for(i=0;i<s;i++)
        {
               //printf("(%.lf,%.lf)\n",p[res[i]].x,p[res[i]].y);
               //if(i<s-1)
               //{
                    ans[ii].x=p[res[i]].x;
                    ans[ii].y=p[res[i]].y;
                    if(ans[ii].x>maxx) maxx=ans[ii].x;
                    if(ans[ii].x<minx) minx=ans[ii].x;
                    if(ans[ii].y>maxy) maxy=ans[ii].y;
                    if(ans[ii].y<miny) miny=ans[ii].y;
                    ii++;
               //}
        }
		if(!(ans[ii-1].x==ans[0].x && ans[ii-1].y==ans[0].y)) ii++;
        for(int i=1;i<ii;i++)
        {
            edge[i-1][0].x=ans[i-1].x;edge[i-1][0].y=ans[i-1].y;
            edge[i-1][1].x=ans[i].x;edge[i-1][1].y=ans[i].y;
            //printf("(%d %d)\n",ans[i-1].x,ans[i-1].y);
        }
        
        for(int i=0;i<ii-1;i++)
        {
            //printf("(%d %d)-(%d %d)\n",edge[i][0].x,edge[i][0].y,edge[i][1].x,edge[i][1].y);
        }
        
        //printf("maxx %d maxy %d minx %d miny %d\n",maxx,maxy,minx,miny);
        int tmpi=0;
        for(int y=maxy;y>=miny;y--)
        {
            Point tmp;
            tmp.y=y;
            for(int x=minx;x<=maxx;x++)
            {
                tmp.x=x;
                if(isInside(tmp,edge,ii-1))
                {
                    line[tmpi].y=y;
                    line[tmpi].x1=x;
                    //printf("in graph x %d y %d\n",x,y);
                    break;
                }
                else continue;
            }
            for(int x=maxx;x>=minx;x--)
            {
                tmp.x=x;
                if(isInside(tmp,edge,ii-1))
                {
                    //printf("tmpi=%d x=%d\n",tmpi,x);
                    line[tmpi++].x2=x;
                    //printf("in graph x %d y %d\n",x,y);
                    break;
                }
                else continue;
            }
        }
        printf("%d %d\n",index,tmpi);
        for(int i=0;i<tmpi;i++)
        {
            printf("%d %d %d\n",line[i].y,line[i].x1,line[i].x2);
        }
    }
    return 0;
}

