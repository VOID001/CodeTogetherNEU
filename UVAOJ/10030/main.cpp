#include<stdio.h>
#include<stdlib.h>
#define MAX 30
//long tests[100000][MAX]={0};
int main(void)
{
    //freopen("input.txt","r",stdin);
    int cases[10000]={0};
    int N,n;//Numbers of test cases N,Numbers of farmers n.
    int S,IFI,nA;
    long total=0;
    //int all =0;
    //while(scanf("%d",&N)!=EOF)
    //{
        //all++;
        scanf("%d",&N);
        for(int oo=1;oo<=N;oo++)
        {
            total=0;
            scanf("%d",&n);
            //cases[all]=oo;
            //tests[all][cases[all]]=0;
            for(int i=1;i<=n;i++)
            {
                scanf("%d%d%d",&S,&nA,&IFI);
                //if(tests[oo]<S*IFI) tests[oo]=S*IFI;
                //printf("@@@@%lld@@@@@",tests[all][oo]);
                //system("pause");
                total+=S*IFI;
            }
            printf("%ld\n",total);
        }
    //for(int oo=1;oo<=all;oo++)
    //{
    //    for(int k=1;k<=cases[oo];k++)
    //    {
    //        printf("%ld",tests[oo][k]);
    //        if(k<cases[oo]) printf("\n");
    //    }
    //    if(oo<all) printf("\n");
    //}
    return 0;
}

/** 想得太复杂了 ，注意简化思路**/
