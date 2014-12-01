/*************************************************************************
    > File Name: L.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月30日 星期日 16时37分56秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;

const double esp=1e-9;

typedef struct line
{
	double a;
	double b;
}Line;

bool cmp (Line a,Line b)
{
	if(a.a!=b.a)
		return a.a<b.a;
	else
		return a.b>b.b;
}

int main(void)
{
	double w,L;
	int n;
	Line l[10001];
	double xi,ri;
	while(scanf("%d%lf%lf",&n,&L,&w)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&xi,&ri);
			double deltax=(ri-0.5*w)*sqrt(3)/4;
			l[i].a=max(0.0,xi-deltax);
			l[i].b=min(L,xi+deltax);
		}
		sort(l,l+n,cmp);
		int cnt=0;
		double pre=0;
		for(int i=0;i<n && pre<L ;i++)
		{
			if(l[i].a>pre)
			{
				break;
			}
			else
			{
				//printf("%lf\n",pre);
				int j=i;
				double maxleng=0;
				while(l[i].a<=pre && i<n)
				{
					if(l[i].b>maxleng)
					{
						maxleng=l[i].b;
						j=i;
					}
					i++;
				}
				i--;
				pre=l[j].b;
				cnt++;		
			}
		}
		//printf("%lf\n",pre);
		if(pre-L > -esp && pre-L < esp) 
			printf("%d\n",cnt);
		else
			printf("-1\n");
	}
	return 0;
}
