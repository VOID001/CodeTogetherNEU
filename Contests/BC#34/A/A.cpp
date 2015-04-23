/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月21日 星期六 19时02分39秒
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
const int maxn=150;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int main(void)
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int a,b;
		int minn=99999;
		FORi(0,m)
		{
			scanf("%d%d",&a,&b);
			int tmp=n>=a?(n/a*b):b;
			if(n%a && n>=a) tmp+=b;
			if(tmp<minn) minn=tmp;
		}
		printf("%d\n",minn);
	}
	return 0;
}
