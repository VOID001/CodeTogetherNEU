/*************************************************************************
  > File Name: 107.cpp
  > Author: VOID_133
  > QQ: 393952764
  > Mail: zhangjianqiu13@gmail.com 
  > Created Time: 2014年08月04日 星期一 09时09分15秒
 ************************************************************************/
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>

const double esp=1e-9;

using namespace std;

typedef long long LL;

double myabs(double a)
{
	return a>0?a:-a;
}

int main(void)
{
	double H,W;
	while(scanf("%lf%lf",&H,&W) && H && W)
	{
		int i;
		double catnum=0;
		if(H==W && H==1) {printf("0 1\n"); continue;};
		for(i=1;;i++)
		{
			double tmpres=pow((1+pow(W,1.0/i)),i);
			if(myabs(tmpres-H)<esp) break;
		}
		double N=pow(W,1.0/i);
		double Hsum=0;
		for(int j=0;j<=i;j++)
		{
			Hsum+=H*pow(N/(N+1),j*1.0);
		}
		for(int j=0;j<=i-1;j++)
		{
			catnum+=pow(N,j);
		}
		//catnum=(pow(N,i)-1)/(N-1);
		//cout<<catnum<<" "<<H<<endl;
		printf("%.0lf %.0lf\n",catnum,Hsum);
	}
}


//考虑一下特殊情况就好
