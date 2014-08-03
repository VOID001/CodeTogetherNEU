#define LOCAL
#include<math.h>
#include<stdio.h>
#include<string.h>
#define MAX  214748
#define MAXINT 2147483647
int prime[MAX];

int main(void)
{
	memset(prime, 0, sizeof(prime));
	int cur = 0;
	for (int i = 2; i <= MAXINT; i++)
	{
		int ok = 1;
		for (long long j = 2; j*j <= i; j++)
		{
			if (i%j == 0) ok = 0; break;
		}
		if (ok) prime[cur++] = i;
	}
}