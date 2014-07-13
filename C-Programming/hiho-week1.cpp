#include<iostream>
#include<stdio.h>
#include<string.h>

const int MAX=1000001;
using namespace std;

bool isPalindrome(char* head,char* end);

int getMxLenPalindrome(char* str);

void debug_print(char* a,char* b);

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
	int maxn=1;
	int tmp=0;
	char* pta=str;
	char* ptb=str;
	int len=strlen(str);
	while(*pta!='\0')
	{
		ptb=pta+1;			//Two Pointers judge Palindrome		
		char* tmpptb=ptb;
		char* tmppta=pta;
		if(*tmppta==*tmpptb)		// There is another condition exist
		{
			tmppta=tmppta-maxn/2;
			tmpptb=tmpptb+maxn/2;
			while( tmppta>=str && *tmpptb!='\0' && isPalindrome(tmppta,tmpptb))
			{
				tmp=tmpptb-tmppta+1;
				maxn=maxn>tmp?maxn:tmp;
			//	cout<<"DEBUG PALINDROME#1 FOUND LEN "<<tmp<<endl;
			//	debug_print(tmppta,tmpptb);
				tmppta--;
				tmpptb++;
			}
		}
		else				//pta!=ptb indicates the Palindrome stirnglen must be an odd number
		{
			tmppta=pta-maxn/2;
			tmpptb=pta+maxn/2;
			while(isPalindrome(tmppta,tmpptb)&& tmppta>=str && *tmpptb!='\0')
			{
				int tmp=tmpptb-tmppta+1;
				maxn=maxn>tmp?maxn:tmp;
			//	cout<<"DEBUG PALINDROME#2 FOUND LEN "<<tmp<<endl;
			//	debug_print(tmppta,tmpptb);
				tmppta--;
				tmpptb++;
			}
		}
		pta++;
	}
	return maxn;
}


