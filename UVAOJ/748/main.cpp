//#define LOCAL

#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 2000

char ground[10];
int n;
int big1[MAX],big2[MAX],res[2*MAX];
bool xiaoshu=0;
int x=0;
int main(void)
{
    #ifdef LOCAL
        freopen("748.in","r",stdin);
    #endif // LOCAL

    while(scanf("%s%d",ground,&n)!=EOF)
    {
        memset(big1,0,sizeof(big1));
        memset(big2,0,sizeof(big2));
        memset(res,0,sizeof(res));
        char s[10]="";
        if(strchr(ground,'.')!=NULL)
        {
            xiaoshu=1;
            x=strchr(ground,'\0')-strchr(ground,'.')-1;       //浮点位移 m
            x=n*x;
            /**去掉小数点操作**/                                              //总位移
            *strchr(ground,'.')='\0';
            strcat(s,ground);
            *strchr(ground,'\0')='#';
            strcat(s,strchr(ground,'#')+1);
        }
        else
        {
        strcpy(s,ground);
        }
        /**去除小数点完毕**/
        int len=strlen(s);
        for (int i=0;i<len;i++) {big1[i]=s[len-i-1]-'0'; big2[i]=big1[i];}
        for(int oo=1;oo<n;oo++)
        {
            for(int i=0;i<MAX;i++)
            {
                int addon=0;
                for(int j=0;j<MAX;j++)
                {
                    int tmp=res[i+j]+big1[j]*big2[i]+addon;
                    res[i+j]=tmp%10;
                    addon=tmp/10;
                }
            }
            for(int k=0;k<MAX;k++) big2[k]=res[k];
            if(oo!=n-1)memset(res,0,sizeof(res));
        //for(int k=0;k<MAX;k++) printf("%d",big1[k]);
        //printf("\n");
        }
        int ok=0;
        char stmp[2*MAX];
        memset(stmp,0,sizeof(stmp));
        if(xiaoshu==1)                          //这是一个小数
        {
            int m=0;
            for(int i=MAX-1;i>=0;i--)
            {
                if(res[i]) ok=1;
                if(ok) {sprintf(stmp+m,"%d",res[i]);m++;}
            }
        }
        ok=0;
        char sres[MAX];
        memset(sres,0,sizeof(sres));
        char *pt=stmp+strlen(stmp);             //stmp 里存的是没有小数点的数值
        int tlen=strlen(stmp);
        if(xiaoshu)
        {
            for(int oo=tlen+1;oo>=0;oo--)
            {
                if(oo!=tlen-x+1) sres[oo]=*(pt--);
                else sres[oo]='.';
            }
        sres[tlen+1]='\0';
        /**for(int i=MAX-1;i>=0;i--)
        {
            if(res[i]) ok=1;
            if(ok) printf("%d",res[i]);
        }**/
        printf("%s\n",sres);
        }
        else printf("%s\n",stmp);
    }

    return 0;
}



