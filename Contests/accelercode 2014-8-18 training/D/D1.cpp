/*************************************************************************
    > File Name: D1.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月18日 星期一 13时05分14秒
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

set<int> s;


int main(void)
{
	int T;
	scnaf("%d",&T);
	while(T--)
	{
		int no,numm;
		scanf("%d%d",&no,&numm);
		printf("%d %d",no,numm/2+1);
		int cnt=1;
		for(int i=1;i<=numm;i++)
		{
			int tnum;
			scanf("%d",tnum);
			s.insert()

			if(i%2) cout<<s[i/2+1];
			if(cnt==10) cout<<endl;
			else if(i!=numm) cout<<" ";
			cnt++;
		}
	}
	return 0;
}
