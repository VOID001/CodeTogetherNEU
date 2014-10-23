#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int N=13,n=20;

double random()
{
    return (double)rand()/RAND_MAX;
}


int random(int m)
{
    return abs((int)(random()*(m-1)+0.5));
}

int main(void)
{
    int random(int m);
    srand(time(NULL));
    freopen("input.txt","w",stdout);
    printf("%d\n",N);
    int S,nA,IFI;
    for(int oo=1;oo<=N;oo++)
    {
        n=random(20)+1;
        printf("%d\n",n);
        for(int k=1;k<=n;k++)
        {
            S=random(100000)+1;
            IFI=random(100000)+1;
            nA=random(100000)+1;
            printf("%d %d %d",S,IFI,nA);
            printf("\n");
        }
    }

}
