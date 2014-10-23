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

const int INF = 555555;

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int sum=0;
		int tmp;
		int tttttt=n;
		int maxn=-INF;
		while(n--)
		{
			scanf("%d",&tmp);
			sum+=tmp;
			maxn=max(maxn,tmp);
		}
		if(m>=tttttt) cout<<maxn<<endl;
		else
		{
			//cout<<"DDD"<<endl;
			int ok=sum%m;
			int avg=sum/m;
			if(ok) avg++;
			int ttt=max(avg,maxn);
			cout<<ttt<<endl;
		}
	}
	return 0;
}
