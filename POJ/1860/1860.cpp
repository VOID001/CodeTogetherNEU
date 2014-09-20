/*************************************************************************
    > File Name: 1860.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月20日 星期六 20时02分35秒
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

const int maxn=300;
typedef struct edge{
	int a;
	int b;
	double r;
	double c;

}Edge;

double dis[maxn];

Edge E[maxn];
int N,M,S;
double V;

int tot=0;
bool bellman_ford()
{
	dis[S]=V;
	for(int i=1;i<=N-1;i++)
	{
		bool flag=false;
		for(int j=0;j<tot;j++)
		{
			double tmp=(dis[E[j].a]-E[j].c)*E[j].r;
			if(dis[E[j].b]<tmp)
			{
				flag=1;
				dis[E[j].b]=tmp;
			}
		}
		if(!flag) break;
	}

	for(int j=0;j<tot;j++)
	{
		double tmp=(dis[E[j].a]-E[j].c)*E[j].r;
		if(dis[E[j].b]<tmp)
			return true;
	}
	return false;
}


int main(void)
{
	int ta,tb;
	double rab,cab,rba,cba;
	while(scanf("%d%d%d%lf",&N,&M,&S,&V)!=EOF)
	{
		tot=0;
		memset(E,0,sizeof(E));
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%lf%lf%lf%lf",&ta,&tb,&rab,&cab,&rba,&cba);
			E[tot].a=ta;
			E[tot].b=tb;
			E[tot].r=rab;
			E[tot++].c=cab;
			E[tot].a=tb;
			E[tot].b=ta;
			E[tot].r=rba;
			E[tot++].c=cba;
		}
		if(bellman_ford())
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
