#define LOCAL
#include<string.h>
#include<cstdio>
#include<cstdlib>

int cmp(const void *a, const void *b)
{
	char* a_ = (char*)a;
	char* b_ = (char*)b;
	return strcmp(a_, b_);
}

int main(void)
{
	char m[10];
	char n[10];
	char s[20];
	while (scanf("%s", s) != EOF)
	{
		m[0] = s[0] > s[5] ? s[5] : s[0]; m[1] = s[0] < s[5] ? s[5] : s[0];
		m[2] = s[1] > s[4] ? s[4] : s[1]; m[3] = s[1] < s[4] ? s[4] : s[1];
		m[4] = s[2] > s[3] ? s[3] : s[2]; m[5] = s[2] < s[3] ? s[3] : s[2];
		m[6] = '\0';
		n[0] = s[6] > s[11] ? s[11] : s[6]; n[1] = s[6] < s[11] ? s[11] : s[6];
		n[2] = s[7] > s[10] ? s[10] : s[7]; n[3] = s[7] < s[10] ? s[10] : s[7];
		n[4] = s[8] > s[9] ? s[9] : s[8]; n[5] = s[8] < s[9] ? s[9] : s[8];
		n[6] = '\0';
		qsort(m, 3, 2 * sizeof(char), cmp);
		qsort(n, 3, 2 * sizeof(char), cmp);
		if (!strcmp(m, n)) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}