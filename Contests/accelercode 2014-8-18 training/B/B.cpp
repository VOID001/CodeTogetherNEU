/*************************************************************************
    > File Name: B.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月18日 星期一 12时45分49秒
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

LL arr[10010];

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int no;
		int cnt;
		scanf("%d%d",&no,&cnt);
		LL sum=0;	
		for(int i=0;i<cnt;i++)
		{
			scanf("%lld",&arr[i]);
			sum+=arr[i];
		}
		int comm;
		LL  i;
		int ok=1;
		for( i=1;i<=sum;i++)
		{
			ok=1;
			if(sum%i) continue;
			LL tmpsum=0;
			for(LL j=0;j<cnt;j++)
			{
				tmpsum+=arr[j];
				if(tmpsum==i)
				{
					tmpsum=0;
				}
				else if(tmpsum>i) {ok=0;break;}
			}
			if(ok)
			{
				cout<<no<<" "<<i<<endl;
				break;
			}	
		}

	}
	return 0;
}
