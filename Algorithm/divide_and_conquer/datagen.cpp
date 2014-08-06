/*************************************************************************
    > File Name: datagen.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月06日 星期三 15时38分38秒
	> Content A generator for testing the Mergesort
 ************************************************************************/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(void)
{
	//freopen("randtest.in","r",stdout);
	srand(time(0));
	int casen =rand()%1000+1;
	for(int i=1;i<=casen;i++)
	{
		int datasize=rand()%10000+1;
		printf("%d\n",datasize);
		for(int j=1;j<=datasize;j++)
		{
			printf("%d ",rand()%10000+1);
		}
		printf("\n");
	}
	return 0;
}


