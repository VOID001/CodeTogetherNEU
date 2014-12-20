#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
typedef long long LL;
const LL N=16000000;

LL p[N];
bool prime[N];
LL k=1;

void isprime()
{
    LL i,j;
    p[0]=1;
    memset(prime,true,sizeof(prime));
    for(i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i;j<N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    p[1]=3;p[2]=4;
}

typedef struct
{
    LL m[2][2];
}Matrix;

Matrix per={1,0,0,1};
Matrix a={1,1,1,0};

Matrix multi(Matrix a,Matrix b,LL MOD)
{
    Matrix c;
    LL i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c.m[i][j]=0;
            for(k=0;k<2;k++)
            {
                c.m[i][j]+=a.m[i][k]*b.m[k][j];
                c.m[i][j]%=MOD;
            }
        }
    }
    return c;
}

Matrix matrix_mod(LL k,LL MOD)
{
    Matrix p=a,ans=per;
    while(k)
    {
        if(k&1)
        {
            ans=multi(ans,p,MOD);
            k--;
        }
        k>>=1;
        p=multi(p,p,MOD);
    }
    return ans;
}

int main()
{
    LL K,X,M,t,i,ret,r;
    isprime();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&K,&X,&M);
        Matrix ans;

        for(i=p[K];;i++)
        {
            ans=matrix_mod(i-1,X);
            if((ans.m[0][0]%X==0))
            {
                r=i;
                break;
            }
        }
        ans=matrix_mod(i-1,M*X);
        ret=ans.m[0][0]/X;
        printf("%lld\n",ret);
    }
    return 0;
}
