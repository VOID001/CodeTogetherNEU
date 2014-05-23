#include<iostream>

using namespace std;

//class CWarrior{
//private:
//	int id;
//	int hp;
//	int atk;
//	char name[10];
//	int type;
//public:
//	CWarrior(int h, int t,int i);
//	void SetHP(int i, int k);
//};


//CWarrior::CWarrior(int h, int t,int i)
//{
//    switch (t)
//    {
//    case 1:
//    	strcpy(name, "dragon");					//vim 替换一个单词 在Normal下 按cw
//    	break;
//    case 2:
//    	strcpy(name, "ninja");
//    	break;
//    case 3:
//    	strcpy(name, "iceman");
//    	break;
//    case 4:
//    	strcpy(name, "lion");
//    	break;
//    case 5:
//    	strcpy(name, "wolf");					//vim 复制多行 首先 选到要复制的首行 在Normal下 按ma 然后 选到复制的最后一行 按 y'a 然后 在要复制的地方 按P or p
//    	break;
//    }
//    hp = h;
//    type = t;
//    atk = 9;
//    id = i;
//}												// vim的批量注释：  Ctrl+V 进入块选模式 然后 选中你要注释的块 然后点 I 然后加入你要加的符号 比如 // 然后 点 Esc回到正常模式 就OK了

class CBase{
private:
	int num_iceman, num_ninja, num_wolf, num_lion, num_dragon;
	int id;
	char name[10];
public:
	static int hp_iceman, hp_ninja, hp_wolf, hp_lion, hp_dragon;					//vim 操作 replace x with y in the whole line 语法： ":s/x/y/g"(不带引号)
	void SetHP(int type, int i);
	int GetHP(int type);
	int CreateWarrior(int hp, int a[]);
	int GetID()
	{
		return id;
	}
	void Init()
	{
		num_iceman = num_ninja = num_wolf = num_lion = num_dragon = 0;
		id = 0;
	}
	CBase(char Name[10])
	{
		strcpy(name, Name);
		num_iceman = num_ninja = num_wolf = num_lion = num_dragon = 0;
		id = 0;
	}
};

int CBase::hp_dragon = 0;
int CBase::hp_ninja = 0;
int CBase::hp_iceman = 0;
int CBase::hp_wolf = 0;
int CBase::hp_lion = 0;

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


int CBase::CreateWarrior(int hp, int a[])
{
	int ok = 0;
	int curid = GetID();
	int i = 0;
	while (1)
	{
		if (hp >= GetHP(a[i%5]))
		{
			int curHP = GetHP(a[i%5]);
			cout << name;
			switch (a[i%5])
			{
			case 1:
				num_dragon++;
				cout << "dragon" << curid << "born with strength" << curHP << "," << num_dragon << "dragon in";
				break;
			case 2:
				num_ninja++;
				cout << "ninja" << curid << "born with strength" << curHP << "," << num_ninja << "ninja in";
				break;
			case 3:
				num_iceman++;
				cout << "iceman" << curid << "born with strength" << curHP << "," << num_iceman << "iceman in";
				break;
			case 4:
				num_lion++;
				cout << "lion" << curid << "born with strength" << curHP << "," << num_lion << "lion in";
				break;
			case 5:
				num_wolf++;
				cout << "wolf" << curid << "born with strength" << curHP << "," << num_wolf << "wolf in";
				break;
			}
			cout <<" "<< name << " headquarter" << endl;
			ok = 1;
			id++;
			i++;
		}
	}
	return ok;
}

int main(void)
{
	int N;
	int iniHP, hp[5];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> iniHP;
		int redHP =iniHP, blueHP = iniHP;
		for (int k = 0; k < 5; k++)	cin >> hp[k];
		CBase red("red"), blue("blue");
		int sred[5] = {3,4,5,2,1};
		int sblue[5] = {4,1,2,3,5};
		for (int i = 0; i < 5; i++)
		{
			red.SetHP(i, hp[i]);
		}
		int redok = 1;
		int blueok = 1;
		int time = 0;
		while (redok || blueok)
		{
			if (redok)
			{
				cout.fill('0');
				cout.setf(ios::right);
				cout.width(3);
				cout << time << " ";
				cout.unsetf(ios::right);
				redok=red.CreateWarrior(redHP, sred);
				if (!redok)
				{
					cout << "red headquarter stops making warriors" << endl;
				}
			}
			if (blueok)
			{
				cout.fill('0');
				cout.setf(ios::right);
				cout.width(3);
				cout << time << " ";
				cout.unsetf(ios::right);
				blueok=blue.CreateWarrior(blueHP, sblue);
				if (!blueok)
				{
					cout << "blue headquarter stops making warriors" << endl;
				}
			}
			time++;
		}
	}
	return 0;
}
