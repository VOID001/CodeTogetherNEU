/*************************************************************************
    > File Name: 1425.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月29日 星期六 09时26分25秒
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

const int maxn=1000001;						//-500000->0;
int arrhash[maxn];

int main(void)
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int a;
		memset(arrhash,0,sizeof(arrhash));
		while(n--)
		{
			scanf("%d",&a);
			arrhash[a+500000]++;
		}
		for(int i=1000000;i>=0 && m;i--)
		{
			if(arrhash[i])
			{
				if(m!=1)
				{
					printf("%d ",i-500000);
				}
				else
				{
					printf("%d\n",i-500000);
				}
				m--;
			}
		}
	}
	return 0;
}
