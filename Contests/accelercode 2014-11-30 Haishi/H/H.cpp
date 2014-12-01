/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月30日 星期日 12时39分46秒
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

LL n;

int main(void)
{
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",(n+3)*(n+2)*(n+1)*n/6);
	}
	return 0;
}
