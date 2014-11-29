/*************************************************************************
    > File Name: 1272.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月25日 星期二 21时38分26秒
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

const int maxv=100010;
int father[maxv];
int used[maxv];


int findroot(int x)
{
	if(father[x]!=x)
	{
		father[x]=findroot(father[x]);	
	}
	return father[x];
}


bool connected (int a,int b)
{
	if(findroot(a)==findroot(b)) return true;
	else return false;
}

void merge(int a,int b)
{
	int x=findroot(a);
	int y=findroot(b);
	if(x!=y)
	{
		father[x]=y;	
	}

	return ;
}

void init(int size)
{
	for(int i=0;i<=size;i++)
	{
		father[i]=i;
	}
	return ;
}


int main(void)
{
	int a;int b;
	int flag=0;
	int stop=0;
	int fa;
	while(1)
	{
		init(maxv);
		memset(used,0,sizeof(used));
		flag=0;
		while(1)
		{
			scanf("%d%d",&a,&b);
			used[a]=used[b]=1;
			if(a==0 && b==0) break;
			if(a==-1 && b==-1)
			{
				stop=1;
				break;
			}
			if(connected(a,b))
			{
				flag=1;
			}
			else
			{
				merge(a,b);
			}
			fa=findroot(a);
		}	
		int pre=fa;
		for(int i=1;i<maxv;i++)
		{
			if(used[i])
			{
				if(fa!=pre) {flag=1;break;}
				pre=fa;
				fa=findroot(i);
			}
		}
		if(stop) break;
		printf("%s\n",flag?"No":"Yes");
	}

	return 0;
}


