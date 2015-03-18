/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月14日 星期六 13时14分15秒
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

const int maxn=1005;
int descarr[maxn];
int main(void)
{
	descarr[1]=1;
	for(int i=2;i<=maxn;i++)
	{
		descarr[i]=descarr[i-1]+i-1;
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int aa;
		scanf("%d",&aa);
		printf("%d\n",descarr[aa]);
	}
	return 0;
}
