#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	int P;
	cin>>P;
	int N;
	double D,A,B,F;
	while(P--)
	{
		scanf("%d%lf%lf%lf%lf",&N,&D,&A,&B,&F);
		double time=D/(A+B);
		printf("%d %.2lf\n",N,time*F);
	}
	return 0;
}
