#include<stdio.h>
#include<string.h>

#define MAX 50000
char pw[MAX][100];
char mw[MAX][500]={""};
int main(void)
{
    int i=0;
    while(scanf("%s",pw[i])!=EOF)
    {
        for(int oo=0;pw[i][oo]!='\0';oo++)
        {
            pw[i][oo]+='*'-'1';
        }
        printf("%s\n",pw[i]);
        i++;
    }
}
