/*************************************************************************
    > File Name: J.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2014年11月23日 星期日 15时01分05秒
 ************************************************************************/
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

int id=0;

vector<string> idcache;

string devname;
string name;
int  price;
int minprice[10];
int chosenum[10];
int enable[10];


int ID(const string& str)
{
	int cnt=0;
	for(vector<string>::iterator ii=idcache.begin();ii!=idcache.end();ii++)
	{
		if(str==*ii) 
		{
//			cout<<cnt<<"="<<*ii<<endl;
			return cnt;
		}
		cnt++;
	}
	idcache.push_back(str);
	return cnt;
}

string& revID(int i)
{
	return idcache[i];
}


int main(void)
{
	for(int i=0;i<6;i++)
	{
		minprice[i]=1000001;
	}
	memset(enable,0,sizeof(enable));

	for(int i=0;i<6;i++)
	{
		cin>>name;
		cin>>devname;
		cin>>price;
		chosenum[ID(devname)]++;
		if(minprice[ID(devname)]>price)
		{
			minprice[ID(devname)]=price;
		}
	}
	int maxchosenum=0;
	for(int i=0;i<6;i++)
	{
		if(chosenum[i]>maxchosenum)
		{
			maxchosenum=chosenum[i];
		}
	}

	int minn=10000001;
	for(int i=0;i<6;i++)
	{
		if(chosenum[i]==maxchosenum)
		{
			enable[i]=1;
			if(minn>minprice[i])
			{
				minn=minprice[i];
			}
		}
	}

	//cout<<"minprice="<<minn<<endl;
	//cout<<"maxchose="<<maxchosenum<<endl;
	//for(int i=0;i<6;i++) cout<<chosenum[i]<<endl;
	for(int i=0;i<6;i++)
	{
		if(enable[i])
		{
			if(minn==minprice[i])
			{
				cout<<revID(i)<<endl;
				break;
			}
		}
	}


	return 0;
}


