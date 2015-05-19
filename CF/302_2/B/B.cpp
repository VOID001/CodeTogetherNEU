/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Mon May 18 15:54:44 2015
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

int mapp[maxn][maxn];

int main(void)
{
	int n,k;
	int maxk;
	int cnt=0;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		MEMSET0(mapp);
		cnt=0;
		if(n%2) maxk=(n*n)/2+1;
		else maxk=(n*n)/2;
		if(k>maxk) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				for(int j=(i%2)?1:0;j<n;j+=2)
				{
					if (cnt == k) break;
					mapp[i][j] = 1;
					cnt ++;
				}
				if(cnt == k ) break;
			}
			FORi(0,n)
			{
				FORj(0,n)
				{
					printf("%c",(mapp[i][j] == 1)?'L':'S');
				}
				printf("\n");
			}
		}
	}

	return 0;
}
