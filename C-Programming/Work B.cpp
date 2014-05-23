#include<iostream>
#include<cstring>

using namespace std;

class CBase{
private:
	int id;
	int num_dragon, num_iceman, num_wolf, num_ninja, num_lion;
	char name[10];
	int hp;
public:
	static int hp_dragon, hp_iceman, hp_wolf, hp_ninja, hp_lion;
	CBase(char Name[],int h);
	int GetHP(int type);
	void Ini();
	static void SetHP(int type, int i);
	int CreateWarrior(int a);
};

int CBase::hp_dragon = 0;
int CBase::hp_iceman = 0;
int CBase::hp_wolf = 0;
int CBase::hp_ninja = 0;
int CBase::hp_lion = 0;

CBase::CBase(char Name[],int h)
{
	strcpy(name, Name);
	id = 0;
	hp = h;
	hp_dragon = 0;
	hp_iceman = 0;
	hp_wolf = 0;
	hp_ninja = 0;
	hp_lion = 0;
	num_dragon = 0;
	num_iceman = 0;
	num_wolf = 0;
	num_ninja = 0;
	num_lion = 0;
}

void CBase::SetHP(int type, int i)
{
	switch (type)
	{
	case 1:
		hp_dragon = i;
		break;
	case 2:
		hp_ninja = i;
		break;
	case 3:
		hp_iceman = i;
		break;
	case 4:
		hp_lion = i;
		break;
	case 5:
		hp_wolf = i;
		break;
	}
}

int CBase::GetHP(int type)
{
	switch (type)
	{
	case 1:
		return hp_dragon;
	case 2:
		return hp_ninja;
	case 3:
		return hp_iceman;
	case 4:
		return hp_lion;
	case 5:
		return hp_wolf;
	}
}


void CBase::Ini()
{
	hp_dragon = 0;
	hp_iceman = 0;
	hp_wolf = 0;
	hp_ninja = 0;
	hp_lion = 0;
}

int CBase::CreateWarrior(int a)
{
	if (hp >= GetHP(a))													//竟然忘记加 "=" 好坑 
	{
		int curHP= GetHP(a);
		hp -= curHP;
		id++;
		cout << name << " ";
			switch (a)
			{
			case 1:
				num_dragon++;
				cout << "dragon " << id << " born with strength " << curHP << "," << num_dragon << " dragon in";
				break;
			case 2:
				num_ninja++;
				cout << "ninja " << id << " born with strength " << curHP << "," << num_ninja << " ninja in";
				break;
			case 3:
				num_iceman++;
				cout << "iceman " << id << " born with strength " << curHP << "," << num_iceman << " iceman in";
				break;
			case 4:
				num_lion++;
				cout << "lion " << id << " born with strength " << curHP << "," << num_lion << " lion in";
				break;
			case 5:
				num_wolf++;
				cout << "wolf " << id << " born with strength " << curHP << "," << num_wolf << " wolf in";
				break;
			}
			cout <<" "<< name << " headquarter" << endl;
			return 1;
	}
	return 0;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int HP;
		cin >> HP;
		int sred[5] = {3,4,5,2,1};
		int sblue[5]={4, 1, 2, 3, 5};
		CBase red("red",HP);
		CBase blue("blue",HP);
		int tmphp;
		for (int j = 1; j <= 5; j++)
		{
			cin >> tmphp;
			CBase::SetHP(j, tmphp);
		}
		bool redok=1, blueok = 1;
		int redi, bluei = 0;
		redi = bluei = 0;
		int time = 0;
		cout << "Case:" << i << endl;
		while (redok || blueok)
		{
			int cnt = 0;
			int tmpok = 1;
			if (redok)
			{
				cout.fill('0');
				cout.setf(ios::right);
				cout.width(3);
				cout << time << " ";
				cout.unsetf(ios::right);
			}
			while (cnt < 5 && redok)
			{
				tmpok = red.CreateWarrior(sred[redi % 5]);
				redi++;
				if (tmpok) break;
				else 
					cnt++;
			}
			if (!tmpok && cnt == 5)
			{
				cout << "red headquarter stops making warriors" << endl;
				redok = 0;
			}
			cnt = 0;
			tmpok = 1;
			if (blueok)
			{
				cout.fill('0');
				cout.setf(ios::right);
				cout.width(3);
				cout << time << " ";
				cout.unsetf(ios::right);
			}
			while (cnt < 5 && blueok)
			{
				tmpok = blue.CreateWarrior(sblue[bluei % 5]);
				bluei++;
				if (tmpok) break;
				else 
					cnt++;
			}
			if (!tmpok && cnt == 5)
			{
				cout << "blue headquarter stops making warriors" << endl;
				blueok = 0;
			}
			time++;
		}
	}
	return 0;
}
