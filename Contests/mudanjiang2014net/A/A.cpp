/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月07日 星期日 12时36分37秒
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

int arr[55];
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",arr+i);
		}
		int cnt=0;
		for(int i=1;i<N-1;i++)
		{
			if(arr[i]> arr[i-1] && arr[i]>arr[i+1]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
