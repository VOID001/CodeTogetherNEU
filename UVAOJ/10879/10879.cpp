#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int j = 1; j <= N; j++)
	{
		int num;
		scanf("%d", &num);
		int fac1, fac2;
		int flag = 0;
		for (long long i = 2; i*i <= num; i++)
		{
			if (num % i == 0 && flag == 0){ fac1 = i; flag = 1; continue; }
			if (num %i == 0 && flag == 1){ if (num / i == fac1)continue;  fac2 = i; break; }
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n", j, num, fac1, num / fac1, fac2, num / fac2);
	}
	return 0;
}