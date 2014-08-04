#include<stdio.h>
#include<string.h>
#define MAX 1000

char get1[MAX];
char get2[MAX];
char get3[MAX];
char get4[MAX];

//Function Prototype
void auto_get(char *s);
char *auto_copy(char *s);
char *auto_copy2(char *s);
//END OF PROTOTYPE
int main(void)
{
    //freopen("input.txt","r",stdin);
    char s1[MAX]="";
    char s2[MAX]="";
    long long  cases;
    scanf("%lld",&cases);
    for(long long i=1;i<=cases;i++)
    {
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        memset(get1,0,sizeof(get1));
        memset(get2,0,sizeof(get2));
        memset(get3,0,sizeof(get3));
        memset(get4,0,sizeof(get4));
        if(i==1) getchar();                              //scanf 不读回车 而我跟上的gets就把那个回车给读入了 因此 要用getchar把回车读了先
        gets(s1);
        gets(s2);                               //获得两组输入
        auto_get(s1);                           //auto_get 获得 s2 s3 s4 s5=get1 get2 get3 get4
        //printf("%s\n%s\n%s\n%s",get1,get2,get3,get4);DEBUG
        char *res=auto_copy(s1);
        printf("%s\n",res);
        res=auto_copy2(s2);
        printf("%s\n",res);
    }
}

void auto_get(char *s)
{
    int len;
    len=strchr(s,'>')-strchr(s,'<');              //获得字段长度及<后第一个字符地址 别减反了！！哈
    if(len==1) get1[0]='\0';                      //考虑特殊情况  字符为空
    else
    {
        for(int i=1;i<len;i++)
        {
            get1[i-1]=*(strchr(s,'<')+i);
        }
        get1[len-1]='\0';
    }
    *strchr(s,'<')='.';
    len=strchr(s,'<')-strchr(s,'>');              //这次是第二个字串了
    if(len==1) get2[0]='\0';                      //考虑特殊情况  字符为空
    else
    {
        for(int i=1;i<len;i++)
        {
            get2[i-1]=*(strchr(s,'>')+i);
        }
        get2[len-1]='\0';
    }
    *strchr(s,'>')='#';                           //为了让strchr能找到下一个<>号 需要把已经找到的去掉
    len=strchr(s,'>')-strchr(s,'<');              //这次是第二个字串了
    if(len==1) get3[0]='\0';                      //考虑特殊情况  字符为空
    else
    {
        for(int i=1;i<len;i++)
        {
            get3[i-1]=*(strchr(s,'<')+i);
        }
        get3[len-1]='\0';
    }
    *strchr(s,'<')='#';
    len=strchr(s,'\0')- strchr(s,'>');             //这次是第二个字串了
    if(len==1) get4[0]='\0';                      //考虑特殊情况  字符为空
    else
    {
        for(int i=1;i<len;i++)
        {
            get4[i-1]=*(strchr(s,'>')+i);
        }
        get4[len-1]='\0';
    }
    return ;
}

char *auto_copy(char *s)
{
    char *ini=s;
    char src[MAX]="";
    strcat(src,get1);
    strcat(src,get2);
    strcat(src,get3);
    strcat(src,get4);
    strcpy(strchr(s,'.'),src);
    return ini;
}

char *auto_copy2(char *s)
{
    char *ini=s;
    char src[MAX]="";
    strcat(src,get3);
    strcat(src,get2);
    strcat(src,get1);
    strcat(src,get4);
    strcpy(strchr(s,'.'),src);
    return ini;
}
