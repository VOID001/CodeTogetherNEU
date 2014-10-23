/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月16日 星期六 15时43分51秒
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

typedef long long LL;

int main()
{
	LL n;
	while(scanf("%lld",&n)!=EOF)
	{
		if((n*n-1)%3==0)printf("1\n");
		else printf("0\n");
	}
	return 0;
}

