#define LOCAL
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<list>

using namespace std;

void v_search();

vector<int> src;
queue<int> fnd;

int Q, N;

int main(void)
{
	int tmp;
	int count = 1;
	while (scanf("%d%d", &N, &Q) == 2)
	{
		src.clear();
		for (int i = 0; i<N; i++)
		{
			scanf("%d", &tmp);
			src.push_back(tmp);
		}
		for (int i = 0; i<Q; i++)
		{
			scanf("%d", &tmp);
			fnd.push(tmp);
		}
		//输入结束 开始查找
		printf("CASE# %d:\n", count++);
		v_search();
	}
}

void v_search()
{
	int now;
	sort(src.begin(), src.end());
	vector<int>::iterator it;
	bool found;
	while (fnd.size())
	{
		now = fnd.front();
		fnd.pop();
		it = find(src.begin(), src.end(), now);
		if (it == src.end())
			printf("%d not found\n", now);
		else
			printf("%d found at %d\n", now, (it - src.begin())/sizeof(int)+1);
	}
	return;
}
