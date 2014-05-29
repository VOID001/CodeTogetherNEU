#include<stdio.h>
#include<string.h>

const int MAX = 10000;
int main(void)
{
	int base, rfac, fac;
	int	arr[MAX + 1];
	while (scanf("%d%d%d", &base, &rfac, &fac) != EOF)
	{
		memset(arr,0,sizeof(arr));
		arr[MAX] = rfac;
		int ok = 1;
		int i = MAX;
		int addin = 0;
		int len = 1;
		if (rfac == 0 || fac == 1) len = 1;
		else
		{
			while (ok)
			{
				int tmp = arr[i] * fac + addin;
				addin = tmp / base;
				len++;
				arr[i - 1] = tmp%base;
				int tmpc = (arr[i - 1] * fac + addin);
				if (tmpc%base == arr[MAX] && tmpc < base) break;
				i--;
			}
		}
		printf("%d\n", len);
		for (int j = len - 1; j >= 0; j--)
		{
			printf("%d ", arr[MAX - j]);
		}
		printf("\n");
	}
}
