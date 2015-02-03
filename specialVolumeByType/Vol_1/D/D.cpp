/*************************************************************************
  > File Name: D.cpp
  > Author: VOID_133
  > ################### 
  > Mail: ################### 
  > Created Time: 2015年02月03日 星期二 10时44分27秒
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

const int maxn=18;

int inMat[maxn][maxn];
bool solveMat[maxn][maxn];
bool minMat[maxn][maxn];
int pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

int m,n;

void calc(int i,int j)
{
	int sum=solveMat[i][j]+solveMat[i-1][j]+solveMat[i][j-1]+solveMat[i][j+1];

	if(inMat[i][j] && sum%2) solveMat[i+1][j]=0;
	if(inMat[i][j] && !(sum%2)) solveMat[i+1][j]=1;
	if(!inMat[i][j] && sum%2) solveMat[i+1][j]=1;
	if(!inMat[i][j] && !(sum%2)) solveMat[i+1][j]=0;
}

bool check()
{
	for(int i=1;i<=n;i++)
	{
		int sum=solveMat[m][i]+solveMat[m][i-1]+solveMat[m][i+1]+solveMat[m-1][i];
		if(inMat[m][i]==1 && sum%2==0) return false;
		if(inMat[m][i]==0 && sum%2==1) return false;
	}
	return true;
}

int main(void)
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&inMat[i][j]);
			}
		}
		//Enumeration Start
		//
		bool ok=0;
		int minf=10000;
		for(int i=0;i<pow2[n];i++)
		{
			memset(solveMat,0,sizeof(solveMat));
			int t=i;
			int cnt=n;
			while(t)
			{
				solveMat[1][cnt--]=t%2;
				t>>=1;
			}

			for(int j=1;j<=m-1;j++)
			{
				for(int k=1;k<=n;k++)
				{
					calc(j,k);
				}
			}
			//printf("Solution %d\n",i);
			if(check())
			{
				ok=1;
				int tmp=0;
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=n;k++)
					{
						if(solveMat[j][k]) tmp++;
					}
				}
				if(tmp<minf)
				{
					for(int j=1;j<=m;j++)
					{
						for(int k=1;k<=n;k++)
						{
							minMat[j][k]=solveMat[j][k];
						}
					}
					minf=tmp;
				}
			}
			//DEBUG
		}
		if(!ok) {printf("IMPOSSIBLE\n");}
		else
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=n;k++)
				{
					printf("%d",minMat[j][k]?1:0);
					if(k!=n) printf(" ");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
