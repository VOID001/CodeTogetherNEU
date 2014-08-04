#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int v,t;
    int x;
    while(scanf("%d%d",&v,&t)!=EOF)
        {
            x=v*t*2;
            printf("%d\n",x);
        }
    return 0;

}
