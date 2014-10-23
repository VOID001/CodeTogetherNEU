#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 220		//用打表法做 
void init();

string Vlst="AUEOI";							//有序V 。 C 表
string Clst = "JSBKTCLDMVNWFXGPYHQZR";		

vector<pair<string,int> > NUM;
int main(void)
{
	//freopen("10785.out", "w", stdout);
	init();
	int cnt;
	scanf("%d",&cnt);
	for (int i = 0; i < cnt; i++)
	{
		int in;
		scanf("%d", &in);
		printf("Case %d: ", i + 1);
		cout << NUM[in - 1].first;
		printf("\n");
	}
}

void init()
{
	for (int i = 1; i <=210;i++)
	{
		string tmp;
		int curposv=0, curposc=0;				//充当指针
		int cntV, cntC;							//充当计数器
		cntV = cntC = 0;
		int val = 0;
		while (tmp.size() != i)
		{
			tmp += Vlst[curposv];
			val += (Vlst[curposv] - 'A') % 8 + 1;
			cntV++;
			if (tmp.size() == i) break;
			tmp += Clst[curposc];
			val += (Clst[curposc] - 'A') % 8 + 1;
			cntC++;
			if (tmp.size() == i) break;
			if (cntV == 21) { cntV = 0; curposv++; }
			if (cntC == 5){ cntC = 0; curposc++; }
		}
		//按照字典序排序 不过这题都是大写不用考虑大小写问题
		for (int m = 0;m < tmp.size()-1; m += 2)				
		{
			if (m<tmp.size())
			for (int n = m + 2; n < tmp.size();n+=2)
			if (n<tmp.size() && tmp[n] < tmp[m])
			{
				char t = tmp[m];
				tmp[m] = tmp[n];
				tmp[n] = t;
			}
		}
		for (int m = 1; m < tmp.size(); m += 2)
		{
			if (m<tmp.size())
			for (int n = m + 2; n < tmp.size(); n += 2)
			if (n<tmp.size() && tmp[n] < tmp[m])
			{
				char t = tmp[m];
				tmp[m] = tmp[n];
				tmp[n] = t;
			}
		}
		//其实这个pair根本没什么用，直接string就可以 刚刚开始读题没明白留下的残局。。。 STL
		NUM.push_back(make_pair(tmp,val));
	}
	return;
}