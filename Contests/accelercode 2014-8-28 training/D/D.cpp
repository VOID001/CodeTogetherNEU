/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月28日 星期四 14时38分11秒
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

int a[330*330*30];

#include <math.h>
#define E 0.57721566490153286060651209
int main()
{
	double a,x;
	while (scanf("%lf",&a) != EOF)
	{

		x = E;
		x *= pow(2,a) - 1;
		printf("%1.12e\n",x);
	}
	return 0 ;
}
