#include<stdio.h>
#include<math.h>
int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=6 || n%4!=3 || n%2==0) printf("YES\n");
        else
        {
            int ok=1;
            for(int oo=2;oo*oo<=n;oo++)
            {
                if(!(n%oo)) {ok=0;break;}
            }
            if(ok)
            {
                if(log(n+1)==0) printf("NO\n");
            }
            else printf("YES\n");
        }
    }
}
