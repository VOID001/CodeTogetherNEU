#include<stdio.h>
#include<string.h>
#include<math.h>

char s[10];
int calc[12]={0,7,6,5,4,3,11,2,1,0};
int main(void)
{
    //freopen("10878.in","r",stdin);
    memset(s,0,sizeof(s));
    while(gets(s)!=NULL)
    {
        char out=0;
        if (!strcmp(s,"___________")) continue;
        for(int i=1;i<=9;i++)
        {
            if(s[i]=='o') out+=(int)(pow(2,calc[i]));
        }
        putchar(out);
    }
    return 0;
}

/** Accepted at 2014-1-25 With ONLY ONE ATTEMPT!!**/
