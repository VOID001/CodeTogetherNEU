/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月24日 星期日 13时56分53秒
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
	int N;
	int tN;
	int cnt=1;
	while(scanf("%d",&N))
	{
		if(N%4==0)
		{
			printf("%d %d\n",0,N);
			tN=N;
			cnt=1;
			while(tN>=4)
			{
				if(cnt!=1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4;
			}
			printf("\n");
			tN=N-1;
			cnt=1;
			while(tN>=4)
			{
				if(cnt!=1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4;
			}
			if(cnt!=1) printf(" ");
			printf("1 3 2 %d\n",N);
		}
		else if(N%4==1)
		{
			tN=N;
			cnt=1;
			while(tN>=4)
			{
				if(cnt==1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4;
			}
			if(cnt==1) printf("#");
			printf("1\n");
			tN=N-1;
			cnt=1;
			while(tN>=4)
			{
				if(cnt==1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4;
			}
			if(cnt==1) printf("#");
			printf("%d\n",N);
		}
		else if(N%4 ==2)
		{
			tN=N;
			cnt=1;
			while(tN>=4)
			{
				if(cnt==1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4;
			}
			if(cnt==1) printf("#");
			printf("1 2\n");
			tN=N-1;
			cnt=1;
			while(tN>=4)
			{
				if(cnt==1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4
			}
			if(cnt==1) printf("#");
			printf("1 %d\n",N);
		}
		else if(N%4==3)
		{
			tN=N;
			cnt=1;
			while(tN>=4)
			{
				if(cnt==1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4
			}
			if(cnt==1) printf("#");
			printf("1 3 2\n");
			tN=N-1;
			cnt=1;
			while(tN>=4)
			{
				if(cnt==1) printf("#");
				printf("%d %d %d %d",tN-3,tN-2,tN,tN-1);
				cnt++;
				tN-=4
			}
			if(cnt==1) printf("#");
			printf("1 2 %d\n",N);
		}
	}
	return 0;
}
