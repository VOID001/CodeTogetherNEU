/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月23日 星期四 11时15分31秒
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
const int maxn=100005;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int x[maxn];
int n,k;
long long cnt;

int abs_(int x)
{
	return x>0?x:-x;
}	

long long C2(int a)
{
	return (a-1)*a/2;
}

int myfind(int i)
{
	int l=i+1;
	int r=n-1;
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
	//	printf("l=%d r=%d\n",l,r);
		if(x[mid]-x[i]<=k && x[mid+1]-x[i]>k) return mid;
		else if(x[mid]-x[i]<=k && mid == n-1) return mid;

		if(x[mid]-x[i]>k) r=mid-1;
		else if(x[mid]-x[i]<=k) l=mid+1;
	}
	return -1;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		MEMSET0(x);
		scanf("%d%d",&n,&k);
		FORi(0,n)
		{
			scanf("%d",x+i);
		}
		cnt=0;
		sort(x,x+n);
		if(x[n-1]-x[0]<=k) cnt+=C2(n);
		else
		{
			int index=0;
			int ap=0;
			FORi(0,n-1)
			{
				if(ap<=i) ap=i;
				index=myfind(i);
				if(index == -1) continue;
				else
				{
					cnt+=C2(index-i+1)-C2(ap-i+1);
					ap=index;
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}


/*
 *
 * 利用二分简化时间复杂度，注意二分的写法，以及对数太多的时候，需要LONGLONG
 *
 */
