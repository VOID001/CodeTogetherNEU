#include<stdio.h>
#include<string.h>
int num[100001];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
       int n,m,k,sum=0;
       scanf("%d%d",&n,&m);
       int i;
       memset(num,0,sizeof(num));
       for(i=1;i<=2*m;i++)
       {
           scanf("%d",&k);
           num[k]++;
       }
       for(i=1;i<=n;i++)
       {
           sum+=num[i]%2;
       }
       if(sum==0||sum==2) printf("0\n");
       else printf("%d\n",(sum-2)/2);
    }
    return 0;
}
