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

int arr[1010];
int sum;

int main(void)
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        sum=0;

        for(int i=0;i<T;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        sort(arr,arr+T);
        int mid=arr[(T+1)/2-1];
        int avg=sum/T;
        if(avg>=mid) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
