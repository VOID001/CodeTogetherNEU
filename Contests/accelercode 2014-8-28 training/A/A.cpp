/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月28日 星期四 12时11分17秒
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

long long arr[50];


int main(void)
{
	arr[1]=1;
	arr[2]=2;
	arr[3]=5;
	arr[4]=10;
	arr[5]=20;
	arr[6]=25;
	arr[7]=50;
	arr[8]=100;
	arr[9]=125;
	for(int i=10;i<50;i+=5)
	{
		arr[i]=arr[i-5]*10;
		arr[i+1]=arr[i-4]*10;
		arr[i+2]=arr[i-3]*10;
		arr[i+3]=arr[i-2]*10;
		arr[i+4]=arr[i-1]*10;
	}
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int cnt=0;
		for(int i=1;arr[i]<=n;i++)
		{
			if(arr[i]>=m) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
	
}
