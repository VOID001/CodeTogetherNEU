#include<iostream>
using namespace std;

class A{
public:
	virtual void print(){ cout << "Print A" << endl; }
};

class B:public A{
public:
	virtual void print(){ cout << "Print B" << endl; }
};

class D:public A{
public:
	virtual void print(){ cout << "Print D" << endl; }
};

class E:public B{
public:
	virtual void print(){ cout << "Print E" << endl; }
};

int main(void)
{
	A a; B b;
	E e; D d;
	A* pa = &a;
	B* pb = &b;
	D* pd = &d;
	E* pe = &e;
	pa->print();
	pa = pb;
	pa->print();
	pa = pd;
	pa->print();
	pa = pe;
	pa->print();
	return 0;
}
