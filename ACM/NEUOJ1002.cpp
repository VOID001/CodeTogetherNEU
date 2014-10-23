/*************************************************************************
    > File Name: NEUOJ1002.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月08日 星期五 16时41分18秒
 ************************************************************************/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int main(void)
{
	string b;
	int a;
	int mark[4];
	while(scanf("%d",&a)!=EOF)
	{
		int cnt=0;
		memset(mark,0,sizeof(mark));
		while(a--)
		{
			cin>>b;
			if(mark[0]==1 && mark[1]==1 && mark[2]==1 && mark[3]==1) break;
			if(b=="bowl" && mark[0]==0) {mark[0]=1;if(cnt==0){cout<<b;}else cout<<" "<<b;cnt++;}
			if(b=="fork" && mark[1]==0) {mark[1]=1;if(cnt==0){cout<<b;}else cout<<" "<<b;cnt++;}
			if(b=="chopsticks" && mark[2]==0) {mark[2]=1;if(cnt==0){cout<<b;}else cout<<" "<<b;cnt++;}
			if(b=="knife"&& mark[3]==0) {mark[3]=1;if(cnt==0){cout<<b;}else cout<<" "<<b;cnt++;}
		}
		cout<<endl;

	}
		return 0;
}
