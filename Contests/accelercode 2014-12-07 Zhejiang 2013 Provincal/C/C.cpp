/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月20日 星期六 13时12分59秒
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

const LL maxn=16000000;
LL p[maxn];
bool prime[maxn];

void genPrime()
{
	prime[0]=0;
	prime[2]=1;
	memset(prime,true,sizeof(prime));
	//int count=0;						//Here is a big mistake!
	int count=1;						
	for(int i=2;i<maxn;i++)
	{
		if(prime[i])
		{
			p[count++]=i;	
			for(int j=i+i;j<maxn;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	
	p[1]=3;
	p[2]=4;
	//p[k] Store the index of the k th Prime S in Fibonacci Series
	//Example:
	//p[1]=3 means the index of the first Prime S (which is 2) in Fibonacci Series is 3 
	// VERY IMPORTANT!!!
	return ;
}

typedef struct 
{
	LL m[2][2];
}Matrix;

Matrix multi(Matrix a,Matrix b,LL MOD)
{
	Matrix c;
	LL i,j;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c.m[i][j]=0;
			for(int k=0;k<2;k++)
			{
				c.m[i][j]+=a.m[i][k]*b.m[k][j];
				c.m[i][j]%=MOD;						//Use MOD to make the number smaller
			}
		}
	}
	return c;
}

Matrix per={1,0,0,1};
Matrix samp={1,1,1,0};

Matrix matrixQuickPow(LL k,LL MOD)
{
	Matrix ans=per;
	Matrix p=samp;
	while(k)
	{
		if(k&1)
		{
			ans=multi(ans,p,MOD);
			k--;
		}
		p=multi(p,p,MOD);
		k>>=1;
	}
	return ans;
}

int main(void)
{
	LL X,M,K;
	genPrime();
	int T;
	scanf("%d",&T);
	LL mem;
	while(T--)
	{
		scanf("%lld%lld%lld",&K,&X,&M);
		Matrix ans;
		for(LL i=p[K];;i++)
		{
			ans=matrixQuickPow(i-1,X);
			if(ans.m[0][0]%X==0)
			{
				mem=i;
				break;
			}
		}
		ans=matrixQuickPow(mem-1,X*M);
		LL res=ans.m[0][0]/X;
		printf("%lld\n",res);
	}
	return 0;
}
