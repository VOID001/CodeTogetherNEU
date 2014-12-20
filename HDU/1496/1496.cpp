/*************************************************************************
    > File Name: 1496.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月06日 星期六 11时46分19秒
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

const int hashmaxsize=1000005;

int hashpos[hashmaxsize];
int hashneg[hashmaxsize];

int main(void)
{
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		memset(hashpos,0,sizeof(hashpos));
		memset(hashneg,0,sizeof(hashneg));
		if(a>0 &&  b>0 && c>0 && d>0 || a<0 && b<0 && c<0 && d<0) printf("0\n");
		else
		{
			int k;
			for(int i=1;i<=100;i++)
			{
				for(int j=1;j<=100;j++)
				{
					k=a*i*i+b*j*j;
					if(k>0) hashpos[k]++;
					else hashneg[-k]++;
				}
			}
			int sum=0;
			for(int i=1;i<=100;i++)
			{
				for(int j=1;j<=100;j++)
				{
					k=c*i*i+d*j*j;
					if(k>=0) sum+=hashneg[k];				//这里应该用 >=号 不能用 > 号
					else sum+=hashpos[-k];
				}
			}
			printf("%d\n",sum*16);
		}
	}
	return 0;
}
