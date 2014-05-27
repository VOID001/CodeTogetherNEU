//运算符为什么要重载为友元函数？ 看下面的代码 
#include<iostream>

using namespace std;

class Complex{
private:
	double real, imagine;
public:
	Complex(double r=0, double i=0) :real(r), imagine(i){}
	Complex operator + (const Complex a);
	Complex operator + (const double a);
	friend Complex operator + (const double r, const Complex c);
	friend ostream & operator << (ostream & o, const Complex & c);

};
Complex Complex::operator + (const Complex a)
{
	return Complex(real + a.real, imagine + a.imagine);
}

Complex Complex::operator + (const double a)
{
	return Complex(real + a, imagine );
}

Complex operator + (const double r, const Complex c)
{
	return (c.real + r, c.imagine);
}

int main(void)
{
	Complex a(3, 5);
	Complex b(2, 1);
	Complex c;
	c = a + 5;					//如果不按照运算符重载为友元函数 这句代码没问题 可是下一句c = 5 + a就有问题了 
	c = 5 + a;
	cout << c<<c<<c<<c;
	return 0;
} 

ostream & operator << (ostream & o,const Complex & c)
{
	cout << c.real << "+" << c.imagine << "i" << endl;
	return o;
}


//}
