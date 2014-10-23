/*************************************************************************
    > File Name: 1007.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月21日 星期日 12时14分39秒
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

int hash[101];
int preval;
bool s=0;
bool ook;

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		memset(hash,0,sizeof(hash));
		int N;
		s=0;
		ook=0;
		scanf("%d",&N);
		for(int j=0;j<N;j++)
		{
			int w;
			scanf("%d",&w);
			if(j==0) preval=w;
			if(j!=0 && w!=preval) s=1;
			hash[abs(w-100)]++;
		}
		int flag=0;
		int max=0;
		int typecnt=0;
		bool ok=0;
		for(int j=0;j<100;j++)
		{
			if(hash[j]!=max && hash[j]!=0)
			{
				if(flag==1) ok=1;				//Good
				if(max<hash[j])max=hash[j];
				if(flag==0) flag=1;
			}
		}
		printf("Case #%d:\n",i);
		bool spaceok=0;
		ook=s&&(!ok);
		ook=!ook;
		for(int j=99;j>=0 && ook;j--)
		{
			if(hash[j]==max)
			{
				if(spaceok) printf(" ");
				printf("%d",10000-j*j);
				spaceok=1;
			}
		}
		if(ook) printf("\n");
		if(!ook) printf("Bad Mushroom\n");
	}
	return 0;
}
