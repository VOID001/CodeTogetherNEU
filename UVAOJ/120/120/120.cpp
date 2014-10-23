//#define LOCAL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 40

int scan();
void solve();
void rev(int cur);

int pan[MAX];
int sorted[MAX];
int doo[2*MAX];
int n;
int cmp_int(const void* a, const void * b);
void ptres();
int main(void)
{
#ifdef LOCAL
	freopen("120.in", "r", stdin);
#endif
	int max;
	while (n=scan())
	{					//数据读入函数
		for (int i = 0; i < n; i++) { printf("%d", pan[i]); if (i != n - 1) printf(" ");  else printf("\n"); }
		solve();		//解决问题函数
		// DEBUG printf("LIST %d\n", n);
	}
	return 0;
}

int scan()
{
	int oo = 0;
	char c;
	while (1)
	{
		int st=scanf("%d", &pan[oo++]);
		if (st == EOF) return 0;
		c = getchar();
		if (c == '\n') return oo;
	}
}

void solve()
{
	int cnt = 0;								//记录doo的个数
	for (int oo = 0; oo < n; oo++)
	{
		sorted[oo] = pan[oo];
	}//get a copy
	qsort(sorted, n, sizeof(int), cmp_int);
	for (int cur = n - 1; cur >= 0; cur--)
	{
		if (pan[cur] != sorted[cur])			//从最底层开始一层层看 不一样的便执行交换操作
		{
			for (int i = 0; i <= cur; i++)
			{
				if (pan[i] == sorted[cur])
				{
					if (i != 0)
					{
						rev(i);
						printf("%d ", n - i);
					}
					rev(cur);
					printf("%d ", n - cur);
					printf("\n");
					ptres();
					break;
				}
			}
		}
	}
	printf("0");
}

int cmp_int(const void* a, const void *b)
{
	int *a_ = (int*)a;
	int *b_ = (int*)b;
	return *a_ - *b_;
}

void rev(int cur)
{
	int t;
	for (int oo = 0; oo <= cur / 2; oo++)
	{
		t = pan[oo];
		pan[oo] = pan[cur-oo];
		pan[cur - oo] = t;
	}
}
void ptres()
{
	for (int i = 0; i < n; i++) printf("%d ", pan[i]);
	printf("\n");
}