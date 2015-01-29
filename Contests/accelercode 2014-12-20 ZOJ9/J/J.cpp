/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月21日 星期日 12时31分03秒
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

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,x,m;
		scanf("%d%d",&a,&m);
		if(m==1)
		{
			if(a%m!=0)
				printf("Not Exist\n");
			else
				printf("1\n");
		}
		else
		{
			for(x=1;x<=m;x++)
			{
				if(a*x%m==1)
				{
					printf("%d\n",x);
					break;
				}
			}
			if(x==m+1) printf("Not Exist\n");
		}
	}
	return 0;
}
