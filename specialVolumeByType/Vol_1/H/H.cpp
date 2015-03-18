/*************************************************************************
    > File Name: H.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2015年03月02日 星期一 19时16分18秒
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

typedef struct node{
	int potA;
	int potB;
	string path;
}Node;

bool vis[150][150];

bool validate(Node a)
{
	if(vis[a.potA][a.potB]==1) return false;
	return true;
}

string bfs(int sizeA,int sizeB,int dest)
{
	queue<Node> que;
	memset(vis,0,sizeof(vis));
	Node tmp;
	tmp.potA=0;
	tmp.potB=0;
	tmp.path.clear();
	vis[0][0]=1;

	que.push(tmp);
	while(!que.empty())
	{
		Node ttmp=que.front();
		que.pop();
		if(ttmp.potA==dest || ttmp.potB==dest) return ttmp.path;
		//FILL(A)
		if(ttmp.potA!=sizeA)
		{
			Node tt=ttmp;
			tt.potA=sizeA;
			tt.path.push_back('A');
			if(validate(tt))
			{
				que.push(tt);
				vis[tt.potA][tt.potB]=1;
			}
		}
		//FILL(B)
		if(ttmp.potB!=sizeB)
		{
			Node tt=ttmp;
			tt.potB=sizeB;
			tt.path.push_back('B');
			if(validate(tt))
			{
				que.push(tt);
				vis[tt.potA][tt.potB]=1;
			}
		}
		//DROP(A)
		if(ttmp.potA>0)
		{
			Node tt=ttmp;
			tt.potA=0;
			tt.path.push_back('C');
			if(validate(tt))
			{
				que.push(tt);
				vis[tt.potA][tt.potB]=1;
			}
		}
		//DROP(B)
		if(ttmp.potB>0)
		{
			Node tt=ttmp;
			tt.potB=0;
			tt.path.push_back('D');
			if(validate(tt))
			{
				que.push(tt);
				vis[tt.potA][tt.potB]=1;
			}
		}
		//POUR(A,B)
		if(ttmp.potA>0)
		{
			Node tt=ttmp;
			if(tt.potA<=sizeB-tt.potB)
			{
				tt.potB+=tt.potA;
				tt.potA=0;
			}
			else if(tt.potA>sizeB-tt.potB)
			{
				tt.potA-=sizeB-tt.potB;
				tt.potB=sizeB;
			}
			tt.path.push_back('E');
			if(validate(tt))
			{
				que.push(tt);
				vis[tt.potA][tt.potB]=1;
			}
		}
		//POUR(B,A)
		if(ttmp.potB>0)
		{
			Node tt=ttmp;
			if(tt.potB<=sizeA-tt.potA)
			{
				tt.potA+=tt.potB;
				tt.potB=0;
			}
			else if(tt.potB>sizeA-tt.potA)
			{
				tt.potB-=sizeA-tt.potA;
				tt.potA=sizeA;
			}
			tt.path.push_back('F');
			if(validate(tt))
			{
				que.push(tt);
				vis[tt.potA][tt.potB]=1;
			}
		}
	}
	return "impossible";
}

int main(void)
{
	int szA,szB,dest;
	while(scanf("%d%d%d",&szA,&szB,&dest)!=EOF)
	{
		string ss=bfs(szA,szB,dest);
		if(ss!="impossible")
		{
			cout<<ss.length()<<endl;
			int len=ss.length();
			for(int i=0;i<len;i++)
			{
                switch(ss[i])
                {
                    case 'A':
                        cout<<"FILL(1)"<<endl;
                        break;
                    case 'B':
                        cout<<"FILL(2)"<<endl;
                        break;
                    case 'C':
                        cout<<"DROP(1)"<<endl;
                        break;
                    case 'D':
                        cout<<"DROP(2)"<<endl;
                        break;
                    case 'E':
                        cout<<"POUR(1,2)"<<endl;
                        break;
                    case 'F':
                        cout<<"POUR(2,1)"<<endl;
                        break;
                }
			}
		}
		else
			cout<<ss<<endl;
	}
	return 0;
}
