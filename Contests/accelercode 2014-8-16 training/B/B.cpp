/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月16日 星期六 16时13分00秒
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

struct Edge
{
	int start;
	int end;
};

bool cmp


Edge earr[1000001];


int main(void)
{
	int N;
	int K,A,B;
	while(scanf("%d%d%d%d",&N,&K,&A,&B)!=EOF)
	{
		for(int i=0;i<2*K;i+=2)
		{
			scanf("%d%d",&earr[i].start,&earr[i].end);
			earr[i+1].start=earr[i].end;
			earr[i+1].end=earr[i].start;
		}
		sort(earr,earr+2*K,cmparr);
	}
}
