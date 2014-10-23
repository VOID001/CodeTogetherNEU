/*************************************************************************
    > File Name: 1116.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年10月23日 星期四 20时55分13秒
	> Comment:并查集&欧拉路  具体见blog
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

const int maxn=26;
int father[maxn];

int findroot(int i)									//Search for the connected root of this node
{
	if(father[i]!=i)
	{
		father[i]=findroot(father[i]);
	}
	return father[i];
}

void unionNode(int a,int b)							//Union the two nodes
{
	int x,y;
	x=findroot(a);
	y=findroot(b);
	if(x!=y) father[x]=y;
	return ;
}

int main(void)
{
	int in[maxn],out[maxn];							//Keep the indegree and outdegree
	int visit[maxn];
	char word[1005];
	int T;
	int cnt=0;
	bool isEulerLoop;
	bool isEulerPath;
	scanf("%d",&T);
	while(T--)
	{
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(visit,0,sizeof(visit));
		int n;
		scanf("%d",&n);
		for(int i=0;i<maxn;i++)
		{
			father[i]=i;
		}
		cnt=0;
		while(n--)
		{
			scanf("%s",word);
			int a=word[0]-'a';
			int b=word[strlen(word)-1]-'a';
			visit[a]=visit[b]=1;
			unionNode(a,b);
			out[a]++;
			in[b]++;
		}
		for(int i=0;i<maxn;i++)
		{
			father[i]=findroot(i);								//Find the roots 
		}
		/*//DEBUG
		printf("\nDEBUG FATHERS\n");
		for(int i=0;i<maxn;i++)
		{
			printf("father[%d]=%d\n",i,father[i]);
		}
		printf("\nDEBUG IN\n");
		for(int i=0;i<maxn;i++)
		{
			printf("in[%d]=%d\n",i,in[i]);
		}
		printf("\nDEBUG OUT\n");
		for(int i=0;i<maxn;i++)
		{
			printf("out[%d]=%d\n",i,out[i]);
		}
		//END DEBUG*/
		for(int i=0;i<maxn;i++)								//How to judge it only has one root
		{
			if(father[i]==i && visit[i])
				cnt++;
		}
		if(cnt!=1)
		{
			printf("The door cannot be opened.\n");
		}
		else
		{
			isEulerLoop=true;
			isEulerPath=true;
			for(int i=0;i<maxn;i++)
			{
				if(in[i]!=out[i]) 
				{
					isEulerLoop=false;
				}
			}
			if(!isEulerLoop)
			{
				//Judge if it's Euler Path;
				int flaga=0;
				int flagb=0;
				for(int i=0;i<maxn;i++)
				{
					if(in[i]!=out[i])
					{
						if(in[i]-out[i]==1) flaga++;
						else if(out[i]-in[i]==1) flagb++;
						else
						{
							isEulerPath=false;
							break;
						}
					}
				}
				if(flaga!=1 || flagb!=1) isEulerPath=false;
			}
			if(isEulerLoop)
			{
				printf("Ordering is possible.\n");
			}
			else if(isEulerPath)
			{
				printf("Ordering is possible.\n");
			}
			else
			{
				printf("The door cannot be opened.\n");
			}
		}
	}
	return 0;
}

