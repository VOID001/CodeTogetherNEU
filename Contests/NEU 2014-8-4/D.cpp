#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAX=1000000;

typedef long long LL;

LL fib[MAX+1];

LL fibo(LL a)
{
	if(fib[a]) {cout<<fib[a]<<endl;return fib[a];}
	if(a==1 || a==2) return fib[a]=1;
	else
	{
		return fib[a]=fibo(a-1)+fibo(a-2);
	}
}

int main(void)
{
	int P;
	cin>>P;
	while(P--)
	{
		int n,m;
		int i;
		scanf("%d%d",&n,&m);
		memset(fib,0,sizeof(fib));
		fib[1]=fib[2]=1;
		for(i=3;i<=MAX;i++)
		{
			fib[i]=(fib[i-1]+fib[i-2])%m;
			if(fib[i]==fib[2] && fib[i-1]==fib[1]) break;

		}
		printf("%d %d\n",n,i-2);
	}
	return 0;

}

