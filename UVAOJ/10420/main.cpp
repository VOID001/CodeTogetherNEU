#define LOCAL

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
typedef struct
{
    char first[80];
    int second=0;
}P;
//typedef pair <char[80],int> P;
char country[80][2010];
P love[2010];
vector<P> vec;
bool operator <(const P &x,const P &y)
{
    return strcmp(y.first,x.first)>0?true:false;        //注意自定义运算符时 要注意返回值只能为true或false
}



int main(void)
{
    #ifdef LOCAL
        freopen("10420.in","r",stdin);
    #endif // LOCAL
    memset(love,0,sizeof(love));
    char input[80];
    char tmp[80];
    int counts;
    scanf("%d",&counts);
    getchar();
    int psize=0;
    int ok;
    for(int i=0;i<counts;i++)
    {
        ok=0;
        gets(input);
        sscanf(input,"%s",tmp);
        for(int j=0;j<psize;j++)
        {
            if(!strcmp(tmp,love[j].first)) {love[j].second++;ok=1;}
        }
        if(!ok) {strcpy(love[psize].first,tmp);love[psize].second=1;psize++;}
    }
    for(int i=0;i<psize;i++) vec.push_back(love[i]);
    //vector<P>::iterator it0=vec.begin();
    //while(it0++!=vec.end());
    //vector<P>::iterator it0=vec.begin();
    //printf("DEBUG :");
    //cout << it0->first << endl;
    sort(vec.begin(),vec.end());
    for(vector<P>::iterator it=vec.begin();it!=vec.end();it++)
        printf("%s %d\n",it->first,it->second);
}

/**第一次用STL解决UVAOJ问题 看看运气咯**/
/**刚开始一直RE WA 注意运算符
