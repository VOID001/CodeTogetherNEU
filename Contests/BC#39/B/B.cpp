/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月26日 星期日 19时50分49秒
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

int arr[10005];

int main(void)
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		FORi(1,N+1)
		{
			scanf("%d",arr+i);
		}
		int sum=0;
		FORi(1,N+1)
		{
			FORj(i+1,N+1)
			{
				if(arr[j]%arr[i] == 0)
				{
					sum+=j;
					break;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;

}
