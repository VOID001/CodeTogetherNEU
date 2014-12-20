#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>

#define CL(arr, val) memset(arr, val, sizeof(arr))

#define lc l,m,rt<<1
#define rc m + 1,r,rt<<1|1
#define pi acos(-1.0)
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define lowbit(x)   (x)&(-x)
#define Read()  freopen("din.txt", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout)


#define M 137
#define N 115

using namespace std;


const int inf = 0x7f7f7f7f;
const int mod = 1000000007;

int ans,res;
int vote[N],c[N],b[N];
map<int,int>mp;
bool vt[N],vt2[N];
int n;

int getR(int k)
{
    for (int i = 2; i <= n; ++i)
    {
        if (b[i] >= k)
        {
           while (b[i] != k - 1)
           {
               int t1 = 0, t2 = inf;
               for (int j = 2; j <= n; ++j)
               {
                   if (!vt2[j] && mp[j] == i && c[j] < t2)
                   {
                       t1 = j;
                       t2 = c[j];
                   }
               }
               ans += t2; vt2[t1] = true;
               b[i]--; b[1]++;
           }
        }
    }
    return b[1];
}
int main()
{
//    Read();
    int T,i,j;
    int x;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        CL(vote,0); mp.clear();
        CL(vt,false);

        for (i = 2; i <= n; ++i)
        {
            scanf("%d",&x);
            mp[i] = x;  vote[x]++;//x的得票数
            if (x == 1) vt[i] = true;//i是否支持1
        }
        for (i = 2; i <= n; ++i) scanf("%d",&c[i]);

        res = inf;
        for (int k = vote[1]; k <= n; ++k)
        {
            if (k <= 1) continue;

            for (i = 1; i <= n; ++i) b[i] = vote[i];
            for (i = 1; i <= n; ++i) vt2[i] = vt[i];
            ans = 0;

            int no = getR(k);

            if (no == k)
            {
                for (j = 2; j <= n; ++j)//保证存在一个得票数小于等k - 2的来结束1的票
                {
                    if (b[j] <= k - 2) break;
                }
                if (j <= n)
                {
                    res = min(res,ans);
                }
            }
            else if (no < k)
            {
                while (no < k)//从没有支持1的人中选出所需糖果数最少的人贿赂得票
                {
                    int t1 = 0,t2 = inf;
                    for (i = 2; i <= n; ++i)
                    {
                        if (!vt2[i] && c[i] < t2)
                        {
                            t1 = i; t2 = c[i];
                        }
                    }
                    vt2[t1] = true;
                    ans += t2;
                    no++;
                }
                res = min(res,ans);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
