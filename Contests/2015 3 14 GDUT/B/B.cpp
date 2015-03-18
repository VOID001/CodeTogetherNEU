/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月14日 星期六 13时20分54秒
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

char alpha[]={"#ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int tmpstor[5];
		memset(tmpstor,-1,sizeof(tmpstor));
		int a;
		scanf("%d",&a);
		int i=4;
		while(a)
		{
			tmpstor[i--]=a%26;
			a/=26;
		}
		for(int i=0;i<5;i++)
		{
			if(tmpstor[i]==-1) continue;
			if(tmpstor[i]==0)
			{
				tmpstor[1]=26;
				if(tmpstor[i-1]!=-1) tmpstor[i-1]--;
			}
		}
		for(int i=0;i<5;i++)
		{
			if(tmpstor[i]==-1) continue;
			printf("%c",'A'+tmpstor[i]-1);
		}
		printf("\n");
	}
	return 0;
}
