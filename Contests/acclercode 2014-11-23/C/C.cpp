/*************************************************************************
    > File Name: C.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年11月23日 星期日 12时45分30秒
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

const int maxn=10100;
char str[maxn];
int used[26];
int k=0;
int poseven[maxn];
int posodd[maxn];
int topodd;
int topeven;
int main(void)
{
	while(scanf("%s%d",str,&k)!=EOF)
	{
		memset(used,0,sizeof(used));
		int numofq=0;
		int len=strlen(str);
		int oddnum=0,evennum=0;
		topodd=topeven=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]!='?')
			{
				used[str[i]-'a']=1;
				
			}
			else
			{
				if((i+1)%2)  //Odd 
				{
					posodd[topodd]=i;
					topodd++;
				}
				else
				{
					poseven[topeven]=i;
					topeven++;
				}
				numofq++;
			}
		}
		int count=0;
		for(int i=0;i<26;i++)
		{
			if(used[i]) count++;
		}
		if(k>count+numofq) 
		{
			printf("-1\n");
		}
		else
		{
			int needk=k-count;
			//while(numofq)
			//{
			//	if(str[i]=='?')
			//	{
			//		if((i+1)%2)			//Odd
			//		{
			//			if(needk==0) str[i]='z';
			//			else
			//			{
			//				int j;
			//				for(j=25;j>=0;j--)
			//				{
			//					if(!used[j]) break;
			//				}
			//				str[i]='a'+j;
			//				used[j]=1;
			//				needk--;
			//			}
			//		}
			//		else
			//		{
			//			if(needk==0) str[i]='a';
			//			else
			//			{
			//				int j;
			//				for(j=0;j<26;j++)
			//				{
			//					if(!used[j]) break;
			//				}
			//				str[i]='a'+j;
			//				used[j]=1;
			//				needk--;
			//			}
			//		}
			//		numofq--;
			//	}
			//	i++;
			//}
			//
			while(topeven || topodd)
			{
				if(needk>0)
				{
					int oddc,evenc;
					int i,j;					//I to save the val of evencanfill  J save oddcanfill
					for(i=0;i<26;i++)
					{
						if(!used[i]) 
						{
							evenc=i;
							break;
						}
					}
					for(j=25;j>=0;j--)
					{
						if(!used[j])
						{
							oddc=j;
							break;
						}
					}
					if(abs(oddc-25)<evenc)
					{
						//We need to change oddc
						if(topodd)
						{
							str[posodd[topodd-1]]='a'+j;
							used[j]=1;
							topodd--;
						}
						else				//Only can fill topeven
						{
							str[poseven[topeven-1]]='a'+i;
							used[i]=1;
							topeven--;
						}
					}
					else
					{
						if(topeven)
						{
							str[poseven[topeven-1]]='a'+i;
							used[i]=1;
							topeven--;
						}
						else				//Only can fill topeven
						{
							str[posodd[topodd-1]]='a'+j;
							used[j]=1;
							topodd--;
						}
					}
					needk--;
				}
				else
				{
					while(topodd)
					{
						str[posodd[topodd-1]]='z';
						topodd--;
					}
					while(topeven)
					{
						str[poseven[topeven-1]]='a';
						topeven--;
					}
				}
			}
			printf("%s\n",str);
		}

	}
	return 0;

}

