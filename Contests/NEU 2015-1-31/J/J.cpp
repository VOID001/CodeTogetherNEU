/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年01月31日 星期六 12时25分52秒
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
const LL maxn=1000000;
bool isp[maxn];
LL prime[300000];
void gen_prime()
{
	memset(isp,1,sizeof(isp));
	isp[0]=0;
	isp[1]=0;
	isp[2]=1;
	int t=2;
	prime[1]=2;
	for(LL i=4;i<=maxn;i+=2) isp[i]=0;
	for(LL i=3;i<maxn;i+=2)
	{
		if(isp[i])
		{
			prime[t++]=i;
			for(LL j=i+i;j<=maxn;j+=i)
				isp[j]=0;
		}
	}
	return ;
}

int main(void)
{
	gen_prime();
	LL N;
	while(scanf("%lld",&N)!=EOF)
	{
		LL i=0;
		for(i=1;i<=maxn;i++)
		{
			if(N<prime[i]) break;
		}
		printf("%lld\n",i-1);
	}
}
