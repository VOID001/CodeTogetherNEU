#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
 
typedef long long LL;
 
int a[3001];
 
int main(void)
{
    LL res;
    int n;
    LL sum;
    LL left;
    LL right;
    while(scanf("%d",&n)!=EOF)
    {
        res=0;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            left=right=0;
            for(int j=0;j<i;j++)
            {
                left=left+a[j];
            }
            right=sum-left-a[i];
            res=(res+left*a[i]*right)%400823823;
        }
        cout<<res%400823823<<endl;
    }
    return 0;
}
/**************************************************************
    Problem: 1456
    User: 20133870
    Language: C++
    Result: 正确
    Time:1652 ms
    Memory:1280 kb
****************************************************************/
