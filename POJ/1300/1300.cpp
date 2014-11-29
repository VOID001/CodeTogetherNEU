/*************************************************************************
    > File Name: 1300.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年10月25日 星期六 00时31分24秒
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

const int maxn=25;
int deg[maxn];

int main(void)
{
	char s[50];
	char inpstr[5000];
	while(scanf("%s",s) && strcmp(s,"ENDOFINPUT"))
	{
		if(!strcmp(s,"END")) continue;
		memset(deg,0,sizeof(deg));
		int sumdeg=0;
		int n,m;				//m is the first room ,total has n rooms
		scanf("%d%d",&m,&n);
		//printf("START %d %d\n",m,n);							//DBEUG
		getchar();				//Clear the Enter
		int nodenum=0;
		while(nodenum<n-1)
		{
			gets(inpstr);
			int len=strlen(inpstr);
			int inpnum=0;
			bool flag;
			//printf("%s\n",s);
			for(int i=0;i<=len;i++)
			{
				//INPUT READIN
				if(inpstr[i]==' '|| (inpstr[i]=='\0' && len))
				{
					//printf("%d ",inpnum);
					deg[nodenum]++;
					deg[inpnum]++;
					inpnum=0;
				}
				else
				{
					//printf("CHAR %c",inpstr[i]
					inpnum=inpnum*10+inpstr[i]-'0';
				}
			}
			nodenum++;
		}
		//Read in  END String
		gets(s);
		gets(s);
		/*for(int i=0;i<n;i++)
		{
			printf("DEG[%d]=%d\n",i,deg[i]);
		}*/
		bool isEuler=true;
		if(m==0)					//START FROM 0 and END to 0 NO ODD POINTS
		{
			for(int i=0;i<n;i++)
			{
				sumdeg+=deg[i];
				if(deg[i]%2)
				{
					isEuler=false;
					break;
				}
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				sumdeg+=deg[i];
				if(i==0 || i==m) continue;
				if(deg[i]%2)
				{
					isEuler=false;
					break;
				}
			}
			if(!(deg[0]%2 && deg[m]%2))
			{
				isEuler=false;
			}
		}
		if(isEuler) printf("YES %d\n",sumdeg/2);
		else printf("NO\n");
	}
	return 0;
}
