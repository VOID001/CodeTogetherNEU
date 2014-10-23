/**UVAOJ 10194 对多个项目进行排序**/
#define LOCAL
#include<iostream>
#include<stdio.h>
#include<set>
#include<string>
#include<algorithm>
#include<vector>				//SET 不能自定义sort函数么？ 用了vector问题就解决了
using namespace std;

typedef struct team
{
	string name;
	//int rank=0;
	int points=0;
	int played=0;
	int wins=0;
	int ties = 0;
	int lose = 0;					//输的比赛次数
	int losses = 0;					//输球几个
	int differ = 0;
	int goals = 0;
}team;

bool cmp(const team *a, const team*b)					//自定义比较函数
{
	if (a->points > b->points) return true;
	else if (a->points < b->points) return false;
	else
	{
		if (a->wins>b->wins) return true;
		else if (a->wins < b->wins) return false;
		else
		{
			if (a->differ>b->differ) return true;
			else if (a->differ < b->differ) return false;
			else
			{
				if (a->goals>b->goals) return true;
				else if (a->goals < b->goals) return false;
				else
				{
					if (a->played<b->played) return true;
					else if (a->played > b->played) return false;
					else
					{
						string tmpa, tmpb;
						tmpa = a->name;
						tmpb = b->name;
						for (int oo = 0; oo < tmpa.size(); oo++) tmpa[oo] = tolower(tmpa[oo]);
						for (int oo = 0; oo < tmpb.size(); oo++) tmpb[oo] = tolower(tmpb[oo]);
						return tmpa < tmpb;
					}
				}
			}
		}
	}
}

int main(void)
{
#ifdef LOCAL
	freopen("10194.out","w",stdout);
#endif
	string game;
	int matches;
	int num;
	scanf("%d", &matches);
	getchar();							//吃回车
	for (int i = 0; i < matches; i++)
	{
		getline(cin, game);
		scanf("%d", &num);
		getchar();						//吃回车
		vector<team*> T;
		team tmp[32];
		for (int oo = 0; oo < num; oo++)
		{
			getline(cin, tmp[oo].name);
			T.push_back(&tmp[oo]);
		}						//存入各个小组信息
		scanf("%d", &num);		//比赛场数
		getchar();				//再吃回车
		for (int oo = 0; oo < num; oo++)
		{
			string data;		//读入信息的区域
			getline(cin, data);
			string cur;
			int cnt = 0;
			team *curteama,*curteamb;
			int scorea = 0 , scoreb = 0;
			while (data[cnt] != '#') cur += data[cnt++];
			for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)
			if ((*i)->name == cur) curteama = *i;	//定位到当前队伍a
			cnt++;
			while (data[cnt] != '@')										//读取比分 先读 a team
			{
				scorea = scorea * 10 + data[cnt] - '0';
				cnt++;
			}
			cnt++;
			while (data[cnt] != '#')
			{
				scoreb = scoreb * 10 + data[cnt] - '0';						//再读b team
				cnt++;
			}
			cur.clear();													//不能忘记清空cur
			cnt++;
			while (data[cnt] != '\0') cur += data[cnt++];					//然后再记录下一个队伍名称										
			for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)		//定位到当前队伍b
			if ((*i)->name == cur) curteamb = *i;
			//开始判断 并记录
			//curteama->played += scorea;
			//curteamb->played += scoreb;
			curteama->losses += scoreb;
			curteamb->losses += scorea;
			curteama->goals += scorea;
			curteamb->goals += scoreb;
			curteama->played++;
			curteamb->played++;
			if (scorea > scoreb)											//分为a赢了b a b平 a输给 b三种情况
			{
				curteama->wins++;
				curteamb->lose++;
				curteama->points += 3;
				curteamb->points += 0;
			}
			else if (scorea < scoreb)
			{
				curteamb->wins++;
				curteama->lose++;
				curteamb->points += 3;
				curteama->points += 0;
			}
			else if (scorea == scoreb)
			{
				curteama->ties++;
				curteamb->ties++;
				curteama->points++;
				curteamb->points++;
			}
			//判断结束
		}
		for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)
		{
			(*i)->differ = (*i)->goals - (*i)->losses;
		}
		sort(T.begin(), T.end(), cmp);
		int count = 1;
		cout << game << endl;
		for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)
		{
			cout << count++ << ") " << (*i)->name << " " << (*i)->points << "p, " << (*i)->played << "g (" << (*i)->wins << "-" << (*i)->ties << "-" << (*i)->lose << "), " << (*i)->differ << "gd (" << (*i)->goals << "-" << (*i)->losses << ")";
			printf("\n");
		}
		if(i<matches-1) printf("\n");
	}
	getchar();
	return 0;
}


/**
Most points earned.
Most wins.
Most goal difference (i.e. goals scored - goals against)
Most goals scored.
Less games played.
Lexicographic order.			这里比较是不分大小写的！！！！Aa属于同样权重
**/