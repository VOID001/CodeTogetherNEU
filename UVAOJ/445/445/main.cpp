#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 150

char s[MAX];

//Function Prototype
void build_maze();
//******************

int main(void)
{
    //Read—in INPUT
    //freopen("input.txt","r",stdin);
    while(gets(s)!=NULL)
    {
        build_maze();
        printf("\n") ;                  //Build the Maze
    }
    return 0;
}

void build_maze()
{
    int times=0;char ch;                  //重复次数 ，重复字符
    int len=0;                          //每两个！之间的距离 len 初始化为0
    //char *pt=s                        //用指针对字符串移位
    len=strlen(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9') times+=s[i]-'0';
        else if(s[i]=='!') printf("\n");
        else
        {
            for(int j=1;j<=times;j++)

                {
                    if(s[i]=='b') printf(" ");
                    else printf("%c",s[i]);
                }
            times=0;
        }
    }
}

/**在回车空格都被看做字符时，要用gets而不是scanf**/
