/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年01月29日 星期四 22时08分43秒
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

const int maxn=17;

int N,K;
char board[maxn][maxn];

bool isOK(int m,int n)
{
	for(int i=0;i<N;i++)
	{
		if(i==m)continue;
		if(board[i][n]=='C') return false;
	}
	for(int i=0;i<N;i++)
	{
		if(i==n) continue;
		if(board[m][i]=='C') return false;
	}
	return true;
}

void print()
{
	printf("====BEGIN OF DEBUG===\n");
	for(int i=0;i<N;i++)
	{
		printf("%s\n",board[i]);
	}
	printf("====END OF DEBUG===\n");
}

int dfs(int m,int num)
{
	int sum=0;
	if(m==N)
	{
		if(num==K) { /*print();*/ return 1;}
		else return 0;
	}
	for(int i=0;i<N;i++)
	{
		if(board[m][i]=='#')
		{
			if(isOK(m,i))
			{
				board[m][i]='C';
				sum+=dfs(m+1,num+1);
				board[m][i]='#';
			}
		}
	}
	sum+=dfs(m+1,num);
	return sum;
}

int main(void)
{
	while(scanf("%d%d",&N,&K) && N!=-1 && K!=-1)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%s",board[i]);
		}
		long long res=dfs(0,0);
		printf("%lld\n",res);
	}
	return 0;
}
