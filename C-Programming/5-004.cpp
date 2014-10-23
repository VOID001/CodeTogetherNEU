#include<iostream>

class CBug{
private:
	int nLegs; int nColor;
public:
	int nType;
	CBug(int legs, int color) : nLegs(legs), nColor(color){}
	void printBug() {}
};

class CSkill{
public:
	CSkill(int n){}
};

class CFlyBug : public CBug{						//这是继承 把CBug 的所有属性 给 CFlyBug 
private:
	int nWings;
	CSkill sk1, sk2;
public:
//	CFlyBug(int a, int b, int c) :CBug(a, b), nWings(c){}					//基类的成员变量需要通过初始化列表初始化
	CFlyBug(int a, int b, int c, int ska, int skb);
};
CFlyBug::CFlyBug(int a, int b, int c, int ska, int skb) :
CBug(a, b), sk1(ska), sk2(skb), nWings(c){}

int main(void) { return 0; }
