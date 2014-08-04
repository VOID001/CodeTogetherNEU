#include<stdio.h>

int main(void)
{
	long long sum = 0;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		long long s2, s3, s4;
		long long tmptot = 0;
		s2 = s3 = s4 = 0;
		for (long long i = 1; i <= n; i++)
		{
			s2 += i*i;
			s3 += i*i*i;
			s4 += i*i*i*i;
			tmptot += i;
		}
		long long r2, r3, r4;
		r2 = tmptot*tmptot - s2;
		r3 = tmptot*tmptot*tmptot - s3;
		r4 = tmptot*tmptot*tmptot*tmptot - s4;
		printf("%lld %lld %lld %lld %lld %lld\n", s2, r2, s3, r3, s4, r4);
	}
}