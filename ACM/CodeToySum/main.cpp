#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000002

const int s=1000000;

int vis[MAX];

int main (void)
{
	int N;
	int sel;
	int sum=0;
	while(scanf("%d",&N)!=EOF)
	{
		printf("%d\n",N);
		memset (vis,0,sizeof(vis));
		for(int i=0;i<N;i++)
		{
			scanf("%d",&sel);
			vis[sel]=1;
			sum+=(sel-1);
		}
		int tmpsum=0;
		int cnt=0;
		int pta=1,ptb=s;
		int oo=1;
		while(pta<ptb && cnt<N)
		{
			if(!vis[pta] && vis[ptb]==1)					//Pointer a point to a element in the set X
			{
				vis[pta]=2;
				if(cnt) printf(" ");
				printf("%d",pta);
				cnt++;
			}
			else if(vis[pta]==1 && !vis[ptb])
			{
				vis[ptb]=2;
				if(cnt) printf(" ");
				printf("%d",ptb);
				cnt++;
			}
			else if(vis[pta]==1 && vis[ptb]==1)
			{
				for(oo;oo<=s/2;oo++)
				{
					if((vis[oo] || vis[s+1-oo])==0)
					{
						if(cnt) printf(" ");
						printf("%d",oo);
						cnt++;
						printf(" %d",s+1-oo);
						cnt++;
						vis[oo]=vis[s+1-oo]=2;
						break;
					}
				}
			}
			pta++;
			ptb--;
		}
		printf("\n");
	}
}
