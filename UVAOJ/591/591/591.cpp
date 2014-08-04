// 591.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
	int n;
	int arr[55];
	int sum;
	int count = 1;
	while (scanf("%d", &n) && n)
	{
		memset(arr, 0, sizeof(arr));
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		sum = sum / n;
		int times = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] - sum>0) times += (arr[i] - sum);
		}
		printf("Set #%d\n", count++);
		printf("The minimum number of moves is %d.\n\n", times);
	}
	return 0;
}

				