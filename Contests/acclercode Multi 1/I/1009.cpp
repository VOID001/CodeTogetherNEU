/*************************************************************************
    > File Name: 1009.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月19日 星期二 13时06分58秒
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

typedef map<pair<int,int>,double> Map;
Map mm;


int main(void)
{

    pair<int,int> pp[5];

	pp[0]=make_pair(85,100);
	pp[1]=make_pair(80,84) ;
	pp[2]=make_pair(75,79) ;
	pp[3]=make_pair(70,74) ;
	pp[4]=make_pair(60,69) ;
	mm[pp[0]]=4.0;
	mm[pp[1]]=3.5;
	mm[pp[2]]=3.0;
	mm[pp[3]]=2.5;
	mm[pp[4]]=2.0;
	double dp1[15][1010]={0};
	double dp2[15][1010]={0};
	for(int i=1;i<=10;i++)
	{
        for(int j=i*60;j<=i*100;j++)
		{
			int maxn=max(j-(i-1)*100,60);
			double xxdb;
			for(int oo=0;oo<5;oo++)
			{
				if((pp[oo].first-maxn)*(pp[oo].second-maxn)<=0)
				{
					xxdb=mm[pp[oo]];
					break;
				}
			}
			dp1[i][j]=dp1[i-1][j-maxn]+xxdb;
			dp2[i][j]=dp2[i-1][j-maxn]+xxdb;
			int minn=min(j-(i-1)*60,100);
			for(int k=maxn+1;k<=minn;k++)
			{
				double mmdb;
				for(int oo=0;oo<5;oo++)
				{
					if((pp[oo].first-k)*(pp[oo].second-k)<=0)
					{
						mmdb=mm[pp[oo]];
						break;
					}
				}
				dp1[i][j]=max(dp1[i][j],dp1[i-1][j-k]+mmdb);
				dp2[i][j]=min(dp2[i][j],dp2[i-1][j-k]+mmdb);
			}
		}
	}
	int T;
	scanf("%d",&T);
	int avg,n;
	while(T--)
	{
		scanf("%d%d",&avg,&n);
		printf("%.4lf %.4lf\n",dp2[n][avg*n]/n*1.0,dp1[n][avg*n]/n*1.0);
	}

	return 0;
}
