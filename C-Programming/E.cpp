#include<iomanip>
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int MAX = 10001;
const string wp[3] = { "sword", "bomb", "arrow" };
const string mon[5] = { "iceman", "lion", "wolf", "ninja", "dragon" };
const int seqred[5] = { 0, 1, 2, 3, 4 };									// 红蓝两方的制造顺序
const int seqblue[5] = { 1, 4, 3, 0, 2 };
class CDragon;
class CNinja ;
class CIceman;
class CLion ;
class CWolf ;
class CBase{
private:
	string name;
	int lifeElement;
	int index;
	int nNinja, nDragon, nLion, nWolf, nIceman;
	int needNinja, needDragon, needLion, needWolf, needIceman;
	CDragon* dragonPtr[MAX];
	CNinja* ninjaPtr[MAX];
	CLion* lionPtr[MAX];
	CWolf* wolfPtr[MAX];
	CIceman* icemanPtr[MAX];
public:
	CBase(const string& nm, int ele, int nN, int nD, int nL, int nW, int nI) :name(nm), nNinja(0), nDragon(0), nLion(0), nWolf(0), nIceman(0), lifeElement(ele), needLion(nL), needWolf(nW), needDragon(nD), needNinja(nN), needIceman(nI),index(1)
	{
		memset(dragonPtr, NULL, sizeof(dragonPtr));
		memset(ninjaPtr, NULL, sizeof(ninjaPtr));
		memset(icemanPtr, NULL, sizeof(icemanPtr));
		memset(wolfPtr, NULL, sizeof(wolfPtr));
		memset(lionPtr, NULL, sizeof(lionPtr));
	}
	~CBase();
	int makeMonster(int time,int type);
	string getBaseName()const { return name; }
	int getHP(const string& monName) const
	{
		if (monName == "lion") return needLion;
		if (monName == "ninja") return needNinja;
		if (monName == "iceman") return needIceman;
		if (monName == "wolf") return needWolf;
		if (monName == "dragon") return needDragon;
	}
	int getNumber(const string& monName) const
	{
		if (monName == "lion") return nLion;
		if (monName == "ninja") return nNinja;
		if (monName == "iceman") return nIceman;
		if (monName == "wolf") return nWolf;
		if (monName == "dragon") return nDragon;
	}
};

class CMonster{
private:
	int id;
	int hp;
	int str;
public:
	virtual void showInfo() {}
	CMonster(const CBase& bas, int i, int h, string monName) :id(i), hp(h), str(hp)
	{ 
		cout <<" "<<bas.getBaseName()<<" "<< monName<<" "<< id << " " << "born with strength " << str<< ","; 			
		cout << bas.getNumber(monName) << " " << monName << " in " << bas.getBaseName() << " headquarter" << endl;
	}
	~CMonster(){}
};

class CDragon :public CMonster{
private:
	double moral;
	int weapon;
public:
	CDragon(const CBase& bas, int id, int hp, double mor) :CMonster(bas, id, hp, "dragon"), weapon(id % 3), moral(mor)
	{
		cout << "It has a " << wp[weapon] << ",and it's morale is ";
		printf("%.2lf\n", moral);
	}
	~CDragon(){}
};

class CNinja :public CMonster{
private:
	int weapon1, weapon2;
public:
	CNinja(const CBase&bas, int id, int hp) :CMonster(bas, id, hp, "ninja"), weapon1(id % 3), weapon2((id + 1) % 3)
	{
		cout << "It has a " << wp[weapon1] << " and a " << wp[weapon2] << endl;
	}
	~CNinja(){}
};

class CIceman :public CMonster{
private:
	int weapon;
public:
	CIceman(const CBase& bas, int id, int hp) :CMonster(bas, id, hp, "iceman"), weapon(id % 3)
	{
		cout << "It has a " << wp[weapon]<<endl;
	}
};

class CLion :public CMonster{
private:
	int loyalty;
public:
	CLion(const CBase& bas,int id, int hp,int loya) :CMonster(bas,id, hp,"lion"), loyalty(loya)
	{
		cout << "It's loyalty is " << loyalty << endl;
	}
	~CLion(){}
};

class CWolf :public CMonster{
public:
	CWolf(const CBase& bas, int id, int hp) : CMonster(bas, id, hp, "wolf"){}
	~CWolf(){}
};


CBase::~CBase()
{
	for (int i = 0; i < MAX; i++)
	{
		if (dragonPtr[i] != NULL) { delete dragonPtr[i]; dragonPtr[i] = NULL; }
		if (ninjaPtr[i] != NULL) { delete ninjaPtr[i]; ninjaPtr[i] = NULL; }
		if (icemanPtr[i] != NULL) { delete icemanPtr[i]; icemanPtr[i] = NULL; }
		if (wolfPtr[i] != NULL) { delete wolfPtr[i]; wolfPtr[i] = NULL; }
		if (lionPtr[i] != NULL) { delete lionPtr[i]; lionPtr[i] = NULL; }
	}
}

int CBase::makeMonster(int time,int type)
{
	if (lifeElement >= getHP(mon[type]))
	{
		cout <<setfill('0')<< setw(3) <<  time;
		lifeElement -= getHP(mon[type]);
		switch (type)
		{
		case 0:
			nIceman++;
			icemanPtr[nIceman-1] = new CIceman(*this, index++, needIceman);
			break;
		case 1:
			nLion++;
			lionPtr[nLion-1] = new CLion(*this, index++, needLion, lifeElement);
			break;
		case 2:
			nWolf++;
			wolfPtr[nWolf-1] = new CWolf(*this, index++, needWolf);
			break;
		case 3:
			nNinja++;
			ninjaPtr[nNinja-1] = new CNinja(*this, index++, needNinja);
			break;
		case 4:
			nDragon++;
			dragonPtr[nDragon-1] = new CDragon(*this, index++, needDragon, (double)lifeElement*1.0 / needDragon);
			break;
		}
		return 1;
	}
	else 
	return 0;
}

int main(void)
{
	int N;
	int dra, nin, ice, lio, wol;
	int life;
	bool red_in_making;
	bool blue_in_making;
	int time;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> life;
		cin >> dra >> nin >> ice >> lio >> wol;
		CBase redBase("red", life, nin, dra, lio, wol, ice); 
		CBase blueBase("blue", life, nin, dra, lio, wol, ice); 
		red_in_making = blue_in_making = 1;
		time = 0;
		int bluei = 0;
		int redi = 0;
		cout << "Case:" << i << endl;
		
		while (red_in_making || blue_in_making)						//只要有一个再做 就不退出循环
		{
			int cannot = 0;
			int tmpok;
			while (red_in_making)
			{
				tmpok = 0;
				if (cannot >= 5){ red_in_making = 0; cout << setw(3) << setfill('0') << time; cout << " red headquarter stops making warriors" << endl; break; }
				tmpok=redBase.makeMonster(time, seqred[redi % 5]);
				redi++;
				if (tmpok) break;
				else cannot++;
			}
			cannot = 0;
			while (blue_in_making)
			{
				tmpok = 0;
				if (cannot >= 5){ blue_in_making = 0; cout << setw(3) << setfill('0') << time; cout << " blue headquarter stops making warriors" << endl; break; }
				tmpok=blueBase.makeMonster(time, seqblue[bluei % 5]);
				bluei++;
				if (tmpok) break;
				else cannot++;
			}
			time++;
		}
	}
	return 0;
}
