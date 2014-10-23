/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月23日 星期六 13时24分18秒
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


int arr[300]={0,1 ,5 ,4 ,1 ,4 ,5 ,5 ,6 ,0 ,4 ,6 ,0 ,6 ,6 ,0 ,2 ,0 ,1 ,6 ,0 ,0 ,1 ,5 ,6 ,3 ,0 ,6 ,6 ,0 ,1 ,4 ,6 ,5 ,6 ,6 ,0 ,2 ,4 ,5 ,0 ,6 ,6 ,0 ,4 ,3 ,0 ,3 ,4 ,4 ,5 ,6 ,3 ,5 ,6 ,5 ,5 ,6 ,1 ,6 ,0 ,5 ,6 ,6 ,0 ,4 ,5 ,2 ,6 ,5 ,5 ,6 ,0 ,3 ,5 ,4 ,5 ,5 ,6 ,1 ,3 ,4 ,6 ,5 ,5 ,6 ,3 ,2 ,6 ,2 ,3 ,3 ,4 ,5 ,2 ,4 ,5 ,4 ,4 ,5 ,0 ,5 ,6 ,4 ,5 ,5 ,6 ,3 ,4 ,1 ,5 ,4 ,4 ,5 ,6 ,2 ,4 ,3 ,4 ,4 ,5 ,0 ,2 ,3 ,5 ,4 ,4 ,5 ,2 ,1 ,5 ,1 ,2 ,2 ,3 ,4 ,1 ,3 ,4 ,3 ,3 ,4 ,6 ,4 ,5 ,3 ,4 ,4 ,5 ,2 ,3 ,0 ,4 ,3 ,3 ,4 ,5 ,1 ,3 ,2 ,3 ,3 ,4 ,6 ,1 ,2 ,4 ,3 ,3 ,4 ,1 ,0 ,4 ,0 ,1 ,1 ,2 ,3 ,0 ,2 ,3 ,2 ,2 ,3 ,5 ,3 ,4 ,2 ,3 ,3 ,4 ,1 ,2 ,6 ,3 ,2 ,2 ,3 ,4 ,0 ,2 ,1 ,2 ,2 ,3 ,5 ,0 ,1 ,3 ,2 ,2 ,3 ,0 ,6 ,3 ,6 ,0 ,0 ,1 ,2 ,6 ,1 ,2 ,1 ,1 ,2 ,4 ,2 ,3 ,1 ,2 ,2 ,3 ,0 ,1 ,5 ,2 ,1 ,1 ,2 ,3 ,6 ,1 ,0 ,1 ,1 ,2 ,4 ,6 ,0 ,2 ,1 ,1 ,2 ,6 ,5 ,2 ,5 ,6 ,6 ,0 ,1 ,5 ,0 ,1 ,0 ,0 ,1 ,3 ,1 ,2 ,0 ,1 ,1 ,2 ,6 ,0 ,4 ,1 ,0 ,0 ,1 ,2 ,5 ,0 ,6 ,0 ,0 ,1 ,3 ,5 ,6 ,1 ,0 ,0};


int main(void)
{
	int N;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		////int res=N/42;
		//int sumtmp=res*6;
		//int mod=N%42;
		//for(int i=1;i<=mod;i++)
		//{
		//	sumtmp+=arr[i];
		//}
		switch(arr[N%294])
		{
			case 0:
				printf("Saturday\n");
				break;
			case 1:
				printf("Sunday\n");
				break;
			case 2:
				printf("Monday\n");
				break;
			case 3:
				printf("Tuesday\n");
				break;
			case 4:
				printf("Wednesday\n");
				break;
			case 5:
				printf("Thursday\n");
				break;
			case 6:
				printf("Friday\n");
				break;
		}
	}
	return 0;
}
