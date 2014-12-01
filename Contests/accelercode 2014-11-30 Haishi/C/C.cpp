/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月30日 星期日 12时26分03秒
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
const int B=10000;

int fib[12]={1,1,2,3,5,8,13,21,34,55,89};
int main(void)
{
	int sum=0;
	for(int i=1;i<=B;i++)
	{
		sum=0;
		int t=i;
		int count=1;
		while(t)
		{
			sum+=t%10*fib[count++];
			t/=10;
		}
		printf("%d\n",sum);
	}
	return 0;
}
