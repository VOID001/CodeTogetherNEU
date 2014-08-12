/*************************************************************************
    > File Name: 1002.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月10日 星期日 19时27分41秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>

const double maxd=1e20;
double eps=1e-9;

using namespace std;


vector<int> v;
vector<double> vdis;
bool cov[1000];
double dis[1000];

int N;
bool cmp(int a,int b)
{
	return a>b;
}

bool fill(double a)
{
	bool ok=0;
	memset(cov,0,sizeof(cov));
	cov[0]=1;
	cov[N-1]=1;
	for(int i=0;i<N-1;i++)
	{
		//if(dis[i]<a && dis[i+1]<a) return false;
		//if(cov[i]==0 && dis[i]<2*a && dis[i]!=a && dis[i+1]<a) return false;
		//if(dis[i]==a || dis[i]>=2*a){cov[i]=1;cov[i+1]=1;}
		if(dis[i]>a) {cov[i]=1;}
		//if(dis[i]==a) {cov[i]=1;cov[i+1]=1;}
		if((dis[i]-a)>-eps && (dis[i]-a)<eps) {cov[i]=1;cov[i+1]=1;}
		if(dis[i]>=2*a) {cov[i]=1;cov[i+1]=1;}
	}
	for(int i=0;i<N;i++)
		if(!cov[i]) return false;
	return true;
}



int main(void)
{
	int T;
	int a;
	cin>>T;
	while(T--)
	{
		double res;
		cin>>N;
		v.clear();
		vdis.clear();
		int tt=N;
		while(tt--)
		{
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		//cout<<"DEBUG"<<endl;
		//for(vector<int>::iterator ii=v.begin();ii!=v.end();ii++)
		//	cout<<*ii<<" ";
		//cout<<endl<<"DEBUGEND"<<endl;
		int now;
		int pre;
		for(vector<int>::iterator ii =v.begin();ii!=v.end();ii++)
		{
			if(ii==v.begin())
			{
				now=*ii;
				pre=now;
			}
			else
			{
				now=*ii;
				vdis.push_back(now-pre);
				pre=now;
			}
		}
		bool ok=1;
		int count=0;
		for(vector<double>::iterator ii=vdis.begin();ii!=vdis.end();ii++)
		{
			dis[count++]=*ii;
		}
		dis[count]=maxd;
		sort(vdis.begin(),vdis.end(),cmp);
		//cout<<"DEBUG"<<endl;
		//for(vector<double>::iterator ii=vdis.begin();ii!=vdis.end();ii++)
		//	cout<<*ii<<" ";
		//cout<<endl<<"DEBUGEND"<<endl;
		count=0;
		double max=-300;
		for(vector<double>::iterator ii=vdis.begin();ii!=vdis.end();ii++)
		{
			count++;
			if(count==N) break;
			if(fill(*ii) && max<*ii) max=*ii;
			//cout<<"max="<<max<<endl;
			if(fill(*ii/2) && max<*ii/2) max=*ii/2;
			//cout<<"max="<<max<<endl;
		}
		printf("%.3lf\n",max);
	}
	return 0;
}
