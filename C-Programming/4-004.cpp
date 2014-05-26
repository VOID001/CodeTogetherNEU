//可变长的整型数组
#include<iostream>
#include<cstdlib>

using namespace std;

////这是我自己设计的CArray 类
//class CArray{
//private:
//	int size;    		//记录数组长度
//	int *ptr;
//public:
//	void push_back(const int a);
//	int length();
//	CArray(int s = 0);
//	~CArray();
//	CArray(CArray a);			//这句代码有问题 复制构造函数必须是 引用类型 或者常引用或者引用
//	int & operator [](const int m);
//	CArray & operator = (const CArray a);
//};
////END OF MyCArray



//这是教程的CArray 类
class CArray{
private:
	int size;			//记录数组长度
	int *ptr;
public:
	void push_back(const int v);
	int length()
	{return size; }
	CArray(int s = 0);
	~CArray();
	CArray(const CArray &a);
	CArray & operator = (const CArray &  a);
	int & CArray::operator [](const int a)
	{
		return ptr[a];
	}
};
//END OF MyCArray

CArray::CArray(int s = 0) :size(s)
{
	if (!s) ptr = NULL;
	else ptr = new int[s];
}

CArray::CArray(const CArray & a)			//这就是深拷贝
{
//	if (a.ptr == ptr)				//注意 复制构造函数和 重载赋值号不一样
//		return ptr
	if (a.ptr!=NULL)
	{
		size = a.size;
		ptr = new int[size];
		memcpy(ptr, a.ptr,sizeof(int)*a.size);
	}
	else
	{
		size = 0;
		ptr = NULL;
	}
}

CArray::~CArray()
{
	if (ptr) delete[] ptr;
}

//CArray CArray::operator =     这句是错的混乱的代码 
CArray & CArray::operator =(const CArray & a)
{
	if (a.ptr == ptr) return *this;
	else
	{
		if (a.ptr == NULL)
		{
			if (ptr) delete[] ptr;
			size = 0;
			ptr = NULL;
			return *this;
		}
		else
		{
			if (size < a.size)
			{
				delete[] ptr;
				ptr = new int[a.size];
			}
			memcpy(ptr, a.ptr,sizeof(int)*a.size);
			size = a.size;
			return *this;
		}
	}
}

void CArray::push_back(const int v)
{
	if (ptr)
	{
		int *tmpptr = new int[size + 1];
		memcpy(tmpptr, ptr, sizeof(int)*size);
		delete[] ptr;
		ptr = tmpptr;
	}
	else
	{
		ptr = new int[1];
	}
	ptr[size++] = v;
}
