/*************************************************************************
    > File Name: D.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月12日 星期日 15时56分46秒
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
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

typedef long long LL;

LL gcd(LL x,LL y)
{
	return (y>0)?gcd(y,x%y):x;
}

int main(void)
{
	int A,B;
	while(scanf("%d%d",&A,&B)!=EOF)
	{
		int N;
		scanf("%d",&N);
		int res=gcd(A,B);
		while(N--)
		{
			int L,R;
			scanf("%d%d",&L,&R);
		}
	}
}
