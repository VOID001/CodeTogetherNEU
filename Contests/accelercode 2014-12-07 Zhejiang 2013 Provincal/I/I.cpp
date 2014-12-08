/*************************************************************************
    > File Name: I.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月07日 星期日 13时35分02秒
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

void convchar(char ch)
{
	int binarr[8];
	memset(binarr,0,sizeof(binarr));
	int cur=7;
	while(ch)
	{
		binarr[cur]=ch%2;	
		cur--;
		ch/=2;
	}
	int bs1,bs2;
	bs1=bs2=0;
	for(int i=0;i<4;i++)
	{
		bs1=bs1*2+binarr[i];
	}
	for(int i=4;i<8;i++)
	{
		bs2=bs2*2+binarr[i];
	}
	printf("%c%c",(bs1<10?bs1+'0':bs1-10+'A'),(bs2<10?bs2+'0':bs2-10+'A'));
}

void convlen(int len)
{
	int binarr[100];
	int shiftc=0;
	memset(binarr,0,sizeof(binarr));
	while(len)
	{
		for(int i=shiftc*8+7;i>=shiftc*8;i--)
		{
			if(i!=shiftc*8)
			{
				binarr[i]=len%2;	
				len=len/2;
			}
			else
			{
				if(len!=0)
				{
					binarr[i]=1;
				}
				else
					binarr[i]=0;
			}
		}
		shiftc++;
	}
	for(int i=0;i<shiftc*8;i+=8)
	{
		int bs1;
		int bs2;
		bs1=bs2=0;
		for(int j=i;j<i+4;j++)
		{
			bs1=bs1*2+binarr[j];
		}
		for(int j=i+4;j<i+8;j++)
		{
			bs2=bs2*2+binarr[j];
		}
		printf("%c%c",bs1<10?bs1+'0':bs1-10+'A',bs2<10?bs2+'0':bs2-10+'A');
	}
}

char str[3000001];

int main(void)
{
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		gets(str);
		int len=strlen(str);
		if(len)
			convlen(len);
		else
			printf("00");
		for(int i=0;i<len;i++)
		{
			convchar(str[i]);
		}
		printf("\n");
	}
	return 0;
}
