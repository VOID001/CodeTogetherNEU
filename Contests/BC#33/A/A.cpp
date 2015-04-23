/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月21日 星期二 12时30分54秒
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
const int maxn=405;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

char numa[maxn];
char res[maxn];
char tab[]="0123456789abcdefghijklmnopqrstuvwxyz";
int n,B;
void print(char* p);

void add(char* na,char*resp)
{
	int len=strlen(na);
	FORi(0,len)
	{
		na[maxn-1-(len-i-1)]=na[i];
		na[i]=0;
	}
	len = strlen(resp);
	FORi(0,len)
	{
		resp[maxn-len+i]=resp[i];
		resp[i]=0;
	}
	for(int i=maxn-1;na[i]!=0 || resp[i]!=0;i--)
	{
		int numa,numb;
		numa=numb=0;
		//printf("na= %c resp= %c\n",na[i],resp[i]);
		if(na[i] == 0 ) numa=0;
		else
			numa=((na[i]>='a')?(na[i]-'a'+10):(na[i]-'0'));
		if(resp[i] == 0) numb=0;
		else
			numb=((resp[i]>='a')?(resp[i]-'a'+10):(resp[i]-'0'));
		resp[i]=tab[(numa+numb)%B];
		//printf("resp[%d]:%c numa=%x numb=%x\n",i,resp[i],numa,numb);
	}
	//Reverse
	int cnt=0;
	FORi(0,maxn)
	{
		if(resp[i])
		{
			len=maxn-i;
			break;
		}
	}
	//	printf("len = %d\n",len);
	while(resp[maxn-cnt-1])
	{
		resp[len-cnt-1]=resp[maxn-cnt-1];
		resp[maxn-cnt-1]=0;
		cnt++;
	}
	//printf("%s\n",resp);
	//print(resp);
	return ;
}

void print(char* p)
{
	int len=strlen(p);
	bool inp=false;
	FORi(0,len)
	{
		if(p[i]!='0' && p[i]!=0)
		{
			inp=true;
		}
		if(inp)	printf("%c",p[i]);
	}
	if(!inp) printf("0");
	printf("\n");
	return ;
}


int main(void)
{
	while(scanf("%d%d",&n,&B)!=EOF)
	{
		MEMSET0(res);
		MEMSET0(numa);
		while(n--)
		{
			MEMSET0(numa);
			scanf("%s",numa);
			add(numa,res);
		}
		print(res);
	}
	return 0;
}
