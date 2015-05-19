/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Mon May 18 15:32:05 2015
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
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int alpha[26];
char str[100];
int mark[100];
int main(void)
{
	int n;
	while(scanf("%d%s",&n,str)!=EOF)
	{
		int len=strlen(str);
		int cnt = 0;
		MEMSET0(alpha);
		MEMSET0(mark);
		FORi(0,len)
		{
			if(alpha[str[i]-'a'] == 0)
			{
				mark[cnt++]=i;
				alpha[str[i]-'a'] =1;
			}
			if(cnt == n) break;
		}
		mark[cnt]=len-1;
		if(cnt != n )
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			FORi(0,cnt)
			{
				FORj(mark[i],mark[i+1])
				{
					printf("%c",str[j]);
				}
				if(i == cnt-1) printf("%c",str[mark[i+1]]);
				printf("\n");
			}
		}
	}
	return 0;
}
