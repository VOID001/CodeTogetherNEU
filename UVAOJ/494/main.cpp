#include<stdio.h>
#include<string.h>

#define MAX 10000
#define J_ALPHA (ch[oo]<='Z' && ch[oo]>='A') || (ch[oo]<='Z' && ch[oo]>='A')
char ch[100];

int main(void)
{
    int pre=0;/**前一字符的标志 1字母 0 非字母**/
    int now=0;/**当前字符的标志 1字母 0 非字母**/
    while(gets(ch))
    {
        int word=0;
        pre=0;
        now=0;
        for(int oo=0;ch[oo]!='\0';oo++)
        {
            pre=now;//前一输入的now是当前的pre
            if((ch[oo]<='Z' && ch[oo]>='A') || (ch[oo]<='z' && ch[oo]>='a')) now=1; else now=0;
            if(pre==0 && now==1) word++;
        }
        printf("%d\n",word);
    }
}
/**Accepted 2013-12-27 11:49:51**/
