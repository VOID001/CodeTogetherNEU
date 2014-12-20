/*************************************************************************
    > File Name: quick_pow.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月20日 星期六 12时23分36秒
	> Algorithm : Quick Power
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

LL quick_pow(LL a,LL b,LL mod)
{
	LL res=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;			
		}
		a=a*a%mod;	
		b>>=1;
	}
	return res;
}


int main(void)
{
	LL a,b,mod;
	scanf("%lld%lld%lld",&a,&b,&mod);
	printf("%lld\n",quick_pow(a,b,mod));

	return 0;
}
