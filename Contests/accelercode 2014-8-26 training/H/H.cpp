/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月26日 星期二 12时14分34秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
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

typedef unsigned long long ULL;
typedef long long LL;
const int maxn=2642248;

ULL arr[maxn];

int main(void)
{
	for(ULL i=1;i<=maxn-2;i++)
	{
		arr[i]=i*i*i;
	}
		//printf("%llu",arr[maxn-3]);
	//Printtable
	
	int count=1;
	ULL a;
	while(scanf("%llu",&a)!=EOF)
	{
		int cnt=0;
		for(int i=1;i<=maxn;i++)
		{
			ULL rest=a-arr[i];
			if(arr[i]>rest) break;
			//printf("%llu # ",rest);
			for(int j=0;j<=maxn;j++)
			{
				//ULL restd=(unsigned long long )pow(rest,1.0/3);
				if(arr[j]>rest) break;
		//		printf("%d\n",j);
				if(rest==arr[j]) 
				{
					if(cnt==0) printf("%d ",count++);
					if(cnt!=0) printf(" ");
					printf("(%d,%d)",i,j);
					cnt++;
				}

			}
		}
		printf("\n");
	}
		return 0;
}
