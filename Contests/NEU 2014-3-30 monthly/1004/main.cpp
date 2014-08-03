#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int max_n=110;
int f[max_n][max_n],a[max_n],b[max_n],i,j,t,n1,n2,max;
int main(void)
{

    while(scanf("%d%d",&n1,&n2)!=EOF)
    {
    for(i=1;i<=n1;i++) scanf("%d",&a[i]);
    for(i=1;i<=n2;i++) scanf("%d",&b[i]);
    memset(f,0,sizeof(f));
    for(i=1;i<=n1;i++)
    {
    max=0;
        for(j=1;j<=n2;j++)
        {
        f[i][j]=f[i-1][j];
        if (a[i]>b[j]&&max<f[i-1][j]) max=f[i-1][j];
        if (a[i]==b[j]) f[i][j]=max+1;
        }
    }
    max=0;
    for(i=1;i<=n2;i++) if (max<f[n1][i]) max=f[n1][i];
    printf("%d\n",max);
    }
    return 0;
}
