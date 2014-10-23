#include<iostream>

using namespace std; 

class String{
private:
	char *str;
public:
	String() :str(NULL){}
	~String();
	const char* c_str() { return str; }
	char *operator =(const char *s);
	String & operator = (const String & s)
	{
		if (str == s.str) return *this;			//语句A
		if (str) delete[] str;
		str = new char[strlen(str) + 1];
		strcpy(str, s.str);
		return *this;
	}
};

class MyString {
private:
	String str;
private:
	String & operator =(const String & s);
};

char *String::operator =(const char *s)						//这是深拷贝 而默认的构造函数是浅拷贝  
{
	if (str) delete[] str;
	if (s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
		str = NULL;
	return str;
}

String::~String()
{
	if (str) delete[] str;
}

int main(void)
{
	String s;
	s = "Hello C++";
	String s1;
	s1 = "PPPP";
	s = s1;					//这个代码在没有 String & operator = 的时候会出错  原因是： 由于用户未自定义String类的 = 运算符 系统会用自己生成的 进行浅拷贝 然后 s 和 s1同时指向了一块内存 于是 ，在return 时就会由于释放两次同一块内存出问题 所以 会报RE 而不是 CE 因为系统有默认的 对String =  的声明 解决这个问题的方式就是自己写一个	String = 号的重载 
	s = s;					//如果不在  String & operator =  里加入 语句A 第一个cout 会出异常值
	cout << s.c_str() << endl;
	s = "Good Luck";
	cout << s.c_str() << endl;
	return 0;
}
