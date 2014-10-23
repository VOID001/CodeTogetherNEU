//#define LOCAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LEN 90
#define MAXLEN 260

void str_replace();

char rep[15][LEN];
char fnd[15][LEN];
char edit[MAXLEN];
int rules;

int main(void)
{
    #ifdef LOCAL
        freopen("10115.in","r",stdin);
    #endif // LOCAL
    while(scanf("%d",&rules))
    {
        getchar();
        if(!rules) break;
        for(int i=1;i<=rules;i++)
        {
            gets(fnd[i]);
            gets(rep[i]);
        }
        gets(edit);
        str_replace();              //替换掉~~~~
    }

    return 0;
}

void str_replace()
{
    char mid[MAXLEN];
    //strcpy(mid,edit);
    int counter=1;
    while(counter<=rules)                    //所有规则都用完就输出文本了
    {
       if(strstr(edit,fnd[counter])!=NULL)
       {
            memset(mid,'\0',sizeof(mid));
            char *finds=strstr(edit,fnd[counter]);
            *finds='\0';
            strcat(mid,edit);
            strcat(mid,rep[counter]);
            *finds=fnd[counter][0];
            strcat(mid,finds+strlen(fnd[counter]));
            strcpy(edit,mid);
       }
       else counter++;
    }
    printf("%s\n",edit);
    return;
}
/**Accepted With ONLY ONE Attempt**/
