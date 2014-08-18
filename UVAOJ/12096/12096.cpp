/*************************************************************************
  > File Name: 12096.cpp
  > Author: VOID_133
  > QQ: 393952764
  > Mail: zhangjianqiu13@gmail.com
  > Created Time: 2014年08月15日 星期五 11时07分00秒
 ************************************************************************/
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include<map>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std;

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(const Set& x)
{
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x]=Setcache.size()-1;
}

int main(void)
{
	stack<int> s;
	int n;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		while(n--)
		{
			char op[10];
			scanf("%s",op);
			if(op[0]=='P')
				s.push(ID(Set()));
			else if(op[0]=='D')
				s.push(s.top());
			else
			{
				Set x1=Setcache[s.top()];s.pop();
				Set x2=Setcache[s.top()];s.pop();
				Set x;
				if(op[0]=='U')
					//x=set_union(ALL(x1),ALL(x2),INS(x));
					set_union(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='I')
					//x=set_intersection(ALL(x1),ALL(x2),INS(x));
					set_intersection(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='A')
				{x=x2;x.insert(ID(x1));}
				s.push(ID(x));
			}
			cout<<Setcache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
	return 0;
}


