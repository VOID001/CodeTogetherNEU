#define LOCAL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 501

void dfs(int curn, int curm);
void read_in();
void solve();
int ok;
int dm[4] = {1,0,-1,0};
int dn[4] = {0,-1,0,1};
char board[MAX][MAX];
int n, m, T;

int main(void)
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		read_in();
		solve();
	}
	return 0;
}

void read_in()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);
	return ;
}

void solve()
{
	ok = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;j++)
		if (ok && board[i][j] == 'B') dfs(i, j);
		if (!ok) break;
	}
	if (ok) printf("YES\n");
	if (!ok) printf("NO\n");
	return;
}

void dfs(int curn, int curm)
{
	int White = 2;
	for (int oo = 0; oo < 4; oo++)
	{
		if(board[curn + dn[oo]][curm + dm[oo]];)
	}
}