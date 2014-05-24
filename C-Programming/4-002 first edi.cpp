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
	String(const char &p)
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
	cout << s.c_str() << endl;
	s = "Good Luck";
	cout << s.c_str() << endl;
	return 0;
}
