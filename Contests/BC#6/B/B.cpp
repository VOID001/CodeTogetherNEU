#include<iostream>
#include<cmath>
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

int main(void)
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int x=sqrt(n);
        bool ok =0;
        for(int j=x;j>=1;j--)
        {
            int res=n-x*x;
            if(res<k) 
            {
                if(x*x>=k*(k-1)/2-res+k) {ok=1 ;break;}
                else continue;
            }
            if(res > k)
            {
                if(x*x>=k*(k-1)/2) 
                {
                    ok=1;
                    break;
                }
                else continue;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
