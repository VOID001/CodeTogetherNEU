/*************************************************************************
    > File Name: G.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月23日 星期六 13时05分01秒
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
	//	int len=strlen(s);
		int num1,num2,num3;
		char op1[2];
		char op2[2];
		int res;
		scanf("%d%s%d%s%d",&num1,op1,&num2,op2,&num3);
		//if(op1[0]=='/+' || op1[0]=='-')
		//{
		//	if(op2[0]== '*' || op2[0]=='/' || op2[0]=='%')
		//	{
		//		if(op[1]=='+' && op2
		//	}
		//}
		if(op1[0]=='+' && op2[0]=='+')
			res=num1+num2+num3;
		if(op1[0]=='+' && op2[0]=='-')
			res=num1+num2-num3;
		if(op1[0]=='+' && op2[0]=='*')
			res=num1+num2*num3;
		if(op1[0]=='+' && op2[0]=='/')
			res=num1+num2/num3;
		if(op1[0]=='+' && op2[0]=='%')
			res=num1+num2%num3;

		if(op1[0]=='-' && op2[0]=='+')
			res=num1-num2+num3;
		if(op1[0]=='-' && op2[0]=='-')
			res=num1-num2-num3;
		if(op1[0]=='-' && op2[0]=='*')
			res=num1-num2*num3;
		if(op1[0]=='-' && op2[0]=='/')
			res=num1-num2/num3;
		if(op1[0]=='-' && op2[0]=='%')
			res=num1-num2%num3;

		if(op1[0]=='*' && op2[0]=='+')
			res=num1*num2+num3;
		if(op1[0]=='*' && op2[0]=='-')
			res=num1*num2-num3;
		if(op1[0]=='*' && op2[0]=='*')
			res=num1*num2*num3;
		if(op1[0]=='*' && op2[0]=='/')
			res=num1*num2/num3;
		if(op1[0]=='*' && op2[0]=='%')
			res=num1*num2%num3;
		//	for(int i=0;i<len;i++)
		if(op1[0]=='/' && op2[0]=='+')
			res=num1/num2+num3;
		if(op1[0]=='/' && op2[0]=='-')
			res=num1/num2-num3;
		if(op1[0]=='/' && op2[0]=='*')
			res=num1/num2*num3;
		if(op1[0]=='/' && op2[0]=='/')
			res=num1/num2/num3;
		if(op1[0]=='/' && op2[0]=='%')
			res=num1/num2%num3;
		//	{
		//		if(s[i]>='0' && s[i]<='9')
		if(op1[0]=='%' && op2[0]=='+')
			res=num1%num2+num3;
		if(op1[0]=='%' && op2[0]=='-')
			res=num1%num2-num3;
		if(op1[0]=='%' && op2[0]=='*')
			res=num1%num2*num3;
		if(op1[0]=='%' && op2[0]=='/')
			res=num1%num2/num3;
		if(op1[0]=='%' && op2[0]=='%')
			res=num1%num2%num3;
		//		{
		//			if(op1=='#')
		//				num1=num1*10+s[i]-'0';
		//			else
		//			{
		//				if(op2=='#')
		//					num3=num3*10+s[i]-'0';
		//				if(op2!='#')
		//					num2=num2*10+s[i]-'0';
		//			}
		//		}
		//		else if(s[i] != ' ';
		//		{
		//			if(op1=='#') op1=s[i];
		//			else if(op2=='#') op2=s[i];
		//		}
		//	}
		printf("%d\n",res);
	}
	return 0;
}
