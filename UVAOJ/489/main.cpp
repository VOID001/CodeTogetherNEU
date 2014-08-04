#include<stdio.h>

#define MAX 100000
int main(void)
{
    //freopen("input.txt","r",stdin);
    int round;/**回合数**/
    char word[MAX];/**目标单词**/
    char ans[MAX];/**用户猜测**/

    while(scanf("%d",&round))
    {

        int win;/**获胜标记 1 win -1 lose 0 no**/
        int alphabet[27]={0};/**单词中含有的字母**/
        int alphaguess[27]={0};/*****玩家猜测的字母****/
        if(round==-1) break;
        scanf("%s",word);
        scanf("%s",ans);
        for(int oo=0;word[oo]!='\0';oo++)
        {
            alphabet[word[oo]-'a']=1;
        }
        int try_game=7;/**七次错误机会**/
        win=0;
        for(int oo=0;ans[oo]!='\0';oo++)
        {
            if(try_game==0) break;
            if(alphabet[ans[oo]-'a']==1 && alphaguess[ans[oo]-'a']==0) alphaguess[ans[oo]-'a']=1;
            if(alphabet[ans[oo]-'a']==0 && alphaguess[ans[oo]-'a']==0) {alphaguess[ans[oo]-'a']=1; try_game--;}
        }
        int guess=1;/**判断猜没猜到 假设猜到了 **/
        //for(int oo=0;oo<27;oo++)

        for(int oo=0;oo<27;oo++)
        {
            if(alphabet[oo]==1 && alphabet[oo]!=alphaguess[oo]) guess=0;
        }
        /**判断获胜与否**/
        if(guess==1) win=1;
        if(guess==0 && try_game>0) win=0;
        if(guess==0 && try_game==0) win=-1;

        printf("Round %d\n",round);
        switch(win)
        {
        case -1:
            printf("You lose.\n");
            break;
        case 0:
            printf("You chickened out.\n");
            break;
        case 1:
            printf("You win.\n");
            break;
        }
    }
}
/**我的想法 ：建立两个对应的数组 a[27] 每一个下标代表一个英文字母 当a[3]=0时意味着 第四个字母已经出现过 **/
