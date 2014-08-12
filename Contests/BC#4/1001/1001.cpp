/*************************************************************************
    > File Name: 1001.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月10日 星期日 19时02分45秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int T;
	int a[1000];
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<6;i++)
			scanf("%d",&a[i]);
		sort(a,a+6);
		if(a[5]+a[4]> a[3]+a[2]+a[1]) 
			printf("Grandpa Shawn is the Winner!\n");
		else
			printf("What a sad story!\n");
	}
	return 0;
}
