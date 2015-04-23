/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月20日 星期一 11时58分08秒
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
using namespace std;
const double eps = 1e-9;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int main(void)
{
	int x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4;
	int T;
	scanf("%d",&T);
	for(int I=1;I<=T;I++)
	{
		bool ok=true;
		scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4);
		int a[10],b[10],c[10];
		a[1]=x1-x2;
		b[1]=y1-y2;
		c[1]=z1-z2;
		a[2]=x1-x3;
		b[2]=y1-y3;
		c[2]=z1-z3;
		a[3]=x1-x4;
		b[3]=y1-y4;
		c[3]=z1-z4;
		a[4]=x3-x2;
		b[4]=y3-y2;
		c[4]=z3-z2;
		a[5]=x4-x2;
		b[5]=y4-y2;
		c[5]=z4-z2;
		a[6]=x4-x3;
		b[6]=y4-y3;
		c[6]=z4-z3;
		int para=1;
		for(int i=1;i<=6;i++)
		{
			for(int j=1;j<=6;j++)
			{
				if( i == j ) continue;
				para*=((a[i]*b[j]-a[j]*b[i])+(a[i]*c[j]-a[j]*c[i])+(b[i]*c[j]-b[j]*c[i]));
			}
		}
		int cnt=0;
		if(para == 0)
		{
			for(int i=1;i<=6;i++)
			{
				for(int j=1;j<=6;j++)
				{
					if(i == j) continue;
					if(a[i]*a[j]+b[i]*b[j]+c[i]*c[j] == 0) cnt++;
				}
			}
			if(cnt == 10) ok =true;
			else ok = false;
		}
		else
			ok=false;

		printf("Case #%d: %s\n",I,ok?"Yes":"No");
	}
}
