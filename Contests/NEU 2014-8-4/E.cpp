#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
const int MAX=10000;

LL facarr[MAX];

LL fac(LL a)
{
	if(facarr[a]) return facarr[a];
	if(a==0 || a==1 )return facarr[a]=1;
	else
	{
		return facarr[a]=fac(a-1)*a;
	}
}

int main(void)
{
	int P;
	cin>>P;
	memset(facarr,0,sizeof(facarr));
	while(P--)
	{
		int N;
		int num;
		LL res;
		LL k;
		res=1;
		scanf("%d%d%lld",&num,&N,&k);
		for(int i=1;i<=k;i++)
		{
			res*=(N-i);
		}
		res*=fac(N-k);
		cout<<num<<" "<<res<<endl;
	}
	return 0;
}


