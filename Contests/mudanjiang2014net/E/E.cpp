/*************************************************************************
    > File Name: E.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月07日 星期日 13时07分10秒
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

int arr[200003];
int sumfront[200003];
int sumback[200003];

int main(void)
{
	char s[100003];
	int T;
	scanf("%d".&T);
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int len=strlen(s);\
		for(int i=0;i<len;i++)
		{
			arr[i]=s[i]-'0';
		}
		for(int i=len;i<len*2;i++)
		{
			arr[i]=s[i-len]-'0';
		}
		//Sum front
		sumfront[0]=arr[0];
		int flag=-1;
		for(int i=1;i<2*len;i++)
		{
			sumfront[i]=sumfront[i-1]+arr[i]*flag;
			flag=-flag;
		}
		flag=-flag;
		sumback[2*len-1]=arr[2*len-1];
		for(int i=2*len-2;i>=0;i--)
		{
			sumfront[i]=sumfront[i-1]+arr[i]*flag;
			flag=-flag
		}
		int N;
		scanf("%d",&N);
		while(N--)
		{
			int op,l,r;
			scanf("%d%d%d",&op,&l,&r);
			if(op==1)
			{
			}
			else if
		}
	}
}
