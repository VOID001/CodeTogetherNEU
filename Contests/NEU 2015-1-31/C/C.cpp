/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年01月31日 星期六 12时54分44秒
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
#include<cmath>
using namespace std;


int main(void)
{
	int T;
	int N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		if(N)
		{
			printf("5");
			for(int i=0;i<N-1;i++) printf("0");
			printf("5");
			for(int i=0;i<N-1;i++) printf("0");
		}
		else
		{
			printf("1");
		}
		printf("\n");
	}
	return 0;
}
