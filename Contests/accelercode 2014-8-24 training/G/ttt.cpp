/*************************************************************************
    > File Name: ttt.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月24日 星期日 15时09分54秒
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

int main(void)
{
	int a[2][2]={1,1,2,2};
	int b[2][2]={3,3,4,4};
	memcpy(b,a,sizeof(a));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			printf("%d ",b[i][j]);
}
