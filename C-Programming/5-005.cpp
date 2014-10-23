#include<iostream>

using namespace std;

class Base{
private:
	int a; 
public:
	int func();
	Base(int n):a(n){ cout << "Base constructed" <<a<< endl; }
	~Base(){ cout << "Base destructed" <<a<< endl; }
};

class Derived :public Base{
public:
	Derived(int n):Base(n){ cout << "Derived constructed" << endl; }
	~Derived(){ cout << "Derived destructed" << endl; }
};

class MoreDerived:public Derived{
public:
	MoreDerived():Derived(4){ cout << "MoreDerived constructed" << endl; }
	~MoreDerived(){ cout << "MoreDerived destructed" << endl; }
};

int main(void)
{
	MoreDerived more;
	Derived deri(4);
	Base bs(4);
	bs = more;					//派生类对象可以赋值给基类对象   反之不可以
	Base& br = more;

	return 0;
}
