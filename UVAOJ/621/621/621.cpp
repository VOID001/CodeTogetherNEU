#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(void)
{
	//freopen("621.in", "r", stdin);
	long long n;
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++)
	{
		string s;
		int flag;
		cin >> s;
		if (s == "1" || s == "4" || s == "78") { printf("+\n");  continue; }
		else if (s[s.size() - 1] == '5' && s[s.size() - 2] == '3') { printf("-\n"); continue; }
		else if (s[0] == '9' && s[s.size() - 1] == '4') { printf("*\n");  continue; }
		else if (s[0] == '1' && s[1] == '9' && s[2] == '0') { printf("?\n");  continue; }
		
	}
	//system("pause");
	return 0;
}