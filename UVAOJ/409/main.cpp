/**GIVE MY PASSION TO ACMACMACMACMACM*
*ACMACMACMACMACMACMACMACMACMACMACMACM*
*ACMACMACMACMACMACMACMACMACMACMACMACM*
*************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//#define LOCAL
#define MAXLEN 100

char words[25][MAXLEN];
int m,n;

int find_words(char *s);

int main(void)
{
    #ifdef LOCAL
        freopen("409.in","r",stdin);
    #endif // LOCAL
    char excuses[25][MAXLEN];
    int n_excuses[25];
    int max;
    int count=1;
    memset(words,0,sizeof(words));
    memset(excuses,0,sizeof(excuses));
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        max=0;
        for(int i=0;i<m;i++) scanf("%s",words[i]);
        getchar();
        for(int i=0;i<n;i++)
        {
            gets(excuses[i]);
            n_excuses[i]=find_words(excuses[i]);
            if(max<n_excuses[i]) max=n_excuses[i];
        }
        printf("Excuse Set #%d\n",count);
        for(int i=0;i<n;i++)
            if(max==n_excuses[i])
            {
                printf("%s",excuses[i]);
                printf("\n");
            }
        printf("\n");
        count++;
    }

    return 0;
}

int find_words(char *s)
{
    int num=0;                          //关键词数量
    char copy[MAXLEN];
    memset(copy,0,sizeof(copy));
    strcpy(copy,s);                     //保证不修改原来的字符串用copy进行操作
    int len=strlen(copy);
    for(int oo=0;oo<len;oo++)
    {
        copy[oo]=tolower(copy[oo]);
        if(!isalpha(copy[oo])) copy[oo]='#';
    }
    //printf("%s\n",copy);
    char words_[100]="";
    int j=0;
    for(int oo=0;oo<len;oo++)
    {
        if(copy[oo]!='#') {words_[j]=copy[oo]; j++;}
        else {words_[j]='\0';j=0;}
        for(int count=0;count<m;count++)  if(!strcmp(words[count],words_)) num++;
    }
    return num;
}

/**Accepted with ONLY ONE Attempt**/
