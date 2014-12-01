/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月30日 星期日 12时05分56秒
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

LL sum=0;
LL a;

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		bool ok=0;
		bool ultrano=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&a);
			if(a==0){ok=1;}
			if(a%4!=0) ultrano=1;
		}
		printf("Case #%d: ",i);
		if(!ultrano || ok)
		{
			printf("Nobita\n");
		}
		else if(ultrano)
			printf("hsh\n");
	}
	return 0;
}
