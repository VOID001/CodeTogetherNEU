/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月23日 星期日 12时14分52秒
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

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		LL res;
	//	if(n%k!=0)
	//		res=(n%k)*(n/k+1)*(n-n%k)*(n/k)*k*(k-1)/2;
	//	else
	//		res=(n/k)*k*k
		res=(n-(n/k+1)*(n%k+1)+1)*(k-n%k)*(n/k)/2+(n-(n/k+1)+n-(n/k+1)*(n%k))*(n%k)*(n/k+1)/2;
		printf("%lld\n",res);
	}

	return 0;
}
