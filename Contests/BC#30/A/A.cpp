/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月25日 星期六 22时19分55秒
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
const int maxn=105;
typedef long long LL;
const LL INTMAX =2147483647;

LL users[maxn];
LL val[maxn];
LL arr[maxn];

int main(void)
{
	int N;
	int kase=1;
	while(scanf("%d",&N)!=EOF)
	{
		MEMSET0(users);
		MEMSET0(val);
		FORi(0,N)
		{
			scanf("%lld",arr+i);
		}
		sort(arr,arr+N);
		int pre=arr[0];
		int now=arr[0];
		int cntval=0;
		int cntusers=0;
		val[0]=arr[0];
		users[0]=1;
		FORi(1,N)
		{
			pre=now;
			now=arr[i];
			if(pre == now)
			{
				users[cntusers]++;
			}
			else
			{
				cntusers++;
				users[cntusers]++;
				cntval++;
				val[cntval]=arr[i];
			}
		}
		cntval++;
		cntusers++;
		//FORi(0,cntval)
		//{
		//	printf("%lld ",val[i]);
		//}
		//printf("\n");
		//FORi(0,cntusers)
		//{
		//	printf("%lld ",users[i]);
		//}
		//printf("\n");
		//printf("cntVAL=%d\n",cntval);
		int kiss=0;
		FORi(1,cntval)
		{
			if((val[i]+val[i-1])%INTMAX == val[(i+1)%cntval]) 
			{
				//printf("No %d Satisfy (%lld+%lld)%%INTMAX == %lld\n",i,val[(i+cntval)%cntval],val[(i+cntval-1)%cntval],val[(i+1+cntval)%cntval]);
				kiss+=users[i];
			}
		}
		if(cntval==1)
		{
			kiss=-1;
		}
		else
		{
			if((val[0]+val[cntval-1])%INTMAX == val[1])
				kiss+=users[0];
		}
		printf("Case #%d: %d\n",kase++,kiss);
	}
	return 0;
}
