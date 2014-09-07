/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月16日 星期六 14时22分45秒
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
#define INF 9999999
using namespace std;

const int maxn=1001;

struct Doll{
	int out;
	int in;
	int cost;
	int flag=0;
};

bool cmpcst(const Doll& a,const Doll& b)
{
	return a.cost>b.cost;
}


Doll darr[maxn];
//int flag[maxn];


int main(void)
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int totcost=0;
		memset(darr,0,sizeof(darr));
		for(int i=0;i<N;i++)
		{
			scanf("%d%d%d",&darr[i].out,&darr[i].in,&darr[i].cost);
			totcost+=darr[i].cost*darr[i].in;
		}	
		sort(darr,darr+N,cmpcst);
		for(int i=0;i<N;i++)
		{
			int delta=INF;
			int smaID=-1;
			for(int j=0;j<N;j++)
			{
				if(!darr[j].flag)
				{
					if(darr[i].in-darr[j].out>0 && darr[i].in-darr[j].out<delta) 
					{
						smaID=j;	
						delta=darr[i].in-darr[j].out;
					}
					
				}
			}
			if(smaID!=-1)
			{
				darr[smaID].flag=1;
				totcost-=darr[smaID].out*darr[i].cost;
			}
		}
		cout<<totcost<<endl;
	}
	return 0;
}
