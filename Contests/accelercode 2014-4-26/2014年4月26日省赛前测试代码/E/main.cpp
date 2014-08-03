#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#define MAX 25
#define MAXN 100001
using namespace std;

typedef struct stu
{
    char name[MAX];
    int math;
    int eng;
} stu;

stu st[MAXN];

bool cmp(const stu a,const stu b)
{
    if(b.eng!=a.eng) return a.eng>b.eng;
    else return a.math>b.math;
}

int main(void)
{
    int i,j;
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        memset(st,0,sizeof(st));

        for( int  oo=0;oo<i;oo++)
        {
            scanf("%s%d%d",st[oo].name,&st[oo].math,&st[oo].eng);

        }
        //sort(v.begin(),v.end(),cmp);
        sort(st,st+i,cmp);
        for(int oo=0;oo<j;oo++)
        {
            int sel;
            scanf("%d",&sel);
            printf("%s\n",st[sel-1].name);
        }
    }
    return 0;

}
