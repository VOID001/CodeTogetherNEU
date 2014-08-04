#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int N=20,n=20;
double random()
{
    return (double)rand()/RAND_MAX;
}

long long random(long long m)
{
    return (long long)(rand()*(m-1)+0.5);
}



int main(void)
{
    srand(time(NULL));
    freopen("input.txt","w",stdout);
    printf("%d\n",N);
    long long S,nA,IFI;
    for(int oo=1;oo<=N;oo++)
    {
        n=random(20)+1;
        printf("%d\n",n);
        for(int k=1;k<=n;k++)
        {
            printf("%lld %lld %lld",random(100000),random(100000),random(100000));
            printf("\n");
        }
    }

}
