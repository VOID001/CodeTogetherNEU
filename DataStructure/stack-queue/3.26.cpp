/*************************************************************************
    > File Name: 3.26.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月01日 星期一 17时39分20秒
 ************************************************************************/



typedef struct data{
	double A;
	double p;
}Data;

typedef Data ElemType;

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;

double A,p;

const double e=2.718281828459;

int main(void)
{
	
}

double mysqrt_recursive(double A,double p,double e)
{
	if(p*p-A>-e && p*p-A<e) return p;
	else return mysqrt_recursive(A,0.5*(p+A/p),e);
}

double mysqrt_recursive(double A,double p,double e)
{
	stack<Data> S;
	Data d;
	d.A=A;
	d.p=p;
	S.push(d);
	double res=0;
	while(!S.empty())
	{
		d=S.top();	
		S.pop();
		if(d.p*d.p-d.A<e && d.p*d.p-d.A>-e)
		{
			res=d.p;
		}
		else
		{
			d.p=0.5*(d.p+d.A/d.p);
			S.push(d);	
		}
	}
	return res;
}



