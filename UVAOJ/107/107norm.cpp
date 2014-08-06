#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,i;
    while(cin>>a>>b)
    {
        int n=1,k=1,opt_1=1,opt_2=a+b;
        if(a==0&&b==0)
            return 0;
        if(a==b&&b==1)
        {
            cout<<"0 1"<<endl;
            continue;
        }

        for(k=1;a!=int(pow(1.+pow(b,1./k),k)+0.1);k++);


        n=int(pow(b,1./k)+0.1);
        for(i=1;i<k;i++)
        {
            opt_1+=int(pow(n*1.,i));
            opt_2+=int(pow(n*1.,i)/pow(n+1.,i)*a+0.1);
        }
        cout<<opt_1<<" "<<opt_2<<endl;
    }
    return 0;
}
