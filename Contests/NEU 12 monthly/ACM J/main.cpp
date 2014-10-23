#include<stdio.h>
#define MAX 10000
int num;
int n;
int x,y;
int Q[10];
int test[MAX];
void search(int current)
{
    int i,j;
    if(current==n) num++;
    else
        for (i=0;i<y;i++)
    {
        int ok=1;
        Q[current]=i;//尝试把第cur行的皇后放在第i列
        for(j=0;j<x;j++)
            if(Q[current]==Q[j]){ok=0;break;}
        if(ok) search(current+1);
    }
}

int main(void)
{
    int count=0;
    while(scanf("%d%d%d",&x,&y,&n)!=EOF);
        {
            num=0;
            count++;
            search(0);
            test[count]=num;
        }
    for(int i=1;i<=count;i++)
    {
        printf("%d",test[i]);
        if(i<count) printf("\n");
    }
}
