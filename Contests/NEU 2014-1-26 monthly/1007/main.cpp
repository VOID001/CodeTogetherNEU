#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1500

int cmp_int (const void *_a,const void *_b);

int main(void)
{
    freopen("input.txt","r",stdin);
    int oil=200;
    int distant[MAX];
    int r_distant[MAX];
    int cases=0;
    int ok=1;
    while(1)
    {
        ok=1;
        scanf("%d",&cases);
        if(!cases) break;
        //Judge if makeit
        for(int i=1;i<=cases;i++)
            scanf("%d",&distant[i]);
        qsort(distant+1,cases,sizeof(int),cmp_int);
        r_distant[1]=distant[2];
        for(int i=2;i<cases;i++)
        {
            r_distant[i]=distant[i]-distant[i-1];
            //printf("%d\t",r_distant[i]);
        }
        r_distant[cases]=1422-distant[cases];
        qsort(r_distant+1,cases,sizeof(int),cmp_int);
        if(r_distant[cases]>200) ok=0;
        if(2*(1422-distant[cases])>200) ok=0;
        if(!ok) printf("IMPOSSIBLE\n");
        if(ok) printf("POSSIBLE\n");
    }
    return 0;
}

int cmp_int (const void *_a,const void *_b)
{
    int *a= (int*) _a;
    int *b= (int*) _b;
    return *a-*b;
}

/**别把问题想复杂**/
