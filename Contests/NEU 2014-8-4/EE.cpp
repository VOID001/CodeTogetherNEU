
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
LL c[20][20];
LL a[20],ans;
int n,k;
void init()
{
	a[0]=a[1]=1;
	c[1][0]=c[1][1]=1;
	for(int i=2;i<=17;i++)
	{
		a[i]=a[i-1]*i;
		c[i][i]=1;
		c[i][0]=1;
		for(int j=1;j<i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}
int main() 
{
	int newss;
	int p;
	init();
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d%d%d",&newss,&n,&k);
		LL ans=a[n];
		for(int i=1;i<=k;i++)
			if(i&1) ans-=c[k][i]*a[n-i];
			else ans+=c[k][i]*a[n-i];
		printf("%d %lld\n",newss,ans);
	}
	return 0;
} 
