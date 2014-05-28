//注意下标
#include<iostream>
#include<stdio.h>
#include<string.h>

const int MAX = 10000;
using namespace std;

int arr[MAX + 1];
int len = 0;					//数字位数
bool no;
int arrt[MAX + 1];
void arrMulti(int base, int fac)
{
	int addi = 0;
	for (int i = MAX, j = 1; j <= len; j++, i--)
	{
		int tmp = arr[i] * fac + addi;
		addi = tmp / base;
		arr[i] = tmp%base;
		if (j == len && addi > 0) //如果数组的位数都不一样 那么就不进行判断了
		{
			no = 1;
			for (int t = i; t <= MAX - 1; t++)
				arrt[t] = base - 1;			//让这个数直接进位
		}
	}
	return;
}
void arrPlus(int arrr[], int base)
{
	int addi = 0;
	int i = MAX - 1;
	int tmp = arrr[i] + addi + 1;
	addi = tmp / base;
	arrr[i] = tmp%base;
	while (addi)
	{
		i--;
		//tmp = arrr[i]+addi+1;
		tmp = arrr[i] + addi;
		addi = tmp / base;
		arrr[i] = tmp%base;
		if (MAX - i + 1 > len) len++;
	}
	return;
}
bool cmpsame(int arr1[], int arr2[])
{
	if (arr1[MAX - len + 1] != arr2[MAX]) return false;
	for (int i = 1; i < len; i++)
	{
		if (arr1[MAX - len + i + 1] != arr2[MAX - len + i]) return false;
	}
	return true;
}

int main(void)
{
	int bs, rfac, fac;
	while (scanf("%d%d%d", &bs, &rfac, &fac) != EOF)
	{
		memset(arr, 0, sizeof(arr));
		memset(arrt, 0, sizeof(arrt));
		len = 2;
		int fl = 1;
		arr[MAX] = arrt[MAX] = rfac;
		while (fl)
		{
			arrPlus(arr, bs);
			arrPlus(arrt, bs);
			arrMulti(bs, fac);
			if (!no && cmpsame(arr, arrt)) fl = 0;
			else
			{
				memset(arr, 0, sizeof(arr));
				for (int i = 0; i < len; i++)
				{
					arr[MAX - i] = arrt[MAX - i];
				}
			}
			no = false;
		}
		printf("%d\n", len);
	}
	return 0;
}
