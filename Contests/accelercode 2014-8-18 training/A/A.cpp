/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月18日 星期一 12时03分12秒
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

int arr[20];

int main(void)
{
	int p;
	scanf("%d",&p);
	while(p--)
	{
		int no;
		scanf("%d",&no);
		for(int i=0;i<10;i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+10);
		cout<<no<<" ";
		cout<<arr[7]<<endl;
	}
	return 0;
}
