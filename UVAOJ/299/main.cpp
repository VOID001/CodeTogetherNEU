/** 299 说了半天就是看看冒泡排序需要交换几次 - - **/
//#define LOCAL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 60

void bubble();

int len;
int s[MAX];
int cases;
int swap;
int main(void)
{

    #ifdef LOCAL
        freopen("299.in","r",stdin);
    #endif // LOCAL
    scanf("%d",&cases);
    for(int i=1;i<=cases;i++)
    {
        swap=0;
        memset(s,0,sizeof(s));
        scanf("%d",&len);
        for(int i=0;i<len;i++)
            scanf("%d",&s[i]);
        bubble();//Bubble Sort
        printf("Optimal train swapping takes %d swaps.\n",swap);
    }
}

void bubble()
{
    int tmp;
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
        {
            if(s[i]>s[j])
            {
                tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
                swap++;
            }
        }
    return ;
}
