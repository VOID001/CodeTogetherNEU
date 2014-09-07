/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月23日 星期六 12时28分03秒
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
	int a,b;
	for(int i=1;i<=T;i++)
	{
		int numa,numb;
		int suma;
		int sumb;
		suma=sumb=0;
		scanf("%d%d",&numa,&numb);
		int tmp;
		while(numa--)
		{
			scanf("%d",&tmp);
			suma+=tmp;
		}
		while(numb--)	
		{
			scanf("%d",&tmp);
			sumb+=tmp;
		}
		if(suma>sumb)
		{
			printf("Calem");
		}
		else if(suma<sumb)
		{
			printf("Serena");
		}
		else
		{
			printf("Draw");
		}
		printf("\n");
	}
	return 0;
}
