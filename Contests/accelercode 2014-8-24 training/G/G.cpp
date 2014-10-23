/*************************************************************************
    > File Name: G.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月24日 星期日 14时53分41秒
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

int adj[55][55];
int chess[55][55];
int change[55][55];

typedef struct leave{
	int time;
	int ii;
	int jj;
}Leave;

Leave lv[2501];


bool cmp(const Leave& l1,const Leave& l2)
{
	if(l1.time!=l2.time)
		return l1.time<l2.time;
	if(l1.ii!=l2.ii)
		return l1.ii<l2.ii;
	if(l1.jj!=l2.jj)
		return l1.jj<l2.jj;

}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int N,M,F,K;
		memset(chess,0,sizeof(chess));
		memset(change,0,sizeof(change));
		memset(adj,0,sizeof(adj));
		
		scanf("%d%d%d%d",&N,&M,&F,&K);
		//for(int i=1;i<=N;i++)
		//{
		//	for(int j=1;j<=M;j++)
		//		printf("%d ",adj[i][j]);
		//	printf("\n");
		//}
		char tttt;
		getchar();
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				scanf("%c",&tttt);
				chess[i][j]=tttt-'0';
				if(chess[i][j]==1) 
				{
			//		printf("Minion (%d,%d) is awake\n ",i,j);
					adj[i-1][j-1]++;
					adj[i-1][j+1]++;
					adj[i+1][j+1]++;
					adj[i+1][j-1]++;
					adj[i-1][j]++;
					adj[i+1][j]++;
					adj[i][j-1]++;
					adj[i][j+1]++;
				}
			}
			getchar();
		}
		//for(int i=1;i<=N;i++)
		//{
		//	for(int j=1;j<=M;j++)
		//		printf("%d ",adj[i][j]);
		//	printf("\n");
		//}
		for(int i=0;i<K;i++)
		{
			scanf("%d%d%d",&lv[i].time,&lv[i].ii,&lv[i].jj);
		}
		sort(lv,lv+K,cmp);
		int ptrcnt=0;
		for(int tt=1;tt<=F;tt++)
		{
			memset(change,0,sizeof(change));
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					if(chess[i][j]==-1) continue;
					if(ptrcnt<K && tt==lv[ptrcnt].time && i==lv[ptrcnt].ii && j==lv[ptrcnt].jj)
					{
						if(chess[i][j]) 
						{
							change[i-1][j-1]--;
							change[i-1][j+1]--;
							change[i+1][j+1]--;
							change[i+1][j-1]--;
							change[i-1][j]--;
							change[i+1][j]--;
							change[i][j-1]--;
							change[i][j+1]--;
						}
						chess[i][j]=-1; 
						ptrcnt++;
					}
					else
					{
						if(chess[i][j])
						{

							if(adj[i][j]<2 || adj[i][j]>3) 
							{
								change[i-1][j-1]--;
								change[i-1][j+1]--;
								change[i+1][j+1]--;
								change[i+1][j-1]--;
								change[i-1][j]--;
								change[i+1][j]--;
								change[i][j-1]--;
								change[i][j+1]--;
								chess[i][j]=0;
							}
						}
						else
						{
							if(adj[i][j]==3)
							{
								change[i-1][j-1]++;
								change[i-1][j+1]++;
								change[i+1][j+1]++;
								change[i+1][j-1]++;
								change[i-1][j]++;
								change[i+1][j]++;
								change[i][j-1]++;
								change[i][j+1]++;
								chess[i][j]=1;
							}
						}
					}
				}

			}
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					adj[i][j]+=change[i][j];
				}
			}

			//printf("************************\n");	
			//for(int i=1;i<=N;i++)
			//{
			//	for(int j=1;j<=M;j++)
			//	{
			//		printf("%d",change[i][j]);
			//	}
			//	printf("\n");
			//}
			//	for(int i=1;i<=N;i++)
			//	{
			//		for(int j=1;j<=M;j++)
			//		{
			//			//printf("%c",chess[i][j]==-1?'X':chess[i][j]+'0');	
			//			if(chess[i][j]==-1) printf("X");
			//			if(chess[i][j]==0) printf("0");
			//			if(chess[i][j]==1) printf("1");
			//		}
			//		printf("\n");
			//	} 
			//	printf("**************************\n");
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				//printf("%c",chess[i][j]==-1?'X':chess[i][j]+'0');	
				if(chess[i][j]==-1) printf("X");
				else if(chess[i][j]==0) printf("0");
				else if(chess[i][j]==1) printf("1");
				else printf("F");
			}
			printf("\n");
		}
		//printf("COUNT\n");
	}
	return 0;
}
