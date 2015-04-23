/*************************************************************************
    > File Name: A.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年04月23日 星期四 10时47分17秒
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
const int maxn=105;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

typedef struct PM{
	int first;
	int sec;
	int id;
}PM;

vector<PM> vec;

bool cmp(PM a,PM b)
{
	int fa=a.first-a.sec;
	int fb=b.first-b.sec;
	if(fa!=fb) return fa > fb;
	else if(a.sec!=b.sec) return a.sec < b.sec;
	else return a.id<b.id;
}

int main(void)
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		vec.clear();
		FORi(0,N)
		{
			PM tmp;
			scanf("%d%d",&tmp.first,&tmp.sec);
			tmp.id=i;
			vec.push_back(tmp);
		}

		sort(vec.begin(),vec.end(),cmp);
		for(vector<PM>::iterator it=vec.begin();it!=vec.end();it++)
		{
			if(it != vec.begin()) printf(" ");
			printf("%d",(*it).id);
		}
		printf("\n");
	}
}


/***************************************
 *    PID:5182
 *    Accepted
 *    Time used: 11min
 *
 * ************************************/
