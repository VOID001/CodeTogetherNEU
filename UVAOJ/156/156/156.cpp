#define LOCAL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 1010
int n;
char dict[MAX][22];
char odict[MAX][22];
char solu[MAX][22];

void read_in();
void solve();
int cmp_char(const void*a, const void*b);
int cmp_string(const void*a, const void*b);

int main(void)
{
	memset(dict, 0, sizeof(dict));
	memset(odict, 0, sizeof(odict));
	memset(solu, 0, sizeof(solu));
	read_in();
	solve();
	system("pause");
	return 0;
}

void read_in()
{
	n = 0;
	while (scanf("%s", odict[n++]))
	{
		if (odict[n - 1][0] == '#') return;
		char tmpch[30] = "";
		strcpy(tmpch, odict[n - 1]);
		int len = strlen(tmpch);
		for (int i = 0; i < len; i++) tmpch[i]=tolower(tmpch[i]);
		qsort(tmpch, len, sizeof(char), cmp_char);
		strcpy(dict[n - 1], tmpch);
	}
	return;
}

int cmp_char(const void*a, const void *b)
{
	char *A = (char*)a;
	char *B = (char*)b;
	return *A - *B;
}

int cmp_string(const void*a, const void*b)
{
	char* A = (char*)a;
	char* B = (char*)b;
	return strcmp(A, B);
}

void solve()
{
	int cnt = 0;
	char tmpch[30];
	for (int i = 0; i < n-1; i++)
	{
		strcpy(tmpch, odict[i]);
		int len = strlen(tmpch);
		for (int oo = 0; oo < len; oo++) tmpch[oo]=tolower(tmpch[oo]);
		qsort(tmpch, len, sizeof(char), cmp_char);
		int ok = 1;
		for (int oo = 0; oo < n; oo++)
		if (!strcmp(tmpch, dict[oo]) && oo != i){ ok = 0; break; }
		if (ok){ strcpy(solu[cnt], odict[i]); cnt++; }
	}
	qsort(solu, cnt, sizeof(solu[0]), cmp_string);
	for (int oo = 0; oo < cnt; oo++)
		printf("%s\n", solu[oo]);
	return;
}