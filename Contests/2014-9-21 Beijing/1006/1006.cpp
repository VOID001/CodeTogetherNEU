/*************************************************************************
  > File Name: 1006.cpp
  > Author: VOID_133
  > ################### 
  > Mail: ################### 
  > Created Time: 2014年09月21日 星期日 13时01分31秒
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

int dis[2*100000+1];

int main(void)
{
	int T;
	scanf("%d",&T);
	int N,M,L;
	for(int kk=1;kk<=T;kk++)
	{
		int pos=0;
		int cur=0;
		int steps=0;
		int maxpos=0;
		scanf("%d%d%d",&N,&M,&L);
		for(int i=0;i<N;i++)
		{
			scanf("%d",dis+i);
		}
		sort(dis,dis+N);
		while(pos<=M)
		{
			if(pos+L>=M) {steps++;printf("It Jumped onto the bank\n");break;}	// Jumped out
			bool ok=0;						//If not Ok means there is no stone to jump to at the situation
			for(int i=cur;i<N;i++)
			{
				if(pos+L>=dis[i])
				{
					ok=1;
					if(i==N-1 || pos+L<dis[i+1])
					{
						int tmp=pos;
						printf("Frog is in the %d pos,It will Jump to the stone at %d pos,The Stone we can place is then from %d To %d\n",pos,dis[i],tmp+L,tmp+2*L);
						pos=dis[i];
						cur=i;steps++;
						maxpos=tmp+L; 
					}
				}
			}
			if(!ok)
			{
				printf("Frog is in th %d pos,A Stone Should be placed at %d pos.After the placement the frog will on the new stone\n",pos,maxpos+1);
				steps++;
				int tmp=maxpos;
				maxpos=pos+L;
				pos=tmp+1;
			}
		}
		printf("Case #%d: ",kk);
		printf("%d\n",steps);
	}
}
