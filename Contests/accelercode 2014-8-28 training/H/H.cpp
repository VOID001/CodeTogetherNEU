/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月28日 星期四 12时35分49秒
 ************************************************************************/
#include<iostream>
#include<cmath>
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

typedef long long LL;

LL a,b;

double f(LL i)
{
	double w;
	double all;
	LL k;
	if(i==-1) return 0;
	if(i==0) return 1;
	if(i==1)  return 1;
	k=(LL)(sqrt(i)+1);
	//if((int)(kk*kk)!=i) 
	//{

	//	k=kk+1;
	//}
	//else
	//{
	//	k=kk;
	//}
	//printf("k=%d  ",k);
	if(k%2)
	{
		w=2*(k-2)-1;
		all=(w+1)/2*(w+3)/4;
		all+=(i+1)-(k-1)*(k-1)-1;
		//printf("all=%lf\n",all);
		return all;
	}
	else
	{
		w=2*(k-1)-1;
		all=(w+1)/2*(w+3)/4;
		//printf("all=%lf\n",all);
		return all;
	}
}

int main(void)
{
	LL a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		//	if(b==0)
		//	{
		//		printf("1\n");
		//	}
		//	else if(a==0)
		//	{
		//		printf("%lld\n",f(b)-f(a)+1);
		//	}
		//	else
		printf("%.0lf\n",f(b)-f(a-1));
	}
	return 0;
}
