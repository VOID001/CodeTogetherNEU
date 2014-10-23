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
            ptst=0;
            subsum=0;
            pted=N-1;
            while(ptst!=N)
            {
                if(!vis[ptst])
                {
                    if(ele[ptst]<sum-subsum)
                    {
                        subsum+=ele[ptst];
                        vis[ptst]=1;
                        ptst++;
                    }
                    else if(ele[ptst]==sum-subsum) { subsum+=ele[ptst];vis[ptst]=1;ptst++;break;}
                    else ptst++;
                }
                else ptst++;
            }
            printf("%d=%d\n",subsum,sum);
            subsum=0;
            /**if(subsum!=sum)
            {
                while(pted!=-1)
                {
                    if(!vis[pted])
                    {
                        if(ele[pted]<sum-subsum)
                        {
                            subsum+=ele[pted];
                            vis[pted]=1;
                            pted--;
                        }
                        else if(ele[pted]==sum-subsum) { subsum+=ele[pted];vis[pted]=1;pted--;break;}
                        else pted--;
                    }
                    else pted--;
                }
            }**/
        }
        printf("%s\n",ii==6?"yes":"no");

    }
    return 0;
}

