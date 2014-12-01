/*************************************************************************
    > File Name: G.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月30日 星期日 13时25分12秒
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

char str[1000010];
int T;

char valiad_32[39]="L:XXX;R:XXXXXXXXXX;C:XXXXXXXXXX;";
char valiad_21[23]="LXXRXXXXXXXXCXXXXXXXX";

bool is_valiad_32()
{
	//if(str[0]=='L' && str[1]==':' && str[5]==';' && str[6]=='R' && str[7]==':' && str[31]==';' && str[18]==';' && str[19]=='C' && str[20]=='C')
	int L,R,C;
	L=R=C=0;
	int flag=0;
	for(int i=0;i<32;i++)
	{
		if(valiad_32[i]!='X' && valiad_32[i]!=str[i])
		{
			return false;	
		}
		else if(valiad_32[i]!='X' && valiad_32[i]==str[i])
		{
			if(str[i]=='R') flag=1;
			if(str[i]=='C') flag=2;
		}
		else if(valiad_32[i]=='X')
		{
			if(str[i]>='0' && str[i]<='9')
			{
				if(flag==0)
					L=L*10+str[i]-'0';
				if(flag==1)
					R=R*10+str[i]-'0';
				if(flag==2)
					C=C*10+str[i]-'0';
			}
			else
			{
				return false;
			}
		}
	}
	printf("L%08XR%08XC%08X\n",L,R,C);
	return true;
}

bool is_valiad_21()
{
	long long  L,R,C;
	L=R=C=0;
	int flag=0;
	for(int i=0;i<21;i++)
	{
		if(valiad_21[i]!='X' && str[i]!=valiad_21[i])
		{
			return false;
		}
		else if(valiad_21[i]!='X' && str[i]==valiad_21[i])
		{
			if(str[i]=='R') flag=1;
			if(str[i]=='C') flag=2;
		}
		else if(valiad_21[i]=='X')
		{
			if(str[i]>='0' && str[i]<='9' || str[i]>='A' && str[i]<='F')
			{
				if(flag==0)
				{
					L=L*16+((str[i]>='0' && str[i]<='9')?(str[i]-'0'):(str[i]-'A'+10));
				}
				else if(flag==1)
				{
					R=R*16+((str[i]>='0' && str[i]<='9')?(str[i]-'0'):(str[i]-'A'+10));
				}
				else if(flag==2)
				{
					C=C*16+((str[i]>='0' && str[i]<='9')?(str[i]-'0'):(str[i]-'A'+10));
				}
			}
			else
			{
				return false;
			}
		}

	}
	printf("L:%03lld;R:%010lld;C:%010lld;\n",L,R,C);
	return true;
}

int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int i=1;i<=T;i++)
	{
		int valiad=1;
		//scanf("%s",str);
		gets(str);
		printf("Case #%d: ",i);
		int len=strlen(str);
		if(len!=32 && len!=21)
			valiad=0;
		else
		{
			if(len==32)
			{
				valiad=is_valiad_32();
			}
			else
			{
				valiad=is_valiad_21();
			}
		}
		if(!valiad) printf("invalid\n");
	}
}
