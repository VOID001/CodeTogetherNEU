#include<stdio.h>
#include<string.h>

#define MAX 10000
char s[MAX];
char ele1,ele2;
double vele1,vele2;
char unit1,unit2;
int main(void)
{
    //freopen("input.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long cases=1;
    scanf("%lld",&cases);
    getchar();
    for(long long i=1;i<=cases;i++)
    {
        memset(s,0,sizeof(s));
        gets(s);
        int flag=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='=' && !flag)  {ele1=s[i-1];flag=1;}
            if(s[i]=='=' && flag) {ele2=s[i-1];}
        }
        sscanf(strchr(s,'=')+1,"%lf%c",&vele1,&unit1);
        *strchr(s,'=')='@';
        sscanf(strchr(s,'=')+1,"%lf%c",&vele2,&unit2);
        //printf("%.2lf%c\n%.2lf%c",vele1,unit1,vele2,unit2);
        switch(unit1)
        {
        case 'm':
            vele1=vele1*0.001;
            break;
        case 'k':
            vele1=vele1*1000;
            break;
        case 'M':
            vele1=vele1*1000000;
            break;
        }
        switch(unit2)
        {
        case 'm':
            vele2=vele2*0.001;
            break;
        case 'k':
            vele2=vele2*1000;
            break;
        case 'M':
            vele2=vele2*1000000;
            break;
        }
        printf("Problem #%lld\n",i);
        if((ele1=='U' && ele2=='I') ||(ele1=='I' &&ele2=='U'))
            printf("P=%.2lfW",vele1*vele2);
        else if((ele1=='P'&&ele2=='U')||(ele1=='U' && ele2=='P'))
            printf("I=%.2lfA",ele1=='P'?vele1/vele2:vele2/vele1);
        else if((ele1=='P'&&ele2=='I')||(ele1=='I' && ele2=='P'))
            printf("U=%.2lfV",ele1=='P'?vele1/vele2:vele2/vele1);
        printf("\n\n");

    }
}

/**思路简单水 = = 但是注意 输出格式！！！！**/
/**Acccepted 2014-1-25 9：44 With 4 Attempts**/
