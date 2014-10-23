#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  

const int maxn=100000;  
typedef long long LL;  
LL mat[maxn+2][52];  
LL kk,k,p,r,c;  

void initialize()  
{  

	for(int i=0;i<=maxn;i++){ mat[i][0]=1;  }
	
	for(int i=1;i<=maxn;i++)  
		for(int j=1;j<=min(i,50);j++)  
			mat[i][j]=mat[i-1][j]+mat[i-1][j-1];  
}  




int main()  
{  
	initialize();  
	scanf("%lld",&k);  
	while(k--)  
	{  
		scanf("%lld%lld%lld%lld",&kk,&p,&r,&c);  
		LL ans=1;  
		for(int i=1;i<=(r-c);i++)  
			ans*=p;  
		if(c>r/2) c=r-c;  
		ans*=mat[r][c];  
		printf("%lld %lld\n",kk,ans);  
	}  
	return 0;  
}  
