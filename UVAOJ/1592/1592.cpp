/*************************************************************************
    > File Name: 1592.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月19日 星期二 09时26分47秒
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

const int maxn=90;


typedef struct pos{
	int row;
	int col1;
	int col2;
}pos;

map<string,int> IDCache;
map<pair<int,int>,pos> pairMap;
vector<string> strCache;
//set<pair<int,int> > IDSet;


int strMem[10010][15];

int ID(string s)                    //给每个字符串映射到一个唯一的ID上
{
    if(IDCache.count(s)) return IDCache[s];
    strCache.push_back(s);
    return IDCache[s]=strCache.size();
}

void readStr(char* s,int idest,int jdest,int* Mem)
{
    string dests;
    int len=strlen(s);
    char* p=s;
    char* q=s;
	int cnt=1;
    for(int i=0;i<len;i++)
    {
        if(*q==',')
        {
            *q='\0';
			dests=p;
			//cout<<"String <"<<dests<<"> is mapped to"<<ID(dests)<<endl;   DEBUG INFO
			Mem[cnt++]=ID(dests);
			p=q+1;
		}
		q++;
	}
	dests=p;
	//cout<<"String "<<dests<<"is mapped to"<<ID(dests)<<endl; DEBUG INFO
	Mem[cnt++]=ID(dests);
}

int main(void)
{
	int row,col;
	char s[maxn];
	while(scanf("%d%d",&row,&col)!=EOF)
	{
        strCache.clear();
        pairMap.clear();
        IDCache.clear();
		getchar();					//要用getchar吃回车 别忘了 without this  the programme will have severe mistake
		for(int i=1;i<=row;i++)
		{
			gets(s);
			readStr(s,i,col,strMem[i]);
			//printf("row is %d\n",row);
		}

	//	for(int i=1;i<=row;i++)
	//	{
	//		for(int j=1;j<=col;j++)
	//		{
	//			printf("%d ",strMem[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	//DEBUG
		int ok=0;
		for(int j=1;j<=col && !ok;j++)
		{
			for(int k=j+1;k<=col && !ok;k++)
			{
				pairMap.clear();
				for(int i=1;i<=row && !ok;i++)
				{
					pair<int,int> p=make_pair(strMem[i][j],strMem[i][k]);
					//cout<<"<"<<p.first<<","<<p.second<<">"<<endl; //DEBUG
					if(pairMap.count(p) /* pairMap[p].row!=i && pairMap[p].col1==j && pairMap[p].col2==k*/)
					{
						cout<<"NO"<<endl<<pairMap[p].row<<" "<<i<<endl<<j<<" "<<k<<endl;
						ok=1;
						break;
					}
					else
					{
						pairMap[p].row=i;
						pairMap[p].col1=j;
						pairMap[p].col2=k;
					}
				}
			}
		}
		if(ok==0) cout<<"YES"<<endl;
	}
	return 0;
}