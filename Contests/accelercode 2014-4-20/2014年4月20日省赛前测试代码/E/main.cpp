#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
//#define LOCAL
#define MAX 100001
using namespace std;
typedef struct zone
{
    double st,ed;
}zone;

//vector<zone> v;
zone Z[MAX];

bool cmp(zone a,zone b)
{
    if(a.ed!=b.ed)
    return a.ed<b.ed;
    else return a.st>b.st;
}

//double time_[100002][2];
int main()
{
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int T;
    scanf("%d",&T);
    int i;
    //zone zone_z;
    for(i=1;i<=T;i++)
    {
        //v.clear();
        memset(Z,0,sizeof(Z));
        int j,n,top=0;
        double r;
        scanf("%d%lf",&n,&r);
        double x,y,z,dx,dy,dz;
        for(j=1;j<=n;j++)
        {
            scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&dx,&dy,&dz);
            double a=dx*dx+dy*dy+dz*dz;
            double b=2*(x*dx+y*dy+z*dz);
            double c=x*x+y*y+z*z-r*r;
            double d=b*b-4*a*c;
            if(d<0)continue;
            double t2=(-b+sqrt(d))/(2*a);
            if(t2<0)continue;
            double t1=(-b-sqrt(d))/(2*a);
            if(t1<0)t1=0;
            Z[top].st=t1;
            Z[top].ed=t2;
            //zone_z.st=t1;
            //zone_z.ed=t2;
            //v.push_back(zone_z);
            top++;
        }
        sort(Z,Z+top,cmp);
        int cnt =0;
        double pre=-1;
        for(int ii=0;ii<top;ii++)
        {
            if(pre>=Z[ii].st && pre<=Z[ii].ed) continue;
            else
            {
                cnt++;
                pre=Z[ii].ed;
            }
        }
        /*sort(v.begin(),v.end(),cmp);
        int cnt=0;
        double  pre=-1;
        for(vector<zone>::iterator ii=v.begin();ii!=v.end();ii++)
        {
            if(pre>= (*ii).st && pre <= (*ii).ed) continue;
            else
            {
                cnt++;
                pre=(*ii).ed;
            }
        }*/
        printf("Case %d: %d %d\n",i,top,cnt);
    }
    return 0;
}
