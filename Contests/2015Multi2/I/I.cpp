/*************************************************************************
    > File Name: I.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 23 Jul 2015 03:26:02 PM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int used;

int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n <= 3 || n == 5) 
		{
			printf("-1\n");
		}
		else if (n == 4)
		{
			printf("1 * 2\n5 + 3\n6 + 4\n");
		}
		else if( n <= 12 )
		{
			int i = 1;
			int j = n + 1;
			int sum = 0;
			printf("%d + %d\n",1,2);
			i = 3;
			sum = 2 * n;
			while(sum <= 24 - n)
			{
				printf("%d + %d\n",i,j);
				sum += n;
				i++;
				j++;
			}
			if(sum != 24)
			{
				printf("%d + %d\n",i,i+1);
				sum += 2;
				int k = j + 1;
				i += 2;
				while(sum < 24)
				{
					printf("%d + %d\n",i,k);
					i++;
					k++;
					sum++;
				}
				printf("%d / %d\n",k,i);
				i++;
				k++;
				printf("%d + %d\n",k,j);
				j = k + 1;					// A[j] = 24 
			
			}
			if( i < n)
			{
				printf("%d - %d\n",i,i+1);
				i+=2;
				int kk = j + 1;
				for(;i<=n;i++)
				{
					printf("%d * %d\n",i,kk);
					kk++;
				}
				printf("%d + %d\n",j,kk);
			}
		}
		else if( n <= 24)
		{
			int i = 1;
			int j = n;
			int sum = n;
			if(n == 23)
			{
				printf("%d / %d\n",i,i+1);
				i+=2;
				printf("%d + %d\n",j,j+1);
				j += 2;
			}
			else
			{
				if(sum != 24)
				{
					printf("%d + %d\n",i,i+1);
					int k = j + 1;
					i += 2;
					for(int cnt = 1;cnt <= 22 - n; cnt++)
					{
						printf("%d + %d\n",i,k);
						i++;
						k++;
						sum++;
					}
					printf("%d / %d\n",k,i);
					i++;
					k++;
					printf("%d + %d\n",k,j);
					j = k + 1;					// A[j] = 24 

				}
			}
			if( i < n - 1 )
			{
				printf("%d - %d\n",i,i+1);
				i+=2;
				int kk = j + 1;
				for(;i<n;i++)
				{
					printf("%d * %d\n",i,kk);
					kk++;
				}
				printf("%d + %d\n",j,kk);
			}
		}
		else if( n == 25)
		{
			printf("1 + 2\n");
			printf("3 + 26\n");
			printf("4 + 27\n");
			printf("5 + 28\n");
			printf("6 + 29\n");
			printf("7 + 30\n");
			printf("8 + 31\n");
			printf("9 + 32\n");
			printf("10 + 33\n");
			printf("11 + 34\n");
			printf("12 + 35\n"); 
			printf("13 + 36\n");
			printf("14 + 37\n");
			printf("15 + 38\n");
			printf("16 + 39\n");
			printf("17 + 40\n");
			printf("18 + 41\n");
			printf("19 + 42\n");
			printf("20 + 43\n");
			printf("21 + 44\n");
			printf("22 + 45\n");
			printf("23 + 46\n");
			printf("24 + 47\n");
			printf("48 / 25\n");
		}
		else if( n == 26)
		{
			printf("1 + 2\n");
			printf("27 / 3\n");
			printf("4 + 5\n");
			printf("29 + 6\n");
			printf("30 + 7\n");
			printf("31 + 8\n");
			printf("32 + 9\n");
			printf("33 + 10\n");
			printf("34 + 11\n");
			printf("35 + 12\n");
			printf("36 + 13\n");
			printf("37 + 14\n");
			printf("38 + 15\n");
			printf("39 + 16\n");
			printf("40 + 17\n");
			printf("41 + 18\n");
			printf("42 + 19\n");
			printf("43 + 20\n");
			printf("44 + 21\n");
			printf("45 + 22\n");
			printf("46 + 23\n");
			printf("47 + 24\n");
			printf("48 + 25\n");
			printf("49 / 26\n");
			printf("50 + 28\n");
		}
		else
		{
			int i = 1;
			int j = n;
			printf("%d + %d\n",i,i+1);
			j++;
			i+=2;
			while( i <= 24 )
			{
				printf("%d + %d\n",i,j);
				j++;
				i++;
			}
			printf("%d / %d\n",j,i);
			j++;
			i++;
			printf("%d - %d\n",i,i+1);
			i+=2;
			int k = j + 1;				// A[k] = 0;
			while(i <= n)
			{
				printf("%d * %d\n",k,i);
				k++;
				i++;
			}
			printf("%d + %d\n",j , k);
		}
//		printf("===================%d====================================\n",n);
	}
	return 0;
}
