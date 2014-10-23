#include<stdio.h>
#include<string.h>

#define MAX 100

//Function Prototype
char *check_keywords(char *s);
char *check_symbols(char *s);
//END OF PROTOTYPE


char list_k[20][10]={"main","char","int","float","struct","for" ,"while", "if", "break", "continue"};
char list_p[25][10]={ "+" , "-", "*", "/", "{", "}", "=",",", "[", "]", ";", "\'", "\"", "(", ")", ">", "<" ,"++","--"};
char list_c[1000][5];
char input_[100000];
char input[500][MAX];

int main(void)
{
    freopen("input.txt","r",stdin);
    int seq_c=0;
    int i=0;
    while(gets(input[i++])!=NULL)
    {
        strcat(input_,input[i-1]);
    }
    //printf("%s",input_);
    int len=strlen(input_);
    for(int j=0;j<len;j++)
    {
        //先判断这是一个字母 才可能出现keywords
        //check_keywords(input_+i);//check if keywords
        //关键词提取
        if(input_[j]>='a' && input_[j]<='z')
        {
            char *stmp=check_keywords(input_+j);
            for(int oo=0;oo<10;oo++)
                if(!strcmp(stmp,list_k[oo])) printf("(%s,k,%d)\n",stmp,oo);
            continue;
        }
        if(!(input_[j]>='a' && input_[j]<='z'))
        {

        }

    }
}

char *check_keywords(char *s)
{
    char copy[100000];
    memset(copy,0,sizeof(copy));
    strcat(copy,s);
    int i=0;
    while(copy[i]>='a'&&copy[i]<='z') {i++;}
    copy[i]='\0';
    return copy;
}

char *check_symbols(char *s)
{
    char copy[10000];
    memset(copy,0,sizeof(copy));
    strcat(copy,s);
    int i=0;
    while(!(copy[i]>='a'&& copy[i]<='z') && !(copy[i]>='0' && copy[i]<='9')) i++;
    copy[i]='\0';
    printf("copyISIS%s\n",copy);
    return copy;
}
