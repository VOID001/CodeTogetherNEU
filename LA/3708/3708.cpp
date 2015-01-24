#include<cstdio>
#include<cstring>

const int maxn=1005;

double mydabs(double a)
{
	return a<0?-a:a;
}

int main(void)
{
  double posa[maxn];
  double posb[maxn];
  
  int m,n;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
	  double incre=360.00/n;
	  posa[0]=posb[0]=0.0;
	  for(int i=1;i<n;i++)
	  {
		  posa[i]=posa[i-1]+incre;
	  }
	  incre=360.00/(m+n);
	  for(int i=1;i<n+m;i++)
	  {
		  posb[i]=posb[i-1]+incre;
	  }
	  double sum=0;
	  for(int i=1;i<n;i++)
	  {
		  double minn=20000;
		  for(int j=1;j<n+m;j++)
		  {
			  if(minn>mydabs(posa[i]-posb[j])) minn=mydabs(posa[i]-posb[j]);
		  }
		  sum+=minn;
	  }
	  printf("%.4lf\n",(sum/360.00)*1.0*10000);
  }
  return 0;
}
