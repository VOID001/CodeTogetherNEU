/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月13日 星期六 19时50分25秒
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
#include<cmath>
#include<set>
using namespace std;

const double g=9.8;

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double v0,H;
		scanf("%lf%lf",&H,&v0);
		double res=sqrt(2)*v0/2*((sqrt(2*g*H+0.5*v0*v0)+sqrt(2)*v0/2)/g);
		printf("%.2lf\n",res);
	}
}
