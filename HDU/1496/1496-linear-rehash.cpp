/*************************************************************************
  > File Name: 1496-linear-rehash.cpp
  > Author: VOID_133
  > ################### 
  > Mail: ################### 
  > Created Time: 2014年12月16日 星期二 21时23分52秒
  > 线性探测再散列解决本题优化时间和空间
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

const int MOD=50021;				//设置模值

int hash[MOD];						//存储映射关系
int num[MOD];						//Store the num of this cnt;

int genhash(int n)
{
	int tmp=n%MOD;
	if(tmp<0) tmp+=MOD;
	//	else							//- - 迷之else  我是不是脑子发热了
	//	{
	while(hash[tmp]!=n && num[tmp]!=0)
	{
		tmp=(tmp+1)%MOD;
	}
	//	}
	return tmp;
}

//void printArray(int *A,int len)
//{
//
//}

int main(void)
{
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		//memset(hash,-1,sizeof(hash));
		memset(num,0,sizeof(num));
		if(a>0 && b>0 && c>0 && d>0 || a<0 && b<0 && c<0 && d<0 )
		{
			printf("0\n");
		}
		else
		{
			for(int i=1;i<=100;i++)
			{
				for(int j=1;j<=100;j++)
				{
					int t=a*i*i+b*j*j;
					int p=genhash(t);
					hash[p]=t;
					num[p]++;
				}
			}
			int res=0;
			for(int i=1;i<=100;i++)
			{
				for(int j=1;j<=100;j++)
				{
					int t=-(c*i*i+d*j*j);
					int p=genhash(t);
					res+=num[p];
				}
			}
			printf("%d\n",res*16);
		}
	}
	return 0;
}