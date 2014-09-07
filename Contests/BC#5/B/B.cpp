/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月17日 星期日 19时53分34秒
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

const int maxn=50;

typedef struct{
	int vol;
	int leak;
}Bucket;


bool cmp(const Bucket& a,const Bucket& b)
{
	//if(a.leak!=b.leak)
	//	return a.leak<b.leak;
	//return a.vol>b.vol;
	return a.leak*b.vol<a.vol*b.leak;
}

Bucket buk[maxn];
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,v;
		scanf("%d%d",&n,&v);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&buk[i].leak);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&buk[i].vol);
		}	
		sort(buk,buk+n,cmp);
		bool ok=1;
		double time=0;
		for(int i=n-1;i>=0;i--)
		{
			if(buk[i].vol==0) continue;
			if(buk[i].leak>=v) {ok=0;break;}
			else
			{
				time+=(time*buk[i].leak+buk[i].vol)*1.0/(v-buk[i].leak);
			}
		}
		if(ok)
			printf("%lf\n",time);
		else 
			printf("-1\n");

	}
	return 0;
}
