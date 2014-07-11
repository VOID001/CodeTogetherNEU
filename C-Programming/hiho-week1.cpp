/*************************************************************************
    > File Name: hiho-week1.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月10日 星期四 22时42分40秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>

const int MAX=1000001;
using namespace std;

bool isPalindrome(char* head,char* end);

int getMxLenPalindrome(char* str);

int main(void)
{
	int N=0;
	int res=0;
	char str[MAX];
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",str);
		res=getMxLenPalindrome(str);
		printf("%d\n",res);
	}
	return 0;
}

bool isPalindrome(char* head,char* end)
{
	while(head<=end)	
	{
		if(*head==*end) 
		{
			head++;
			end--;
		}
		else return false;
	}
	return true;
}

int getMxLenPalindrome(char* str)
{
	int maxn=0;
	char* pta=str;
	char* ptb=str;
	int len=strlen(str);
	while(*pta!='\0')
	{
		ptb=pta+1;
		while(*ptb!='\0')
		{
			if(*pta==*ptb) 
			{
				if(isPalindrome(pta,ptb)) 
				{
					int tmp=ptb-pta+1;
					//printf("DEBUG: PALIN FOUND LEN=%d\n",tmp);
					maxn=maxn>tmp?maxn:tmp;
				}
			}
			ptb++;	 
		}
		pta++;
	}
	return maxn;
}
