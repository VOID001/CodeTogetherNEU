#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<long long>v;
    long long  j;
    int a[55];
    long long A[55];
    for(int i=0;i<=50;i++)
    {
        A[i]=1;
        for(int j=1;j<=i;j++)
        {
            A[i]*=2;
        }
    }
    while(scanf("%lld",&j)!=EOF)
    {
        memset(a,0,sizeof(a));
        v.clear();
        int oo=0;
        while(j)
        {
            a[oo]=j%2;
            j/=2;
            oo++;
        }
        oo--;
        for(int j=oo;j>=0;j--)
        {
            if(a[j])
            {
                v.push_back(A[j]);
            }
        }
        sort(v.begin(),v.end());
        for(vector<long long>::iterator ii=v.begin();ii!=v.end();ii++)
        {
            if(ii!=v.begin()) printf(" ");
            printf("%lld",*ii);
        }
        printf("\n");
    }
}
