/*************************************************************************
    > File Name: JS.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月23日 星期六 12时46分58秒
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

typedef long long LL;

LL powLL(LL a,LL b)
{
	LL res=1;
	for(LL i=1;i<=b;i++)
	{
		res*=a;
	}
	return res;
}

int main(void)
{
	
	LL sum=0;
	//for(LL i=1;i<=100;i++)
	//{
		for(int j=1;j<=100;j++)
		{
			sum+=powLL(j,j);		
			printf("sum=%lld\t",sum);
			printf("%lld\n",sum%7);
		}
		//switch(sum%7)
		//{
		//	case 0:
		//		printf("Sat)
		//		break;
		//	case 1:
		//		break;
		//	case 2:
		//		break;
		//	case 3:
		//		break;
		//	case 4:
		//		break;
		//	case 5:
		//		break;
		//	case 6:
		//		break;
		//}
		//}
		return 0;
}
