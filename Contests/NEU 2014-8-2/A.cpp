#include<iostream>
#include<cmath>
using namespace std;
 
int main(void)
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<abs(a-b)<<endl;
    }
    return 0;
}
/**************************************************************
    Problem: 1451
    User: 20133870
    Language: C++
    Result: 正确
    Time:211 ms
    Memory:1268 kb
****************************************************************/
