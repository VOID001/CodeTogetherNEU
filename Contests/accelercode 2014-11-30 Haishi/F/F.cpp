/*************************************************************************
    > File Name: F.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月30日 星期日 16时09分18秒
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

int graph[100][100];
int indeg[105];
int outdeg[105];

int main(void)
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=1;i<=N;i++)
		{
			int a;
			scanf("%d",&a);
			int tmp;
			while(a--)
			{
				scanf("%d",&tmp);
				indeg[tmp]++;
				outdeg
			}
		}
	}
}
