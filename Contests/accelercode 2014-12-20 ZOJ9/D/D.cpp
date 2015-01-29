/*************************************************************************
    > File Name: D.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月21日 星期日 12时51分16秒
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

int num[26][30];

int main(void)
{
	int T;
	scanf("%d",&T);
	char str[20];
	while(T--)
	{
		int N;
		scanf("%d",&N);
		memset(num,0,sizeof(num));
		for(int i=0;i<N;i++)
		{
			scanf("%s",str);
			//int len=strlen(str);
			for(int j=0;j<12;j++)
			{
				num[str[j]-'A'][i]++;
			}
		}
		for(int i=0;i<26;i++)
		{
			int min=20;
			for(int j=0;j<N;j++)
			{
				if(num[i][j]<min)
				{
					min=num[i][j];
				}
			}
			for(int k=0;k<min;k++)
			{
				printf("%c",'A'+i);
			}
		}
		printf("\n");
	}
}
