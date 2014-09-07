/*************************************************************************
  > File Name: ../B/B.cpp
  > Author: VOID_133
  > QQ: 393952764
  > Mail: zhangjianqiu13@gmail.com
  > Created Time: 2014年08月23日 星期六 14时47分03秒
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


int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}


int score[13][13];
//int seq[12]

bool chose [12];


int pass=0;
int N,M;
int interest=0;
int maxn;


int fac(int n)
{
	int res=1;
	for(int i=1;i<=n;i++)
		res=res*i;
	return res;
}


void dfs(int now)
{
	if(interest>=M) {pass+=fac(N-now);	
	return ;}
	if(interest+(N-now)*maxn<M) return ;

	for(int i=0;i<N;i++)
	{
		if(!chose[i]) 
		{
			interest+=score[now+1][i+1];
			chose[i]=1;
			dfs(now+1);
			chose[i]=0;
			interest-=score[now+1][i+1];
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		pass=0;
        int condi;
		memset(chose,0,sizeof(chose));
		maxn=-1000;
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
			{
				scanf("%d",&score[i][j]);
				maxn=max(maxn,score[i][j]);
			}
		dfs(0);
		condi=fac(N);
		if(pass==0)
		{
			printf("No solution\n");
		}
		else
		{
			int mod=gcd(condi,pass);
			printf("%d/%d\n",condi/mod,pass/mod);
		}
	}
	return 0;
}
