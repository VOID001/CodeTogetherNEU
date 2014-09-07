/*************************************************************************
    > File Name: 1011.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月19日 星期二 12时13分38秒
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

typedef long long LL;


const int maxn=100001;

typedef struct Mon{
	LL hp;
	int pos;
}Mon;

typedef struct Tower{
	int atk;
	int left;
	int right;
}Tower;

bool cmp(const Tower& t1,const Tower& t2)
{
    return t1.left<t2.left;
}


Mon mon[maxn];
Tower tow[maxn];

int main(void)
{
	int n;
	int damage_[maxn];
	while(scanf("%d",&n) && n)
	{
		int townum;
		memset(damage_,0,sizeof(damage_));
		scanf("%d",&townum);
		for(int i=0;i<townum;i++)
		{
			scanf("%d%d%d",&tow[i].left,&tow[i].right,&tow[i].atk);
		}
		int monnum;
		scanf("%d",&monnum);
		for(int i=0;i<monnum;i++)
		{
			scanf("%lld%d",&mon[i].hp,&mon[i].pos);
		}
		sort(tow,tow+townum,cmp);
		//for(int i=0;i<townum;i++)
			//printf("Tow left %d right %d atk %d\n",tow[i].left,tow[i].right,tow[i].atk);

        for(int j=1;j<=n;j++)
		{
            for(int k=0;k<townum;k++)
            {
                if(tow[k].left>j) break;
				if(tow[k].right<j) continue;
				//if(j>=tow[k].left && j<= tow[k].right)
				//{
					//printf("add damage %d to No.%d\n",tow[k].atk,j);
					damage_[j]+=tow[k].atk;
				//}
			}
			damage_[j]+=damage_[j-1];
		}
		//DEBUG
		//for(int i=0;i<=n;i++)
		//	printf("%d\t",damage_[i]);
		int alive=0;
		for(int i=0;i<monnum;i++)
		{
			int hpremain=mon[i].hp-(damage_[n]-damage_[mon[i].pos-1]);
			if(hpremain>0) alive++;
		}
		printf("%d\n",alive);
	}
	return 0;
}
