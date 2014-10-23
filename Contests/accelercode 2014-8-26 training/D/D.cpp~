#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const char* mahjong[]={
"1s","2s","3s","4s","5s","6s","7s","8s","9s",
"1p","2p","3p","4p","5p","6p","7p","8p","9p",
"1m","2m","3m","4m","5m","6m","7m","8m","9m",
"1z","2z","3z","4z","5z","6z","7z"
};
int convert(char *s)
{
    for(int i=0;i<34;i++)
    {
        if(strcmp(mahjong[i],s)==0) return i;
    }
    return -1;
}
int c[34];
bool search(int dep)
{
    int i;
    for(i=0;i<34;i++)if(c[i]>=3)
    {
        if(dep==3) return true;
        c[i]-=3;
        if(search(dep+1)) return true;
        c[i]+=3;
    }
    for(i=0;i<=24;i++)if(i%9<=6&&c[i]>=1&&c[i+1]>=1&&c[i+2]>=1)
    {
        if(dep==3) return true;
        c[i]--;c[i+1]--;c[i+2]--;
        if(search(dep+1)) return true;
        c[i]++; c[i+1]++;c[i+2]++;
    }
    return false;
}
bool check()
{
    int i;
    for(i=0;i<34;i++)
     if(c[i]>=2)
     {
         c[i]-=2;
         if(search(0))return true;
         c[i]+=2;
     }
     return false;
}
struct Node
{
    int x;
    char t;
};
Node node[20];
bool cmp(const Node& a,const Node& b)
{
    if(a.t==b.t) return a.x<b.x;
    else return a.t<b.t;
}
vector<string> vs;
int main()
{
    int i,j;
    bool ok;
    char tol[100];
    char s[100];
    int mj[15];
    while(scanf("%s",tol)!=EOF)
    {
        for(int i=0;i<13;i++)
        {
            node[i].x=tol[2*i]-'0';
            node[i].t=tol[2*i+1];
        }
        sort(node,node+13,cmp);
        for(int i=0;i<13;i++)
        {
            tol[2*i]=node[i].x+'0';
            tol[2*i+1]=node[i].t;
        }
        //printf("%s\n",tol);
        s[0]=tol[0];s[1]=tol[1];s[2]='\0';
        //printf("%s",s);
        mj[0]=convert(s);
        for(i=1;i<13;i++)
        {
            s[0]=tol[i*2];s[1]=tol[i*2+1];s[2]='\0';
            //printf("%s-",s);
            mj[i]=convert(s);
        }
        ok=false;
        int con=0;
        vs.clear();
        for(i=0;i<34;i++)
        {
            memset(c,0,sizeof(c));
            for(j=0;j<13;j++) c[mj[j]]++;
            if(c[i]>=4) continue;
            c[i]++;
            if(check())
            {
                ok=true;
                string ss=mahjong[i];
                vs.push_back(ss);
                con++;
            }
            c[i]--;
        }
        cout<<con<<" ";
        for(vector<string>::iterator ii=vs.begin();ii!=vs.end();ii++)
        {
            cout<<*ii;
        }
        printf("\n");
    }
    return 0;
}
