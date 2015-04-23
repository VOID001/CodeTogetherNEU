/*************************************************************************
    > File Name: D.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2015年03月22日 星期日 13时10分29秒
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
const int maxn=150;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORI(l,r) for(int i=(l);i>=(r);i--)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORJ(l,r) for(int j=(l);j>=(r);j--)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int validate(char a)
{

	if(a>='A' && a<='Z') return 1;
	if(a>='a' && a<='z') return 2;
	if(a>='0' && a<='9') return 3;
	return -1;
}

void increment(char* str)
{
	int len=strlen(str);
	bool ok=0;
	int carry=0;
	for(int i=len-1;i>=0 || carry;i--)
	{
		if(carry==0 && i>=0)
		{
			int type=validate(str[i]);
			if(type!=-1)
			{
				ok=1;
				if(type==1)
				{
					if(str[i]=='Z'){str[i]='A';carry=1;}
					else {str[i]++;carry=0;}
				}
				else if(type==2)
				{
					if(str[i]=='z'){str[i]='a';carry=2;}
					else {str[i]++;carry=0;}
				}
				else if(type==3)
				{
					if(str[i]=='9'){str[i]='0';carry=3;}
					else {str[i]++;carry=0;}
				}
				if(carry==0) break;
			}
		}
		else if(carry!=0)
		{
			int type=-1;
			int j;
			for(j=i;j>=0;j--)
			{
				type=validate(str[j]);
				if(type!=-1) break;
			}
			int tmp=j;
			if(type==-1)
			{ 
				//printf("HEREA\n");
				FORJ(len-1,(i<0?0:i+1))
				{
					str[j+1]=str[j];
				}
				if(carry==1) str[i+1]='A';
				else if(carry==2) str[i+1]=='a';
				else if(carry==3) str[i+1]='1';
				carry=0;
			}
			else
			{
				if(type==1)
				{
					if(str[j]=='Z'){str[j]='A';carry=1;}
					else {str[j]++;carry=0;}
				}
				else if(type==2)
				{
					if(str[j]=='z'){str[j]='a';carry=2;}
					else {str[j]++;carry=0;}
				}
				else if(type==3)
				{
					if(str[j]=='9'){str[j]='0';carry=3;}
					else {str[j]++;carry=0;}
				}
			}
			i=tmp;
			if(carry==0) break;
		}
		//else if(carry!=0 && i<0)
		//{
		//	FORJ(len-1,0)
		//	{
		//		str[j+1]=str[j];
		//	}
		//	if(carry==1) str[0]='A';
		//	else if(carry==2) str[0]=='a';
		//	else if(carry==3) str[0]='1';
		//	carry=0;
		//}
		//else if(carry!=0 && i>=0)
		//{
		//	bool found=0;
		//	FORJ(i,0)
		//	{
		//		int type=validate(str[j]);
		//		if(type!=-1)
		//		{
		//			found=1;
		//			//printf("DEBUG: found j=%d type=%d\n",j,type);
		//			if(type==1)
		//			{
		//				if(str[j]=='Z'){str[j]='A';carry=1;}
		//				else {str[j]++;carry=0;}
		//			}
		//			else if(type==2)
		//			{
		//				if(str[j]=='z'){str[j]='a';carry=2;}
		//				else {str[j]++;carry=0;}
		//			}
		//			else if(type==3)
		//			{
		//				if(str[j]=='9'){str[j]='0';carry=3;}
		//				else {str[j]++;carry=0;}
		//			}	
		//			break;
		//		}
		//	}
		//	if(!found)
		//	{
		//		FORJ(len-1,i+1)
		//		{
		//			str[j+1]=str[j];
		//		}
		//		if(carry==1) str[i+1]='A';
		//		else if(carry==2) str[i+1]=='a';
		//		else if(carry==3) str[i+1]='1';
		//		carry=0;
		//	}
		//	if(carry==0) break;
		//}
	}
	if(!ok)
	{
		str[len-1]++;
	}
	printf("%s\n",str);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	char str[maxn];
	while(T--)
	{
		int n;
		MEMSET0(str);
		scanf("%s%d",str,&n);
		FORi(0,n)
		{
			increment(str);
		}
		printf("\n");
	}
	return 0;
}
