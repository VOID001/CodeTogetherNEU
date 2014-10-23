#include<stdio.h>
#include<string.h>
#define MAX 10000
int M,N;


int main(void)
{
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        printf("%.6lf\n",(N*1.0)/(M*1.0+N*1.0));
    }
    return 0;
}
