/*************************************************************************
    > File Name: 1001.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月21日 星期日 14时54分54秒
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
	if(!b) return a;
	return gcd(b,a%b);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		int M;
		scanf("%d",&M);
		int a,b,x;
		printf("Case #%d:\n",i);
		while (M--)
		{
			scanf("%d%d%d",&a,&b,&x);
			long long prod=0;
			int p=x;
			for(int xx=1;xx<=p;xx++)
			{
			
				int yy=b*xx/a;
				prod+=((yy+1)*yy/2+yy*B)*(xx+A);
			}
			cout<<prod<<endl;
		}
	}
}

