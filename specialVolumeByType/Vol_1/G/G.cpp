/*************************************************************************
    > File Name: G.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月02日 星期一 17时27分03秒
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

const int maxn=5010;

int ID=0;
map<string,int> pattern;
bool vis[maxn][maxn];
int cnt=0;				//Store the times to shuffle
int C;
string destStr;

void dfs(string a,string b)
{
	cnt++;
	if(!pattern.count(a)) pattern[a]=ID++;
	if(!pattern.count(b)) pattern[b]=ID++;
	if(vis[pattern[a]][pattern[b]])
	{
		cnt=-1;
		return ;
	}
	vis[pattern[a]][pattern[b]]=1;
	//shuffle
	string tmpStr;
	tmpStr.clear();
	for(int i=0;i<C;i++)
	{
		tmpStr.push_back(b[i]);
		tmpStr.push_back(a[i]);
	}
	if(tmpStr==destStr) return;
	a.clear();
	b.clear();
	for(int i=0;i<C;i++)
	{
		a.push_back(tmpStr[i]);
	}
	for(int i=C;i<2*C;i++)
	{
		b.push_back(tmpStr[i]);
	}

	dfs(a,b);

}

int main(void)
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		memset(vis,0,sizeof(vis));
		cnt=0;
		cin>>C;
		string s1,s2;
		cin>>s1>>s2;
		cin>>destStr;
		dfs(s1,s2);
		
		cout<<i<<" "<<cnt<<endl;
	}
	return 0;
}
