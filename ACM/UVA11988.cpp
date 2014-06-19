#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 200005;

int main(void)
{
	char s[MAX];
	char sin[MAX];
	while (scanf("%s", sin) != EOF)
	{
		memset(s, 0, sizeof(s));
		int len = strlen(sin);
		char* phead = &s[100000];
		char* pend = &s[100001];
		for (int i = 0; i < len; i++)
		{
			if (sin[i] != ']' && sin[i] != '[')
			{
				*pend = sin[i];
				pend++;
			}
			else
			{
				if (sin[i] == '[')
				{
					int j = 0;
					for (j = i; j <= len; j++)
					{
						if (sin[j] == '\0' || sin[j] == ']')
						{
							for (int k = j-1; sin[k] != '['; k--)
							{
								*phead = sin[k];
								phead--;
							}
							break;
						}
					}
					i = j;
				}
			}
		}
		*(pend + 1) = '\0';
		printf("%s\n",phead+1);
	}
}
