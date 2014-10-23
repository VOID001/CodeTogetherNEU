/*************************************************************************
    > File Name: baoliver.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月06日 星期三 19时42分39秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX =1000000;

int arr[MAX];
int deseq=0;

int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		deseq=0;
		for(int i=0;i<n;i++)
			cin>> arr[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
				if(arr[i]>arr[j]) deseq++;
		}
		cout << deseq<<endl;
	}
	return 0;
}
