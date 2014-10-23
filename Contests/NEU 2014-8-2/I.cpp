#include<iostream>
using namespace std;
 
typedef long long LL;
LL quick_pow(LL a,LL b,LL mod)
{
    LL ans=1;
    a=a%mod;
    while(b)
    {
        if(b%2)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
 
int main(void)
{
    LL n;
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n;
        cout<<quick_pow(2,n-1,20140413)<<endl;
    }
    return 0;
}
/**************************************************************
    Problem: 1459
    User: 20133870
    Language: C++
    Result: 正确
    Time:1 ms
    Memory:1268 kb
****************************************************************/
