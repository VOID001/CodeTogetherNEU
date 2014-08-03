#include<stdio.h>
#include<string.h>

#define MAX 10001

int getcnt(bool a[],int n);
int main(void)
{
    freopen("i.out","w",stdout);
    bool a[MAX];
    int n;
    for(n=10000;n<=10000;n++)
    {
        bool *pt=a+1;
        int num=2;
        memset(a,1,sizeof(a));
        int counter=0;
        int N=n;
        while(N>=num)
        {
            int delnum=0;
            for(;pt-a<=n;pt++)
            {
                if(*pt)
                {
                    counter++;
                }
                if(counter==num) {*pt=0;delnum++;counter=0;}
            }
            //for(pt=a+1;pt-a<=n;pt++) printf("%d",*pt);
            //printf("\n");
            //printf("%d\n",delnum);
            N=N-delnum;
            for(pt=a+num+1;pt-a<=n;pt++)
            {
                if(*pt) {num=pt-a;pt=a+1;counter=0;break;}
            }
        }
        printf("%d,",N);
    }
}

/*int getcnt(bool a[],int n)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]) cnt++;
    return cnt;
}*/
