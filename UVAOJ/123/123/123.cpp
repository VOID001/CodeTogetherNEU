#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>
#include<map>			//multimap 必需
#include<set>			//set
#include<algorithm>		//count 必需
using namespace std;


int main(void)
{
	set<string> ig;						//忽略集合
	multimap<string, string> res;		//结果集合
	string igs;							//读取忽略字串
	string title;						//读取标题字串
	while (cin >> igs && igs != "::")
		ig.insert(igs);
	getchar();							//别忘了吃回车
	while (getline(cin, title))
	{
		for (int i = 0; i < title.size(); i++)
			title[i] = tolower(title[i]);
		for (int i = 0; i < title.size(); i++)
		{
			if (!isalpha(title[i])) continue;
			string key;					//存放关键词
			int cur_pos = i;			//自己写代码又忘了这个部分 记好~~ 
			while (i < title.size() && isalpha(title[i]))
			{
				key += title[i++];
			}
			if (!ig.count(key))
			{
				string tmp = title;
				for (int j = 0; j < key.size(); j++)
					key[j] = toupper(key[j]);
				tmp.replace(cur_pos, key.size(), key);
				res.insert(make_pair(key, tmp));
			}
		}
	}
	for (multimap<string, string>::iterator i = res.begin(); i != res.end(); i++)
		cout << i->second << endl;
	return 0;
}

//算是自己背着写的吧 。。理解了是理解了 自己想写出这种代码需要很好的功底