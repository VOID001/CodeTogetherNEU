//#define LOCAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 510
#define SMA 260
int main(void)
{
    #ifdef LOCAL
        freopen("10106.in","r",stdin);
    #endif // LOCAL
    int big1[SMA],big2[SMA];
    int res[MAX];
    char s[SMA];
    while(scanf("%s",s)!=EOF)
    {
        int len1=strlen(s);
        memset(big1,0,sizeof(big1));
        memset(big2,0,sizeof(big2));
        memset(res,0,sizeof(res));
        for(int i=0;i<len1;i++) big1[i]=s[len1-i-1]-'0';
        scanf("%s",s);
        int len2 =strlen(s);
        for(int i=0;i<len2;i++) big2[i]=s[len2-i-1]-'0';
        for (int j=0;j<len2;j++)
        {
            int addon=0;
            for(int i=0;i<=len1;i++)
            {
                int tmp=res[i+j]+big2[j]*big1[i]+addon;
                res[i+j]=tmp%10;
                addon=tmp/10;
            }
        }
        int ok=0;
        for(int i=MAX-1;i>=0;i--)
        {
            if(res[i]) ok=1;
            if(ok) printf("%d",res[i]);
        }
        if(!ok) printf("0");
        printf("\n");
    }
    return 0;
}

/**Accepted With ONLY One Attempt**/
/** TIME Duration 25min **/
