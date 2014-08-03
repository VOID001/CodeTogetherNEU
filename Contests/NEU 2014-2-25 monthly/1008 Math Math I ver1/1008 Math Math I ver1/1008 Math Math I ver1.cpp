#define MAX 214748364
#include<stdio.h>
#include<math.h>
#include<string.h>

bool isp[MAX];

int main(void)
{
	for (int i = 0; i < MAX; i++)
		isp[i] = true;
	isp[0] = isp[1] = false;
	for (int cur = 2; cur < MAX;cur++)
	{
		if (isp[cur])
		{
			for (int j = cur * 2; j < MAX; j += cur)
				isp[j] = false;
		}
	}
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		int dis[1000];
		int iL[1000];
		int iU[1000];
		int max = -1, min = 2013;
		int oo = 0;
		int np = 0;
		for (int i = a; i <= b; i++)
		{
			if (isp[i])
			{
				np++;
				for (int j = i+1; j <= b; j++)
				{
					if (isp[j])
					{
						iL[oo] = i;
						iU[oo] = j;
						dis[oo] = j - i;
						//printf("%d %d %d\n", iL[oo], iU[oo], dis[oo]);
						oo++;
						break;
					}
				}
			}
		}
		//printf("%d\n", oo);
		if (np < 2) printf("There are no adjacent primes.\n");
		else
		{
			int maxpos, minpos;
			for (int i = 0; i <oo; i++)
			{
				if (max<dis[i]) { maxpos = i; max = dis[i]; }
				if (min>dis[i]) { minpos = i; min = dis[i]; }
			}
			//printf("%d %d\n", min, max);
			printf("%d,%d are closest, %d,%d are most distant.\n", iL[minpos], iU[minpos], iL[maxpos], iU[maxpos]);
		}
	}
	
}

