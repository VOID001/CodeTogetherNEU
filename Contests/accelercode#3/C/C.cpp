/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2015年03月22日 星期日 15时37分17秒
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
const int maxn=1005;

vector<int> vec[maxn];
vector<int> path;
vector<int> allpath[maxn];
int cnt;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

bool cmp(int a,int b)
{
	return vec[a].size()>vec[b].size();
}

void dfs(int x)
{
	if(vec[x].size()==0)
	 {
        FORj(0,path.size())
        {
            allpath[cnt].push_back(path[j]);
        }
		cnt++;
        return;
	 }
	int len=vec[x].size();
	for(int i=0;i<len;i++)
	{
		path.push_back(i);
		dfs(vec[x][i]);
		path.pop_back();
	}
	return ;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,Q;
		cnt=0;
		scanf("%d%d",&n,&Q);
		int u,v;
		FORi(0,maxn)
		{
			vec[i].clear();
			allpath[i].clear();
		}
		int tmp=n-1;
		while(tmp--)
		{
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
		}
		FORi(0,n-1)
		{
			sort(vec[i].begin(),vec[i].end(),cmp);
		}
		//FORi(0,n-1)
		//{
		//	for(vector<int>::iterator it=vec[i].begin();it!=vec[i].end();it++)
		//	{
		//		printf("%d ",*it);
		//	}
		//	printf("\n");
		//}
		//return 0;

		path.clear();
		dfs(0);
		while(Q--)
		{
			int query;
			scanf("%d",&query);
			if(query>cnt) printf("Out of range.\n");
			else
			{
				int len=allpath[query-1].size();
				printf("%d",allpath[query-1][0]);
				FORi(1,len)
				{
					printf(" %d",allpath[query-1][i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
//TAT
