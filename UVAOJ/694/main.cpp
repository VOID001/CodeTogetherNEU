#include<stdio.h>

#define MAX 1000

int counter=0;

int collatz(long long n,long long limit);

int main(void)
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int times,cases;
    cases=1;
    long long a,b;
    while(scanf("%lld %lld",&a,&b))
    {
        counter=1;
        if(a<0 && b<0) break;
        times=collatz(a,b);
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",cases,a,b,times);
        cases++;
    }
    return 0;
}

int collatz(long long n,long long limit)
{
    while(n>1)
    {
        if(n%2==0)
        {
            n/=2;
        }
        else
        {
            n=3*n+1;
        }
        if(n>limit) break;
        counter++;
    }
    return counter;
}

/**问题想的时候正确思路！！！！ freopen别忘了去掉 **/
/**多想 仔细读题 ！**/
