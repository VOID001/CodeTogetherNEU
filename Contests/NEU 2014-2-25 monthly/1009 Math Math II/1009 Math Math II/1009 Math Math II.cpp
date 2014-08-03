#include<stdio.h>
#include<string.h>
#define MAX 50000
struct node
{
	long p;
	long n;
	node()
	{
		n = 0;
	}
};
long prime[MAX];
bool flag[MAX];
node stc[1000];
long num1 = 0, num2;

void init();
bool X_judge(long n, long m);
void Div_Ion(long m);

int main()
{
	init();
	long n, m, i;
	while (scanf("%ld%ld", &n, &m) == 2)
	{
		for (i = 0; i<1000; i++)
			stc[i].n = 0;
		if (n <= 1 && m>1)
		{
			printf("%ld does not divide %ld!\n", m, n);
			continue;
		}
		if (m == 0)
		{
			printf("%ld does not divide %ld!\n", m, n);
			continue;
		}
		if (n >= m)
		{
			printf("%ld divides %ld!\n", m, n);
			continue;
		}
		Div_Ion(m);
		if (X_judge(n, m))
			printf("%ld divides %ld!\n", m, n);
		else
			printf("%ld does not divide %ld!\n", m, n);
	}
	return 0;
}

void init()
{
	unsigned long i, j;
	memset(flag, 0, sizeof(flag));
	for (i = 2; i<50000; i++)
	{
		if (!flag[i])
		{
			prime[num1++] = i;
			for (j = i*i; j<50000; j = j + i)
				flag[j] = true;
		}
	}
}


bool X_judge(long n, long m)
{
	long i, sum, temp;
	for (i = num2 - 1; i >= 0; i--)
	{
		sum = 0;
		temp = stc[i].p;
		while (n >= temp)
		{
			sum = sum + n / temp;
			temp = temp*stc[i].p;
		}
		if (sum<stc[i].n)
			return false;
	}
	return true;
}

void Div_Ion(long m)
{
	long i;
	num2 = 0;
	for (i = 0; prime[i] * prime[i] <= m; i++)
	{
		if (m%prime[i] == 0)
		{
			stc[num2].p = prime[i];
			stc[num2].n++;
			m = m / prime[i];
			while (m%prime[i] == 0)
			{
				stc[num2].n++;
				m = m / prime[i];
			}
			num2++;
		}
		if (m == 1)
			break;
	}
	if (m>1)
	{
		stc[num2].p = m;
		stc[num2].n++;
		num2++;
	}
}
