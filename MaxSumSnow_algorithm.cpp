#include<stdio.h>
int ch[110];
int main()
{
    int n;
    int i;
    int sum,maxsum;
    while(scanf("%d",&n)!=EOF,n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ch[i]);
        }
        maxsum=-1;
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=ch[i];
            maxsum=(sum>maxsum)?sum:maxsum;
            if(sum<0)
            {
                sum=0;
            }
        }
        printf("%d\n",maxsum);
    }
    return 0;
}
//最大序列的一个O(n)算法~供参考
