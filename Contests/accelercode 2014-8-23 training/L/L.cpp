/*************************************************************************
    > File Name: L.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月23日 星期六 13时48分54秒
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

typedef struct stu
{
	int timer;
	int ID;
}Stu;

Stu s[20005];

int sque[20005];

int cmp(const Stu& s1,const Stu& s2)
{
	return s1.timer<s2.timer;
}

int main(void)
{
	int hh,mm,ss;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(sque,0,sizeof(sque));
		int N,L;
		scanf("%d%d",&N,&L);
		for(int i=1;i<=N;i++)
		{
			scanf("%d:%d:%d",&hh,&mm,&ss);
			s[i].timer=hh*3600+mm*60+ss;
			s[i].ID=i;
		}
		sort(s+1,s+N+1,cmp);
			//cout<<"***DEBUG***"<<endl;
		//for(int i=1;i<=N;i++)
			//cout<<s[i].timer<<endl;
		int cur=s[1].timer;
		int needcards=1;
		int cntptr=1;
		sque[0]=s[1].ID;
		for(int i=2;i<=N;i++)
		{
			if(s[i].timer-cur>=L)
			{
				cur=s[i].timer;
				needcards++;
				sque[cntptr++]=s[i].ID;
			}
		}
		sort(sque,sque+needcards);
		printf("%d\n",needcards);
		for(int i=0;i<needcards;i++)
		{
			printf("%d",sque[i]);
			if(i!=needcards-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
