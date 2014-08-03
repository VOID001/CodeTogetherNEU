#include<iostream>
#include<list>
#include<cstring>
#include<cstdlib>
#include<cstdio>


void printsnake();
using namespace std;

class CSnake{
	public:
		int x;
		int y;
};

list<CSnake> snake;

void processop(char* op)
{
	int len=strlen(op);
	int j;
	for(int i=0;i<len;i++)
	{
		if(op[i]=='R' && op[i+1]=='L')
		{
			j=i+1;
			while(op[j]=='L')
			{
				op[j]='R';
				j++;
			}
		}
		if(op[i]=='L' && op[i+1]=='R')
		{
			j=i+1;
			while(op[j]=='R')
			{
				op[j]='L';
				j++;
			}
		}
		if(op[i]=='U' && op[i+1]=='D')
		{	
			j=i+1;
			while(op[j]=='D')
			{
				op[j]='U';
				j++;
			}
		}
		if(op[i]=='D' && op[i+1]=='U')
		{
			j=i+1;
			while(op[j]=='U')
			{
				op[j]='D';
				j++;
			}
		}
	}
}


int getdir(int n,int m)
{
	int xhead,yhead,xnext,ynext;
	int dirx,diry;
	CSnake head=snake.front();
	xhead=head.x;
	yhead=head.y;
	int count=0;
	for(list<CSnake>::iterator ii=snake.begin();ii!=snake.end();ii++)
	{
		if(count==1)
		{
			xnext=(*ii).x;
			ynext=(*ii).y;
			break;
		}
		count++;
	}
	dirx=xhead-xnext;
	diry=yhead-ynext;
	//	cout<<"*******DEBUG*****"<<endl;
	//	cout<<"xhead="<<xhead<<" yhead="<<yhead<<endl;
	//	cout<<"xnext="<<xnext<<" ynext="<<ynext<<endl;
	//	cout<<"dirx="<<dirx<<" diry="<<diry<<endl;
	if(dirx==0 && (diry==1||diry==1-m)) return 1;                    //1 R
	else if(dirx==0 && (diry==-1||diry==m-1)) return 2;              //2 L
	else if ((dirx==1||dirx==1-n) && diry==0) return 3;              //3 D
	else if ((dirx==-1||dirx==n-1) && diry==0) return 4;             //4 U
}

bool touchbody()
{
	int xhead,yhead;
	CSnake head=snake.front();
	xhead=head.x;
	yhead=head.y;
	for(list<CSnake>::iterator ii=snake.begin();ii!=snake.end();ii++)
	{
		if(ii==snake.begin()) continue;
		if(xhead==(*ii).x && yhead==(*ii).y) return true;
	}
	return false;
}

void createsnake(int L)
{
	snake.clear();
	CSnake tmp;
	for(int i=0;i<L;i++)
	{
		scanf("%d%d",&tmp.x,&tmp.y);
		snake.push_back(tmp);
	}
	return ;
}

int movesnake(int n,int m,char op)
{
	//cout<<"******DEBUG*******"<<endl;
	//cout<<"move in "<<op<<" direction"<<endl;
	bool die=0;
	int dir=getdir(n,m);
	int xhead,yhead;
	CSnake head=snake.front();
	xhead=head.x;
	yhead=head.y;
	if(dir==1 && op=='L' || dir==2 && op=='R' || dir==3 && op=='U' || dir==4 &&op=='D')     //if move backwards omit it
	{
		if(dir==1){head.x+=0;head.y+=1;}
		if(dir==2){head.x+=0;head.y-=1;}
		if(dir==3){head.x+=1;head.y+=0;}
		if(dir==4){head.x-=1;head.y+=0;}
	}
	else
	{
		if(op=='L'){head.x+=0;head.y-=1;}
		if(op=='R'){head.x+=0;head.y+=1;}
		if(op=='D'){head.x+=1;head.y+=0;}
		if(op=='U'){head.x-=1;head.y+=0;}
	}
	if(head.x>n-1) head.x=0;
	if(head.x<0) head.x=n-1;
	if(head.y>m-1) head.y=0;
	if(head.y<0) head.y=m-1;
	snake.push_front(head);
	snake.pop_back();
	//cout<<"DEBUG SNAKE SHOW"<<endl;
	//printsnake();
	//cout<<endl;
	if(touchbody()) return -1;
	return 0;
}

void printsnake()
{
	for(list<CSnake>::iterator ii=snake.begin();ii!=snake.end();ii++)
	{
		printf("%d %d\n",(*ii).x,(*ii).y);
	}	
	return ;
}
int main(void)
{
	int T;
	cin>>T;
	char op[10010];
	while(T--)
	{
		bool die=0;
		int n,m,L;
		cin>>n>>m>>L;
		//if(L==1) die=1;
		createsnake(L);
		//printsnake();
		scanf("%s",op);
		processop(op);
		int len=strlen(op);
		for(int i=0;i<len && !die;i++)
		{
			if(i==0)
			{
				int dir=getdir(n,m);
				if(dir==1 && op[i]=='L' || dir==2 && op[i]=='R' || dir==3 && op[i]=='U' || dir==4 &&op[i]=='D') die=1;
				else
				{
					movesnake(n,m,op[i]);
				}

			}
			else
			{
				die=movesnake(n,m,op[i]);
			}

		}
		if(die)
		{
			cout<<"Sorry about that!"<<endl;
		}
		else
		{
			printsnake();
		}
		 cout<<endl;
	}

}


