#include<stdio.h>
#include<string.h>
#include<stdlib.h>              //Qsort in it;
char *remove_front_space(char *s);
int cmp_string(const void* _stra,const void* _strb);

char dict[500000][300];
int main(void)
{
    //freopen("10815.in","r",stdin);
    //freopen("10815.out","w",stdout);
    char s[1000]="";
    char *ps=s;
    int oo=0;
    int repeat=0;
    while(scanf("%s",ps)!=EOF)
    {
        int len=strlen(ps);
        for(int i=0;i<len;i++)
        {
            if(*(ps+i)>='A' && *(ps+i)<='Z') *(ps+i)+=32;
            if(!(*(ps+i)>='a' && *(ps+i)<='z')) *(ps+i)='\0';
        }
        ps=remove_front_space(s);
        for(int j=0;j<oo;j++)
            if(!strcmp(ps,dict[j])) repeat=1;
        if(!repeat)
        {
            strcpy(dict[oo],ps);
            oo++;
        }
        repeat=0;
    }
    qsort(dict,oo,sizeof(dict[0]),cmp_string);
        for(int i=0;i<oo;i++)
            printf("%s\n",dict[i]);
}

char *remove_front_space(char *s)
{
    while(*(s++)=='\0');
    return s-1;
}

int cmp_string(const void* _stra,const void* _strb)
{
    char* a= (char*) _stra;
    char* b= (char*) _strb;
    return strcmp(a,b);
}
