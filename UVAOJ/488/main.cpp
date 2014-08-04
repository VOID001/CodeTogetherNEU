/**Triangle waves**/
#include<stdio.h>
#include<string.h>

#define MAX 1000

int main(void)
{
    int waves,height;/**重复次数 以及最高处高度**/
    int cases;
    scanf("%d",&cases);
    for(int i=1;i<=cases;i++)
    {
    scanf("%d\n%d",&height,&waves);
    {
       for(int toto=1;toto<=waves;toto++)
        {
            for(int cur=1;cur<=height;cur++)
            {
            for(int oo=1;oo<=cur;oo++)
                printf("%d",cur);
            printf("\n");
            }
            for(int cur=height-1;cur>=1;cur--)
            {
            for(int oo=1;oo<=cur;oo++)
                printf("%d",cur);
            printf("\n");
            }
            if(toto<waves) printf("\n");
        }
    }
    if(i<cases) printf("\n");
    }

}
/**tried 5 times Accepted 2013-12-30 12:10:26**/
