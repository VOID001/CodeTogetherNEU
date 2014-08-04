#define LOCAL
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#define MAX 5050

using namespace std;
void Calc_Dist();
void d_Search();

typedef struct Point
{
	double x;
	double y;
	double z;
}P;



vector<double> dist;
vector<P> pt;
int oo = 0;				//计数器
int res[15];
P p[MAX];
P pp;
double x, y, z, dis;
double cmp[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int main(void)
{
#ifdef LOCAL
	freopen("152.in", "r", stdin);
#endif //LOCAL
	memset(res, 0, sizeof(res));
	while (scanf("%lf%lf%lf", &x, &y, &z) && ~(x == 0 && y == 0 && z == 0))
	{
		pp.x = x;
		pp.y = y;
		pp.z = z;
		pt.push_back(pp);
	}
	Calc_Dist();//生成有序距离表代码
	d_Search();//查找距离表代码
	for (int i = 0; i < 10; i++)
		printf("%4d", res[i]);
	return 0;
}

void Calc_Dist()
{
	vector<P>::iterator iteri,iterj;
	for (iteri=)
	{
		for (int j = i + 1; j < oo; j++)
		{
			dis = (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y) + (p[i].z - p[j].z)*(p[i].z - p[j].z);
			dist.push_back(dis);
		}
	}
	sort(dist.begin(), dist.end());
	return;
}

void d_Search()
{
	vector<double>::iterator iter;
	int oo = 0;
	for (iter = dist.begin(); iter != dist.end(); iter++)
	{
		while (oo < 10)
		{
			if (*iter < cmp[oo] * cmp[oo]) { res[oo]++; break; }
			else if (res[oo] != 0) { res[oo]++ ; oo++; }
			else oo++;
		}
		if (oo == 10) break;	       //优化算法
	}
}