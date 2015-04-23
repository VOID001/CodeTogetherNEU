/*************************************************************************
    > File Name: F.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月22日 星期日 12时47分39秒
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
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int main(void)
{
	int T;
	cin>>T;
	string name[105];
	while(T--)
	{
		int n;
		string front;
		cin>>n;
		cin>>front;
		int cur;
		FORi(0,n)
		{	
			cin>>name[i];
			if(name[i]==front) cur=i;
		}
		cout<<name[(cur-n/2+n)%n]<<endl;
	}
	return 0;
}

