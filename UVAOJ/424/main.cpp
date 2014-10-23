//#define LOCAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
char bign[MAX];
int num[MAX];
int res[MAX];
int addon=0;
int maxlen=0;
int main(void)
{
    #ifdef LOCAL
        freopen("424.in","r",stdin);
        freopen("424.out","w",stdout);
    #endif // LOCAL
    memset(bign,0,sizeof(bign));
    memset(res,0,sizeof(res));
    //memset(addon,0,sizeof(addon));
    while(scanf("%s",bign))
    {
        addon=0;
        if(!strcmp("0",bign)) break;
        int len=strlen(bign);
        if (maxlen<len) maxlen=len;
        memset(num,0,sizeof(num));
        for(int i=0;i<len;i++)  num[i]=bign[len-i-1]-'0';
        //for(int i=0;i<len;i++) printf("%d",num[i]);
        //printf("\n");
        for(int i=0;i<MAX;i++)
        {
            int tmp=res[i]+num[i]+addon;
            res[i]=(res[i]+num[i]+addon)%10;
            addon=tmp/10;
        }
    }
    int pre0=0;
    for(int i=MAX-1;i>=0;i--)
    {
        if(res[i]) pre0=1;
        if(pre0) printf("%d",res[i]);
    }
    printf("\n");
    return 0;
}
