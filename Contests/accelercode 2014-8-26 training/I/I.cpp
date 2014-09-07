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


vector<pair<string,string> > category;
vector<string> catvec;

bool cmp(const pair<string,string> p1,const pair<string,string> p2)
{
	return p1.second<p2.second;
}



string item;


int main(void)
{
	int T;
	char s[205];
	char* p;
	char* q;
	while(scanf("%d",&T)!=EOF)
	{
		getchar();
		catvec.clear();
		map<string,int> catcnt;
		for(int i=0;i<T;i++)
		{
			cin>>item;
			getchar();
			string cate;
			gets(s);
			p=s;
			q=p;
			while(*q!='\0')
			{
				if(*q==' ')
				{
					*q='\0';
					q++;
					cate=p;
					category.push_back(make_pair(item,cate));
					if(catcnt.count(cate)!=1)
					{
						catvec.push_back(cate);
						catcnt[cate]=0;
					}
					p=q;
				}
				else q++;
			}
			cate=p;
			category.push_back(make_pair(item,cate));
			if(catcnt.count(cate)!=1)
			{
				catvec.push_back(cate);
				catcnt[cate]=0;
			}
			catcnt[cate]=0;
		}
		sort(category.begin(),category.end(),cmp);
		sort(catvec.begin(),catvec.end());
		int cases;
		scanf("%d",&cases);
		getchar();
		int querynum=0;
		while(cases--)
		{
			for(vector<string>::iterator ii=catvec.begin();ii!=catvec.end();ii++)
			{
				catcnt[*ii]=0;
			}
			querynum=0;
			gets(s);
			p=s;
			q=p;
			string itt;
			while(*q!='\0')
			{
				if(*q==' ')
				{
					*q='\0';
					q++;
					itt=p;
					for(vector<pair<string,string> >::iterator ii=category.begin();ii!=category.end();ii++)
					{
						if((*ii).first==itt) catcnt[(*ii).second]++;
					}
					p=q;
					querynum++;
				}
				else q++;
			}
			querynum++;
			itt=p;
			for(vector<pair<string,string> >::iterator ii=category.begin();ii!=category.end();ii++)
			{
				if((*ii).first==itt) catcnt[(*ii).second]++;
			}

			int ok=0;
			int cntt=0;
			for(vector<string>::iterator ii=catvec.begin();ii!=catvec.end();ii++)
			{
				//cout<<catcnt[*ii]<<" ";
				if(catcnt[*ii]==querynum)
				{
					if(cntt!=0) printf(" ");
					cout<<*ii;
					ok=1;
					cntt++;
				}
			}
			if(!ok) printf("NO\n");
			else printf("\n");
		}
	}

return 0;
}

