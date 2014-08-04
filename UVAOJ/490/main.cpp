#include<stdio.h>
#include<string.h>

#define MAX 120

char s[MAX][MAX]={"",""};
int main(void)
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int oo=0;
    int max=0;
    memset(s,0,sizeof(s));
    while(gets(s[oo])!=NULL)
    {

        //printf("input recieved\n");
        if(max<strlen(s[oo])) max=strlen(s[oo]);
        oo++;
    }
    //printf("max=%d",oo);' '
    for(int i=0;i<oo;i++)
        for(int j=0;j<max;j++)
            if(!s[i][j]) s[i][j]=' ';

    for(int j=0;j<max;j++)
        {
            for(int i=oo-1;i>=0;i--)
            {
                //if (s[i][j]==' ') printf("&");
                printf("%c",s[i][j]);
            }
            printf("\n");
        }
    return 0;
}

/**到现在我还没看出来这道题为什么要这么输出 。。。。。。**/
/** 重定向千万千万要关了 ！！！！！！！！****/
