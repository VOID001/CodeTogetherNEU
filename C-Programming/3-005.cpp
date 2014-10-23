#include<iostream>

using namespace std;
// 构建成员对象 CTyre CEngine
class CTyre{
private:
	int radius;
	int price;
public:
	CTyre(int r,int p);
	~CTyre();
};

CTyre::CTyre(int r, int p) :radius(r), price(p){ cout << "CTyre Constructed" << endl; };		//用初始化列表的方式初始化 对象
CTyre::~CTyre(){ cout << "CTyre Destructed" << endl; };

class CEngine{
public:
	CEngine(){ cout << "CEngine Constructed" << endl; }
	~CEngine(){ cout << "CEngine Destructed" << endl; }	
};
//构建封闭类 CCar
class CCar{
private:
	int price;
	CTyre tyre;
	CEngine engine;
public:
	CCar(int p, int tr, int w);
	~CCar();
};

CCar::CCar(int p, int tr, int w) :price(p), tyre(tr, w){ cout << "CCar Constructed" << endl; }
CCar::~CCar(){ cout << "CCar Destructed" << endl; };

int main(void)
{
	CCar car(2,4,6)	;
	return 0;
}

//************************  Result ********************
//CTyre Constructed
//CEngine Constructed
//CCar Constructed
//CCar Destructed
//CEngine Destructed
//CTyre Destructed

