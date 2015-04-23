/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月12日 星期日 13时06分06秒
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
const int maxn=100001;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int n,K,M;
double day[maxn];
double fast[maxn];
double slow[maxn];



int main(void)
{
	while(scanf("%d%d%d",&n,&K,&M)!=EOF)
	{
		double sum=0;
		double sumb=0;
		FORi(0,n)
		{
			scanf("%lf",day+i);
			sum+=day[i];
			sumb+=day[i];
			if(i >= K-1)
			{
				fast[i]=sum/K;
				sum-=day[i+1-K];
			}
			if(i >= M-1)
			{
				slow[i]=sumb/M;
				sumb-=day[i+1-M];
			}
		}
		bool nowst=0;
		bool prest=0;
		FORi(0,M)
		{
			if(i!=0) printf(" ");
			printf("silent");
		}
		if(slow[M-1]>fast[M-1]) nowst=0;
		if(slow[M-1]<fast[M-1]) nowst=1;
		FORi(M,n)
		{
			prest=nowst;
			if(fast[i]>slow[i]) nowst=1;
			else if(slow[i]>fast[i]) nowst=0;
			if(prest!=nowst)
			{
				if(prest == 1)
					printf(" sell");
				else
					printf(" buy");
			}
			else
			{
				printf(" silent");
			}
		}
		printf("\n");
	}
	return 0;
}


