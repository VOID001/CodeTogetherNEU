/*************************************************************************
    > File Name: 136.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com
    > Created Time: 2014年08月18日 星期一 20时43分09秒
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
typedef long long LL;

const int coeff[3]={2,3,5};


int main(void)
{
    priority_queue<LL,vector<LL>,greater<LL> > pque;
    set<LL> s;
    pque.push(1);
    s.insert(1);
    for(int i=1;;i++)
    {
        LL x=pque.top();
        pque.pop();
        if(i==1500)
        {
            printf("The 1500'th ugly number is %I64d\n",x);
            break;
        }
        else
        {
            for(int i=0;i<3;i++)
            {
                LL x2=x*coeff[i];
                if(!s.count(x2))
                {
                    s.insert(x2);
                    pque.push(x2);
                }
            }
        }
    }
    return 0;
}
