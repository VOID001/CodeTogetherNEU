#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(const int a, const int b)
{
    return a>b;
}

int main(void)
{
    int cases;
    int N;
    int ele[35];
    int vis[35];
    while(scanf("%d",&cases)!=EOF)
    {
        scanf("%d",&N);
        memset(ele,0,sizeof(ele));
        memset(vis,0,sizeof(vis));
        int sum=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&ele[i]);
            sum+=ele[i];
        }
        if(sum%6) {printf("no\n"); break;}
        sum/=6;
        sort(ele,ele+N,cmp);
        int ptst,pted;
        int subsum=0;
        memset(vis,0,sizeof(vis));
        int ii;
        for(ii=0;ii<6;ii++)
        {
            subsum=0;
            while(ptst<pted)
            {
                subsum+=ele[ptst];
                if(subsum==sum) break;
                else if(subsum>sum)
                {
                    ptst--;
                    if(ptst==-1)break;
                    while(ptst<pted)
                    {
                        subsum+=ele[pted];
                        pted--;
                        if(subsum==sum) break;
                        else if(subsum>sum) {ptst--; if(ptst==-1)break;}
                    }
                    if(ptst==-1)break;
                }
            }
            //printf("%d=%d\n",subsum,sum);
            if(subsum!=sum) break;

        }
        printf("%s\n",ii==6?"yes":"no");

    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(const int a, const int b)
{
    return a>b;
}

int main(void)
{
    int cases;
    int N;
    int ele[35];
    int vis[35];
    while(scanf("%d",&cases)!=EOF)
    {
        scanf("%d",&N);
        memset(ele,0,sizeof(ele));
        memset(vis,0,sizeof(vis));
        int sum=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&ele[i]);
            sum+=ele[i];
        }
        if(sum%6) {printf("no\n"); break;}
        sum/=6;
        sort(ele,ele+N,cmp);
        int ptst,pted;
        int subsum=0;
        memset(vis,0,sizeof(vis));
        int ii;
        for(ii=0;ii<6;ii++)
        {
            subsum=0;
            while(ptst<pted)
            {
                subsum+=ele[ptst];
                if(subsum==sum) break;
                else if(subsum>sum)
                {
                    ptst--;
                    if(ptst==-1)break;
                    while(ptst<pted)
                    {
                        subsum+=ele[pted];
                        pted--;
                        if(subsum==sum) break;
                        else if(subsum>sum) {ptst--; if(ptst==-1)break;}
                    }
                    if(ptst==-1)break;
                }
            }
            //printf("%d=%d\n",subsum,sum);
            if(subsum!=sum) break;

        }
        printf("%s\n",ii==6?"yes":"no");

    }
    return 0;
}
