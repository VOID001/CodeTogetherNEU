/*************************************************************************
    > File Name: polymorphism.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月10日 星期四 07时41分45秒
 ************************************************************************/
#include<iostream>
using namespace std;

class BaseClass{
	public:
		virtual void fn1(){cout<<"BaseClass fn1 called"<<endl;}
		void fn2(){cout<<"BaseClass fn2 called"<<endl;}			
};

class DerivedClass:public BaseClass{
	public:
		virtual void fn1(){cout<<"DerivedClass fn1 called"<<endl;}
		void fn2(){cout<<"DerivedClass fn2 called"<<endl;}
};

int main(void)
{
	BaseClass bs;DerivedClass ds;
	BaseClass *p;
	p=&bs;
	p->fn1();
	p->fn2();
	p=&ds;
	p->fn1();
	p->fn2();
	return 0;
}
