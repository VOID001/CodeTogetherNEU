/*************************************************************************
    > File Name: quick-pow.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月08日 星期五 16时04分41秒
 ************************************************************************/
#include<iostream>
using namespace std;

typedef long long LL;

LL quick_pow(LL  a,LL  b,LL  mod)
{
	a=a%mod;
	LL res=1;
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
	LL b,p,k;
	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<quick_pow(b,p,k);
	return 0;
}	
