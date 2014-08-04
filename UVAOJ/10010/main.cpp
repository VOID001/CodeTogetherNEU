#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main(void)
{
    freopen("input.txt","r",stdin);
    int cases;
    char wordmatrix[MAX][MAX]={""};/**字符矩阵**/
    char wordlist[MAX+5][MAX];
    scanf("%d",&cases);/**总共有多少条输入**/
    for(int useless=1;useless<=cases;useless++)/**总输入数**/
    {
        int this_word_find=0;
        int find=0;
        int m,n;
        scanf("%d%d",&m,&n);
        for(int M=1;M<=m;M++)/**读入字母矩阵**/
            scanf("%s",wordmatrix[M]);
        for(int M=1;M<=m;M++)
            for(int N=0;wordmatrix[M][N]!='\0';N++)
                if(wordmatrix[M][N]<='Z' && wordmatrix[M][N]>='A') wordmatrix[M][N]+=32;
        /**对字母矩阵进行统一小写转换处理**/
        int k;
        scanf("%d",&k);
        for(int counter=1;counter<=k;counter++)/**读入单词字典**/
            scanf("%s",wordlist[counter]);

        for(int r=1;r<=k;r++)
            for (int qqw=0;wordlist[r][qqw]!='\0';qqw++)
                if(wordlist[r][qqw]<='Z' && wordlist[r][qqw]>='A') wordlist[r][qqw]+=32;
        /**同样把字典的大小写统一**/
        /**下面是关键代码:判断模块**/
        for(int oo=1;oo<=k;oo++)/**一个单词一个判断模块**/
        {
            //printf("\n");
            this_word_find=0;/**这个单词的找到标志初始化为0 表示没找到 若为1 表示找到**/
            for(int M=1;M<=m;M++)
            {
                for(int N=0;wordmatrix[M][N]!='\0';N++)
                {
                    if(wordlist[oo][0]!=wordmatrix[M][N]) continue;//如果第一个字母就不匹配 那么 忽略这个位置 进行下一判断
                    int len=strlen(wordlist[oo]);//读取字符串的长度
                    /**开始查找**/
                    //find=1;//查找标志find初始化为1
                    /**按照八个方向依次查找 若有不符马上退出**/
                    //printf("\n");
                    for(int finding=0;finding<=len-1;finding++)
                        if(wordmatrix[M][N+finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    //printf("right %d",find);
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M][N-finding]!=wordlist[oo][finding]){find=0;break;} else if(finding==len-1) find=1;
                    //printf("left %d",find);
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M+finding][N+finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M-finding][N-finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M+finding][N]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M-finding][N]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M+finding][N-finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M-finding][N+finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    if(find==1)
                    {
                        printf("%d %d",M,N+1);
                        if(oo<k) printf("\n");
                        if(oo==k) printf("\n");
                        this_word_find=1;
                        break;
                    }
                    if(this_word_find==1) break;
                }
                if(this_word_find==1) break;/**上面几行代码表示 若找到此单词一次 就不继续找这个单词**/
            }
        }
        if(useless<cases) printf("\n");
    }
}

/**Accepted 2013-12-28 02:46:57**/
