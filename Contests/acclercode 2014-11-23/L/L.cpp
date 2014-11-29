/*************************************************************************
    > File Name: L.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月23日 星期日 12时24分16秒
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
	int X,Y,C;
	scanf("%d%d%d",&X,&Y,&C);
	if(X+Y<C) 
		printf("Impossible\n");
	else
		printf("%d %d\n",X,C-X);
	return 0;
}
