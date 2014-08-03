#define MAX 10010
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;
int H[MAX];
int V[MAX];

int main(void)
{
	int lie = 0;
	while (scanf("%d", &N) != EOF)
	{
		memset(H, 0, sizeof(H));
		memset(V, 0, sizeof(V));
		lie = 0;
		for (int i = 1; i <=N; i++)
			scanf("%d", &H[i]);
		for (int i = 1; i <=N; i++)
			scanf("%d", &V[i]);
		//Judge//
		for (int i = 1; i <=N; i++)
		{
			if (V[i] == i) lie++;
			if (V[i]>i)
			{
				for (int oo = i + 1; oo <V[i]; oo++)
				{
					if (H[oo]>H[i]) { lie++; break; }
				}
			}
			if (V[i] < i)
			{
				for (int oo = i-1; oo > V[i]; oo--)
				{
					if (H[oo]>H[i]) { lie++; break; }
				}
			}
		}
		//-----//
		printf("%d\n", lie);
	}
}


//Accepted