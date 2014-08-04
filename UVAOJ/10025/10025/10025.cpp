//#define LOCAL
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define MAX 3000

void gen(int a);

#ifdef LOCAL
FILE *fp = fopen("gen.txt", "w");
#endif
int main(void)
{
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++)
	{
		int n;
		scanf("%d", &n);
		n = abs(n);
		int k = 1;
		while (1)
		{
			int S = (k + 1)*k / 2;
			if ((S - n) % 2==0 && S-n>=0) break;
			else k++;
		}
		printf("%d\n", k);
		if (i < cases - 1) printf("\n");
	}
}

void gen(int a)						//数据生成器
{
	int sum = 0;
	int add = 1;
	int op = 0;
	for (op = 0;; op++)
	{
		add = 1;
		sum = 0;
		int t = op;
		while (t!=0)
		{
			sum = t % 2 == 0 ? sum - add: sum + add;		//0代表 -  1代表 +
			add++;
			t /= 2;
			//printf("a=%d,op=%d,sum=%d\n",a,op ,sum);
			//system("pause");
		}
		if (sum == a) break;
	}
#ifdef LOCAL
	fprintf(fp, "f(%d)=%d\", a, add - 1");
#endif
#ifndef LOCAL
	printf("f(%d)=%d\n", a, add-1);
#endif
}

