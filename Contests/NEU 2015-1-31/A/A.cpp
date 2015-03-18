/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年01月31日 星期六 12时03分27秒
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

const double eps=1e-9;

double x[15];
double y[15];
double z[15];

int main(void)
{
	int T;
	scanf("%d",&T);
	double money;
	while(T--)
	{
		for(int i=0;i<12;i++)
		{
			scanf("%lf",x+i);
		}
		for(int i=0;i<12;i++)
		{
			scanf("%lf",y+i);
		}
		for(int i=0;i<12;i++)
		{
			scanf("%lf",z+i);
		}
		scanf("%lf",&money);
		double tt=money;
		for(int i=0;i<12;i++)
		{
			double max=-10000;
			if(max<z[i]) max=z[i];
			if(max<y[i]) max=y[i];
			if(max<x[i]) max=x[i];
			if(max<0) continue;			//No Profit Do not invest
			money=money*(1+max*0.01);
		}
		printf("%.3lf\n",money-tt);
	}
	return 0;
}
