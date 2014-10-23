#include<stdio.h>
#include<string.h>

#define MAX 30
#define MAXN 100000

char mirror[25]= "AEHIJLMOSTUVWXYZ12358";
char _mirror[25]="A3HILJMO2TUVWXY51SEZ8";       //建立镜像字符表
//=======Function Prototype======
int judge_mirror(char *s);
int judge_palindrome(char *s);
//===============================
int main(void)
{
    //freopen("input.txt","r",stdin);
    //freopen("outputOK.txt","w",stdout);
    char s[MAX];
    int j_mirror,j_palindrome;
    while(scanf("%s",s)!=EOF)
    {
        j_mirror=judge_mirror(s);//Judge if mirror
        j_palindrome=judge_palindrome(s);//Judge if Palindrome
        printf("%s",s);
        switch(j_mirror+j_palindrome)//Output Result
        {
        case 0:
            printf(" -- is not a palindrome.\n\n");
            break;
        case 1:
            printf(" -- is a regular palindrome.\n\n");
            break;
        case 2:
            printf(" -- is a mirrored string.\n\n");
            break;
        case 3:
            printf(" -- is a mirrored palindrome.\n\n");
            break;
        }
    }
    return 0;
}
int judge_mirror(char *s)
{
    char *ini=s;
    int len=strlen(mirror);
    while(*(++s)!='\0')
    {
        if(strchr(mirror,*s)==NULL) return 0;               //如果有的字符根本不是镜像字符中的任何一个 则该串不是镜像串
    }

                                                            //若所有字符都是镜像字符中的字符 那么开始比较下一步
    s--;
    if(strlen(s)==1 && strchr(mirror,*s)==NULL) return 0;   //处理特殊情况 只有一个字符的情况                                               //s最后指向\0需要让s回退一个单位

    while(ini<=s)                                           //两个指针一起扫整个字符串 一个从后扫 一个从头扫
    {
        for(int oo=0;oo<len;oo++)
        {
             if((*ini==mirror[oo] && *s==_mirror[oo]) || *ini!=mirror[oo]) continue;
             return 0;
        }
        ini++;
        s--;
    }
    return 2;                                   //Return 2 Indicates it's a mirror string
}

int judge_palindrome(char *s)
{
    char *ini=s;
    while(*(s++));                              //让指针移动到字符串末尾后一个字符
    s-=2;                                       //移动到\0前
    while(ini<=s)
    {
        if(*ini!=*s) return 0;
        ini++;
        s--;
    }
    return 1;                                   //Return 1 Indicates it's a palindrome
}

/**数组开的不够大 以后记着点 。。可以直接输出就别开数组 格式问题还是很蒙**/
