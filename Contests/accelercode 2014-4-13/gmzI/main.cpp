#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int MAX=150;
const double  sma=1e-9;
int main(void)
{
    int cases;
    int cnt;
    double x[MAX];
    double y[MAX];
    scanf("%d",&cases);
    while(cases--)
    {
        cnt=0;
        int pt;
        scanf("%d",&pt);
        for(int i=0;i<pt;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        for(int i=0;i<pt;i++)
        {
            for(int j=i+1;j<pt;j++)
            {
                //if(i==j) continue;
                for(int k=j+1;k<pt;k++)
                {
                    //if(j==k || i==k) continue;
                    double len1=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);                //防止溢出
                    double len2=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
                    double len3=(x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]);
                    if(len1+len2-len3>sma && len1+len3-len2 >sma && len2+len3-len1>sma) cnt++;

                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
