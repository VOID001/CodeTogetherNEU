/*************************************************************************
  > File Name: E.cpp
  > Author: VOID_133
  > QQ: 393952764
  > Mail: zhangjianqiu13@gmail.com 
  > Created Time: 2014年08月18日 星期一 12时14分28秒
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int no;
		char num[100];
		int strnum[100];
		scanf("%d%s",&no,num);
		int len=strlen(num);
		for(int i=0;i<len;i++)
		{
			strnum[i]=num[i]-'0';
		}
		int ok=next_permutation(strnum,strnum+len);
		printf("%d ",no);
		if(ok)
		{
			for(int i=0;i<len;i++)
				printf("%d",strnum[i]);
		}
		else
			printf("BIGGEST");
		cout<<endl;
	}
	return 0;
}
