#include<stdio.h>


int abs(int a)
{
    return a>0?a:-a;
}

int main(void)

{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int P,PA,PB;
        scanf("%d%d%d",&P,&PA,&PB);
        printf("%s\n",abs(P-PA)<abs(P-PB)?"A":"B");
    }
    return 0;
}
