/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月07日 星期日 12时38分20秒
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

int hash[205];
int arr[3];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(hash,0,sizeof(hash));
		int maxc=0;
		int x,y;
		scanf("%d%d",&x,&y);
		//Break the X
		int count=0;
		int maxcount=count;
		for(int j=1;j<=x/2;j++)
		{
			memset(hash,0,sizeof(hash));
			arr[0]=j;
			arr[1]=x-j;
			arr[2]=y;
			for(int i=0;i<3;i++)
			{
				hash[arr[i]]++;
				hash[arr[i%3]+arr[(i+1)%3]]++;
				hash[abs(arr[i%3]-arr[(i+1)%3])]++;
				hash[abs(arr[i%3]+arr[(i+1)%3]-arr[(i+2)%3])]++;
			}
			hash[x+y]++;
			count=0;
			for(int i=1;i<=200;i++)
			{
				if(hash[i]) count++;
			}
			if(maxcount<count) maxcount=count;
		}

		for(int j=1;j<=y/2;j++)
		{
			memset(hash,0,sizeof(hash));
			arr[0]=j;
			arr[1]=y-j;
			arr[2]=x;
			for(int i=0;i<3;i++)
			{
				hash[arr[i]]++;
				hash[arr[i%3]+arr[(i+1)%3]]++;
				hash[abs(arr[i%3]-arr[(i+1)%3])]++;
				hash[abs(arr[i%3]+arr[(i+1)%3]-arr[(i+2)%3])]++;
			}
			hash[x+y]++;
			count=0;
			for(int i=1;i<=200;i++)
			{
				if(hash[i]) count++;
			}
			if(maxcount<count) maxcount=count;
		}
		printf("%d\n",maxcount);
	}
	return 0;
}
