#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;
 
#define N 1000000001  
typedef long long LL;
  
  
//void init()  
//{  
//    int i, j;  
//    for(i = 1; i < N; i++)  
//        phi[i] = i;  
//  
//    for(i = 2; i < N; i++)  
//        if(i == phi[i]) //此时i为素数  
//            for(j = i; j < N; j += i)  //j累加i  
//                phi[j] = (phi[j] / i) * (i - 1); //j有因子i,而且i是素数,正是欧拉函数  
//}  

const int mod=1000000007;



int main(void)
{
    LL count=0;
    LL n,k;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        count=0;
        if(k==2)
        {
            printf("1\n");
        }
        else if(k>2) printf("0\n");
        else 
        {
            LL fac;
            for(fac=2;fac<sqrt(n);fac++)
            {
                if(!(n%fac))
                {
                    count+= 2*(n/fac-1)*(fac-1);
                    count=count%mod;
                }
            }
            if(fac*fac==n) count+=(n/fac-1)*(fac-1);
            int tmp=n;
            for(int k=2;k<=sqrt(n);k++)
            {
                if(!(n%k)) 
                {
                    tmp=tmp/k*(k-1);
                    while(!(n%k)) n=n/k;
                }
            }
            if(n!=1) tmp=tmp/n*(n-1);
            count+=2*tmp;
            printf("%I64d\n",count%mod);
        }
    }
    return 0;
}
