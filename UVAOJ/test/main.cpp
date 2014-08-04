#include<stdio.h>
#include<string.h>

#define MAX 120


char s[MAX];
int main(void)
{
    gets(s);
    printf("%d",strlen(s));
}
