#include<stdio.h>
int main()
{
    int T;
    int i,n;
    int ans,m,l;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            l=m;
            ans=ans^(m%(l+1));
        }
        if(ans==0)  printf("Brother\n");//��ȡ����ʤ
        else   printf("John\n");//��ȡ����ʤ
    }
    return 0;
}
