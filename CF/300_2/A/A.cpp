/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Tue May 19 18:21:35 2015
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

char cfstr[]="CODEFORCES";
char str[105];
char resstr[105];
int len;

void cut_glue(int r,int l)
{
	memset(resstr,0,sizeof(resstr));
	int cnt=0;
	for(int i=0;i<r;i++)
		resstr[cnt++]=str[i];
	for(int i=l+1;i<len;i++)
		resstr[cnt++]=str[i];
	resstr[cnt]=0;
//	printf("%s\n",resstr);
}

int main(void)
{
	while(scanf("%s",str)!=EOF)
	{
		len = strlen(str);
		int cnt=0;
		int ok=0;
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++)
			{
				cut_glue(i,j);
				if(strcmp(resstr,"CODEFORCES")==0) {ok=1;break;}
			}
			if(ok) break;
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
