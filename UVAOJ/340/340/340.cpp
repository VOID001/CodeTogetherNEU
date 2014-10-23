#define LOCAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1010


int main(void)
{
#ifdef LOCAL
	freopen("340.in", "r", stdin);
#endif
	int srclst[MAX];
	int pwdlst[MAX];
	int tmplst[MAX];
	int n;
	int game = 1;
	while (1)
	{
		memset(srclst, 0, sizeof(srclst));
		memset(pwdlst, 0, sizeof(pwdlst));
		memset(tmplst, 0, sizeof(tmplst));
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			scanf("%d", &srclst[i]);
		printf("Game %d:\n", game++);
		while (1)
		{
			for (int i = 0; i < n; i++)
				scanf("%d", &pwdlst[i]);
			if (pwdlst[0] == 0) break;
			//开始判断
			for (int i = 0; i < n; i++) tmplst[i] = srclst[i];			//tmplst 作为一个副本
			int p, q;
			p = 0; q = 0;
			for (int i = 0; i < n; i++)
			{
				if (pwdlst[i] == tmplst[i])
				{
					p++;
					pwdlst[i] = -1;
					tmplst[i] = -1;					//用 -1 表示已找过
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (pwdlst[j] == tmplst[i] && pwdlst[j] != -1)
					{
						q++;
						pwdlst[j] = -1;
						tmplst[i] = -1;
					}
				}
			}
			printf("    (%d,%d)\n", p, q);
		}
	}

	return 0;
}