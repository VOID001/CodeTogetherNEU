/*************************************************************************
    > File Name: M.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月22日 星期日 12时31分13秒
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
const int maxn=1000;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int main(void)
{
	int T;
	double arr[maxn];
	scanf("%d",&T);
	FORi(0,T)
	{
		int n;
		scanf("%d",&n);
		FORj(0,n)
		{
			scanf("%lf",arr+j);
		}
		sort(arr,arr+n);
		if(n%2==0) printf("%.3lf\n",(arr[n/2-1]+arr[n/2])/2);
		else if(n!=1) printf("%.3lf\n",arr[n/2]);
		else if(n==1) printf("%.3lf\n",arr[0]);
	}
	return 0;
}
