#include<stdio.h>
#include<ctype.h>
#include<string.h>

void decrypt(int a);

int main(void)
{
    int N;
    while(scanf("%d",&N) && N)
    {
        int a;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a);
            decrypt(a);
        }
        printf("\n");
    }
    return 0;
}

void decrypt(int a)
{
    char s[100];
    char res[100];
    int i=0;
    int mod;
    while(a)
    {
        mod=a%16;
        if(mod>=10) s[i++]= mod-10 +'a';
        else s[i++]= mod + '0';
        a/=16;
    }
    //for(int ptr=i;ptr<4;ptr++)
     //   s[ptr]='0';
    //printf("%s",s);
    int pt=0;
    for(int oo=i-1;oo>=0;oo--)
    {
        if( s[oo]>= '0' && s[oo]<= '9') res[pt++]=s[oo]-'0'+'A';
        else res[pt++]=s[oo];
        //res[pt++]=s[oo];
    }
    res[pt]='\0';
    printf("%s",res);
    return ;
}
