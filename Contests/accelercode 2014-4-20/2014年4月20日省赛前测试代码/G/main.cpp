#include<stdio.h>
#include<string.h>
#define MAX 10088

int main(void)
{
    int c;
    char s[MAX];
    scanf("%d",&c);
    for(int i=1;i<=c;i++)
    {
        scanf("%s",s);
        printf("Case %d: %s\n",i,strlen(s)%2?"Odd":"Even");
    }
    return 0;
}
