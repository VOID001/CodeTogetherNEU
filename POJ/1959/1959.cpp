/*************************************************************************
    > File Name: 1959.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年09月11日 星期四 14时31分44秒
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

const int maxn=500;



void initialize(int* arr)
{
	for(int i=0;i<=20;i++)
	{
		arr[i]=i;
	}
	for(int k=1;k<=20;k++)
	{
		arr[k+20]=2*k;
	}
	for(int k=1;k<=20;k++)
	{
		arr[k+40]=3*k;
	}
	arr[61]=25;
	arr[62]=50;
	sort(arr,arr+62);
	return ;
}

int main(void)
{
	int arr[maxn];
	initialize(arr);
	int n;
	scanf("%d",&n);
	for(int oo=1;oo<=n;oo++)
	{
		int score;
		int tmp;
		int cnt=0;
		scanf("%d",&score);
		for(int i=0;i<=62;i++)
		{
			for(int j=i;j<=62;j++)
			{
				for(int k=j;k<=62;k++)
				{
					tmp=arr[i]+arr[j]+arr[k];
					if(tmp==score) 
					{
					//	cout<<arr[i]<< ","<<arr[j]<<","<<arr[k]<<endl;
						cnt++;
					}
					//if(tmp>score) break;
				}
				//if(tmp>score) break;
			}
			//if(tmp>score) break;
		}
		cout<<"Scenario #"<<oo<<":"<<endl;
		cout<<cnt<<endl;
		if(oo!=n) cout<<endl;
	}
	return 0;
}



