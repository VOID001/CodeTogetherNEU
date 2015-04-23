/*************************************************************************
    > File Name: M.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月18日 星期三 18时58分05秒
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
const int maxn=105;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int cup[3];
int tmpcup[3];
int size[3];
int dir[][2]={{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}};
bool vis[maxn][maxn];
bool inque[maxn][maxn];
typedef struct node{
	int N;
	int M;
	int step;
}Node;
queue<Node> que;

void pour(int i,int j)
{
	//pour i into j
	if(cup[i]==0) return;
	if(cup[j]==size[j]) return;

	if(size[j]-cup[j]<=cup[i])
	{
		cup[i]=cup[i]-(size[j]-cup[j]);
		cup[j]=size[j];
		//printf("[POURED1]\n");
	}
	else
	{
		cup[j]=cup[j]+cup[i];
		cup[i]=0;
		//printf("[POURED2]\n");
	}
	return ;
}

int bfs()
{
	while(!que.empty()) que.pop();
	int minpour=99999;
	cup[0]=size[0];
	cup[1]=cup[2]=0;
	Node tmp;
	tmp.N=cup[1];
	tmp.M=cup[2];
	tmp.step=0;
	que.push(tmp);
	inque[0][0]=1;
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		//printf("[DEQUEUE]STATE S=%d  N=%d  M=%d\n",size[0]-tmp.N-tmp.M,tmp.N,tmp.M);
		int n=tmp.N;int m=tmp.M;int s=size[0]-n-m;
		if((n==m && s==0)||(n==s && m==0)||(s==m && n==0)) {minpour=tmp.step<minpour?tmp.step:minpour;}
		if(!vis[tmp.N][tmp.M])
		{
			vis[tmp.N][tmp.M]=1;
			Node ttmp;
			cup[1]=tmp.N;
			cup[2]=tmp.M;
			cup[0]=size[0]-tmp.N-tmp.M;
			//printf("[BEFORE POUR] S=%d N=%d M=%d\n",cup[0],cup[1],cup[2]);
			FORi(0,3) tmpcup[i]=cup[i];
			FORi(0,6)
			{
				FORj(0,3) cup[j]=tmpcup[j];
				pour(dir[i][0],dir[i][1]);
				//printf("[AFTER POUR] S=%d N=%d M=%d\n",cup[0],cup[1],cup[2]);
				if(!inque[cup[1]][cup[2]])
				{
					ttmp.N=cup[1];
					ttmp.M=cup[2];
					ttmp.step=tmp.step+1;
					que.push(ttmp);
					//printf("[INQUEUE]STATE S=%d  N=%d  M=%d\n",size[0]-ttmp.N-ttmp.M,ttmp.N,ttmp.M);
					inque[ttmp.N][ttmp.M]=1;
				}
			}
		}
	}
	return minpour;
}

int main(void)
{
	while(scanf("%d%d%d",size,size+1,size+2) && (size[0] || size[1] || size[2]))
	{
		MEMSET0(vis);
		MEMSET0(inque);
		if(size[0]%2) printf("NO\n");
		else
		{
			int res=bfs();
			if(res==99999) printf("NO\n");
			else printf("%d\n",res);
		}
	}
	return 0;
}
