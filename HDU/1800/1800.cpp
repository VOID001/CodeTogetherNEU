/*************************************************************************
    > File Name: 1800.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月17日 星期三 18时29分45秒
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

const int MOD=7003;						//At most 3000 different strings

int hasht[MOD];
int num[MOD];
int maxnum;

inline int ELFhash(char* key)
{
	unsigned long h=0;
	unsigned long g;
	while(*key)
	{
		h = (h<<4) + *key++;
		g = h & 0xf0000000L;
		if(g) h^=g>>24;
		h &=~g;
	}
	return h;
}

inline void genhash(char* key)
{
	int tmp;
	while(*key++ == '0');
	key--;
	tmp=ELFhash(key);					//gen a number
	int k=tmp%MOD;						//hash the number into [0,MOD)
	while(hasht[k]!=tmp && num[k]!=0)	//Here , understand the code so you won't make mistakes
	{
		k=(k+1)%MOD;
	}
	num[k]++;
	if(hasht[k]==-1) hasht[k]=tmp;				
	if(maxnum<num[k]) maxnum=num[k];

	return ;
}

int main(void)
{
	int T;
	while(scanf("%d",&T)!=EOF)
	{
		char str[35];
		memset(hasht,-1,sizeof(hasht));
		memset(num,0,sizeof(num));
		maxnum=0;
		for(int i=0;i<T;i++)
		{
			scanf("%s",str);
			genhash(str);
		}
		printf("%d\n",maxnum);
	}
	return 0;
}
