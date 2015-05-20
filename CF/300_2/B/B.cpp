/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Tue May 19 18:44:55 2015
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
const int maxn=10;

int digi[maxn];
int eledigi[maxn];
std::vector<int> V;

int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(digi,0,sizeof(digi));
		memset(eledigi,0,sizeof(eledigi));
		V.clear();
		while(n)
		{
			int tmp=n;
			int cnt=0;
			while(n)
			{
				digi[cnt++]=n%10;
				n/=10;
			}
			//printf("DIGITS\n");
			n = tmp;
			//for(int i=0;i<cnt;i++)
			//	printf("%d ",digi[i]);
			//printf("\nEND DIGITS\n");
			for(int i=0;i<cnt;i++)
			{
				if(digi[i] >= 1)
				{
					eledigi[i]=1;
				}
				else
				{
					eledigi[i]=0;
				}
			}
		//	printf("ELEDIGITS\n");
		//	for(int i=0;i<cnt;i++)
		//		printf("%d ",eledigi[i]);  
		//	printf("\nEND ELEDIGITS\n");
		//	printf("%d\n",cnt);
			int subele=0;
			for(int i=cnt-1;i>=0;i--)
			{
				subele=subele*10+eledigi[i];
			}
//			printf("n=%d subele=%d\n",n,subele);
			n-=subele;
			V.push_back(subele);
		}
		printf("%d\n",V.size());
		for(int i=0;i<V.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%d",V[i]);
		}
		printf("\n");
	}
	return 0;
}
