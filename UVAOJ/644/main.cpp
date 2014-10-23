//#define LOCAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>          //qsort include
#define MAX 1000

char code[15][10];

void judge(int oo);
int cmp_string(const void* _a, const void*_b);


int main(void)
{
    #ifdef LOCAL
        freopen("644.in","r",stdin);
    #endif // LOCAL
    long long count=1;
    int oo=0;
    while(scanf("%s",code[oo])!=EOF)
    {
        if(code[oo][0]=='9')
        {
                printf("Set %lld ",count++);
                judge(oo);            //еп╤ойг╥Я©иртdecode
                oo=0;
                memset(code,'\0',sizeof(code));
        }
        else
        {
            oo++;
        }
    }

    return 0;
}

void judge(int oo)
{
    qsort(code,oo,sizeof(code[0]),cmp_string);
    //int decode=0;
    int decode[15]={0};
    int ok=1;
    //for(int i=0;i<oo;i++) printf("%s\n",code[i]);
    for(int i=0;i<oo-1;i++)
    {
        int len=strlen(code[i]);
        for(int j=0;j<len;j++)
            if(code[i][j]!=code[i+1][j]) {decode[i]=1;break;}

    }
    for(int i=0;i<oo-1;i++) if(!decode[i]) {ok=0;break;}
    if(ok) printf("is immediately decodable\n");
    if(!ok) printf("is not immediately decodable\n");
    return ;
}

int cmp_string(const void* _a, const void* _b)
{
    char *a=(char*) _a;
    char *b=(char*) _b;
    return strcmp(a,b);
    //else return strlen(a)-strlen(b);
}

/**WA的原因 ：qsort参数使用毛草- -**/
