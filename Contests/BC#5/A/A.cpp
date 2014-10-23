/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月17日 星期日 19时25分55秒
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

int getsum(LL a);

int main(void)
{
	int T;
	scanf("%d",&T);
	LL l,r;
	while(T--)
	{
		scanf("%lld%lld",&l,&r);
		LL t=l;
		while(t%11!=3)
		{
			t++;
		}
		LL i=t;
		for(i=t;i<=r;i+=11)
		{
			if(getsum(i)!=3) break;
		}
		if(i<=r) cout<<i<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}


int getsum(LL a)
{
	bool odd=1;
	int sumodd,sumeven;
	sumodd=sumeven=0;
	while(a)
	{
		int t=a%10;
		if(odd) sumeven+=t;
		else sumodd+=t;
		odd=!odd;
		a/=10;
	}
	return sumeven-sumodd;
}
