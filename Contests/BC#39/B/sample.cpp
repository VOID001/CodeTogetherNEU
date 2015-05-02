#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
int a[maxn],loc[maxn];
bool has[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n)) {
        memset(loc,0,sizeof loc);
        memset(has,0,sizeof has);
        int M = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d",a+i);
            loc[a[i]] = i;
            has[a[i]] = 1;
            M = max(M,a[i]);
        }
        int res = 0;
        for(int i = 1; i < n; i++) {
            int d = n+1,t = a[i];
            for(int j = t; j <= M; j += t) {
                if(has[j]){
                    if(loc[j]>i)d = min(d,loc[j]);
                }
            }
            if(d>n) d = 0;
            res += d;
        }
        printf("%d\n",res);
    }
    return 0;
}
