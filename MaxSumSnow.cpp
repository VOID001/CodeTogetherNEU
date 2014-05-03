#include <stdio.h>
#include <string.h>

int main()
{
    int n,a;                                                
    scanf("%d",&n);
    for(a=0;a<n;a++)
    {
        int m,i,j,b[100005],c[100005],max,min,k,h,l=0;                  //h 是起始位置 k是末尾位置 
        memset(b,0,sizeof(b));                                          //数组b是整个输入的记录数组
        memset(c,0,sizeof(c));                                          //数组c是记录从1---n个b中数的和的数组,c[i]-c[j](i>j)可以表示任意连续和
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            if(i==0)c[i]=b[i];
            else c[i]=c[i-1]+b[i];
        }
        max=c[0];                                                       //min存的是1--i 这组数的最小连续前缀和 max是 1--i的最大连续和 max 就等于 c[i]-min
        for(i=0;i<m;i++)
        {
            if(i==0)
            {
                min=0;
                k=1;                                                    //初始化h k 的值为b最前端
                h=1;
                continue;
            }
            if(min>c[i-1])                                              //如果前n个数的和比当前的最小和 （最大为0） 还要小
            {                                                           //min表示第i个数之前的最小和,c[i]-min表示以i为末尾的最大连续和
                min=c[i-1];                                             //就把min修改
                l=i+1;                                                  //为什么要用l记录？ 直接用h就可以吧 h=i+1
                                                                        //循环截止时l是最小和的位置，并不一定是最大序列的起始位置
            }
            if(max<(c[i]-min))
            {
                max=c[i]-min;
                if(!l)h=l;                                              //只有c[i]-min为最大序列示才更新h的值
                k=i+1;                                                  //每一次max更新 就说明序列 因此 i+1;
            }
        }
        printf("Case %d:\n%d %d %d\n",a+1,max,h,k);
        if(a!=n-1)printf("\n");
    }
    return 0;
}
//这个是当初的AC代码~没有用dp
//小宇讲这叫前缀数组


//这是我的理解 这么理解对么～ 还有 我还有两个疑问 你看看
