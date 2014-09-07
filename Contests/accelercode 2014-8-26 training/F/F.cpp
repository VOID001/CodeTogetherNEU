/*************************************************************************
    > File Name: F.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月26日 星期二 13时02分12秒
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

bool isSeven();
bool isOrphan();
typedef struct icard{
	int rank;
	int type;
}Card;

bool cmp(const Card& c1,const Card& c2)
{
	if(c1.type!=c2.type)
		return c1.type<c2.type;
	return c1.rank<c2.rank;
}

Card card[30];


int main(void)
{
	char cards[30];
	while(scanf("%s",cards)!=EOF)
	{
		for(int i=0;i<27;i+=2)
		{
			card[i/2].rank=cards[i]-'0';
			switch(cards[i+1])
			{
				case 's':
					card[i/2].type=0;
					break;
				case 'm':
					card[i/2].type=1;
					break;
				case 'p':
					card[i/2].type=2;
					break;
				case 'z':
					card[i/2].type=3;
					break;
			}
		}
		sort(card,card+14,cmp);
	
	if(isSeven()) printf("Seven Pairs");
	else if(isOrphan()) printf("Thirteen Orphans");
	else printf("Neither!");
	printf("\n");
	}
	return 0;
}

bool isSeven()
{
	for(int i=0;i<14;i+=2)
	{
		if(card[i].rank==card[i+1].rank && card[i].type==card[i+1].type)
		{
			if(i!=0) 
			{
				if(card[i].rank==card[i-1].rank && card[i].type==card[i-1].type)
				return false;
			}
		}
		else return false;
	}
	return true;
}

bool isOrphan()
{
	int haven[13];
	memset(haven,0,sizeof(haven));
	for(int i=0;i<14;i++)
	{
		if(card[i].type==0)
		{
			//j	switch(card[i].rank)
			//j	{
			//j		case 1:

			//j	}
			if(card[i].rank==1) haven[0]++;
			if(card[i].rank==9) haven[1]++;
		}
		else if(card[i].type==1)
		{
			if(card[i].rank==1) haven[2]++;
			if(card[i].rank==9) haven[3]++;
		}
		else if(card[i].type==2)
		{
			if(card[i].rank==1) haven[4]++;
			if(card[i].rank==9) haven[5]++;
		}
		else if(card[i].type==3)
		{
			if(card[i].rank<=7) haven[5+card[i].rank]++;
		}
	}
	int two=0;
	for(int i=0;i<13;i++)
	{
		if(haven[i]==0 || haven[i]>2 ) return false;
		if(haven[i]==2 && two) return false;
		else if(haven[i]==2)
			two++;
	}
	if(two!=0) return true;
	else return false;
}
