#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
const int MAX =35;
int base(char *s,int b)
{
    int len =strlen(s);
    int sum=0;
    for(int i=0;i<len;i++)
    {
        if(isalpha(s[i])) sum=sum*b+(s[i]-'a'+10);
        else (sum=sum*b+(s[i]-'0'));
    }
    return sum;
}

int main(void)
{
    int cases;
    char s1[MAX],s2[MAX];
    int bas;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%s%s%d",s1,s2,&bas);
        int num1=base(s1,bas);
        int num2=base(s2,bas);
        printf("(%d,%d)\n",num1/num2,num1%num2);
    }
    return 0;
}
