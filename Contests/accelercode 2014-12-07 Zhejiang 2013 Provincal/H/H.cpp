/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月07日 星期日 12时20分09秒
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

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int A,B,C;
		int minpoints=0;
		int maxpoints=0;
		scanf("%d%d%d",&A,&B,&C);
		int tot=A+B+C;
		int tmpA=A;
		int tmpB=B;
		int tmpC=C;
		for(int i=0;i<tot;i++)
		{
			if(tmpA>0)
			{
				minpoints+=300*(2*i+1);
				tmpA--;
			}
			else if(tmpB>0)
			{
				minpoints+=100*(2*i+1);
				tmpB--;
			}
			else if(tmpC>0)
			{
				minpoints+=50*(2*i+1);
				tmpC--;
			}
		}
		tmpA=A;
		tmpB=B;
		tmpC=C;
		for(int i=0;i<tot;i++)
		{
			if(tmpC>0)
			{
				maxpoints+=50*(2*i+1);
				tmpC--;
			}
			else if(tmpB>0)
			{
				maxpoints+=100*(2*i+1);
				tmpB--;
			}
			else if(tmpA>0)
			{
				maxpoints+=300*(2*i+1);
				tmpA--;
			}
		}
		printf("%d %d\n",minpoints,maxpoints);
	}
	return 0;
}
