/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月26日 星期日 19时00分57秒
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

const int maxn=200;
int nums[maxn];

bool cmp(int a,int b)
{
	return a>b;
}

int main(void)
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		MEMSET0(nums);
		int tmp;
		FORi(0,N)
		{
			scanf("%d",&tmp);
			nums[tmp]++;
		}
		int k;
		scanf("%d",&k);
		sort(nums,nums+maxn,cmp);
		int cnt=0;
		while(k)
		{
			if(nums[cnt] == 0) break;
			if(nums[cnt]>1)
			{
				k--;
				nums[cnt]--;
			}
			else
			{
				cnt++;
			}
		}
		int tot=0;
		FORi(0,maxn)
		{
			if(nums[i]) tot++;
		}
		tot-=k;
		printf("%d\n",tot);
	}
	return 0;
}
