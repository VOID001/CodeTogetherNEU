#include<iostream>
using namespace std;
 
const int MAX=100000;
const double esp=1e-9;
 
int main(void)
{
    int T;
    cin>>T;
    int N;
    double x1,y1,x2,y2;
    double x[MAX+1],y[MAX+1];
    for(int cnt=0;cnt<T;cnt++)
    {
        int coins=0;
        cin>>N>>x1>>y1>>x2>>y2;
        for(int i=0;i<N;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<N;i++)
        {
            cin>>y[i];
        }
        if(x1==x2)
        {
            for(int i=0;i<N;i++)
            {
                if(x[i]<x1 || y[i]>y1) continue;
                if(x1==x[i]) coins++;
            }
        }
        else
        {
            double k=(y1-y2)/(x1-x2);
            for(int i=0;i<N;i++)
            {
                if(x[i]<x1 || y[i]>y1) continue;
                double tmpx=x[i];
                double tmpy=y[i];
                if((x2-x1)*(tmpy-y1)-(y2-y1)*(tmpx-x1)<esp && (x2-x1)*(tmpy-y1)-(y2-y1)*(tmpx-x1)>-esp) coins++;
            }
        }
        cout<<coins<<endl;
    }
    return 0;
}
/**************************************************************
    Problem: 1452
    User: 20133870
    Language: C++
    Result: 正确
    Time:563 ms
    Memory:2760 kb
	注意这是射线不是直线
****************************************************************/
