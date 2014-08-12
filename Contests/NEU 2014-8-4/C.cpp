#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=1001;

int graph[MAX][MAX];
int adjin[MAX];
int	adjout[MAX];
int val[MAX];

int main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(graph,0,sizeof(graph));
		memset(adjin,0,sizeof(adjin));
		memset(adjout,0,sizeof(adjout));
		memset(val,0,sizeof(val));
		int K,M,P;
		scanf("%d%d%d",&K,&M,&P);
		while(P--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			graph[a][b]=1;
			adjout[a]++;
			adjin[b]++;	
		}
		////DEBUG****************************************
		//printf("M=%d\n",M);
		//for(int i=1;i<=M;i++)
		//{
		//	for(int j=1;j<=M;j++)
		//	{
		//		printf("%d ",graph[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("\n");
		//for(int i=1;i<=M;i++)
		//	printf("%d ",adjin[i]);
		//printf("\n");
		//for(int i=1;i<=M;i++)
		//	printf("%d ",adjout[i]);
		//printf("\n");
		////DEBUG****************************************
		for(int i=1;i<=M;i++)
		{
			if(adjin[i]==0) val[i]=1;
		}
		for(int i=1;;i++)
		{
			i=i%(M+1);
			if(val[i]==0) continue;
			if(val[M]) break;
				for(int j=1;j<=M;j++)
				{
					if(graph[i][j])
					{
						int maxval=1;
						int cnt=0;
						for(int k=1;k<=M;k++)
						{
							if(graph[k][j])
							{
								if(val[k]==maxval) cnt++;
								if(val[k]>maxval)
								{
									maxval=val[k];
									cnt=1;
								}
							}
						}
						if(cnt>1)
							val[j]=maxval+1;
						else
							val[j]=maxval;
					}
				}

		}
			printf("%d %d\n",K,val[M]);
	}
	return 0;
}

