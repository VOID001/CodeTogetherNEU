/*************************************************************************
    > File Name: stack-1.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月28日 星期一 08时25分50秒
    > Content 顺序结构的栈
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#define OK 0
#define ERR -1
using namespace std;

const int MAXSIZE=1000;

typedef int SElemType;				//数据类型
typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

int push(SqStack* S,SElemType e)
{
	if(S->top==MAXSIZE-1) return ERR;
	S->top++;
	S->data[S->top]=e;
	return OK;
}

int pop(SqStack* S,SElemType* e)
{
	if(S->top==-1) return ERR;
	*e=S->data[S->top];
	S->top--;
	return OK;
}

int initStack(SqStack* S)
{
	S->top=-1;
	return OK;
}

int showTop(SqStack* S)
{
	if(S->top==-1) return ERR;
	cout<<S->data[S->top];
	return OK;
}

void printInfo()
{
	system("clear");
	cout<<"Stack Emulator"<<endl;
	cout<<"1 push"<<endl;
	cout<<"2 pop"<<endl;
	cout<<"3 show top"<<endl;
	cout<<"4 clear stack"<<endl;
	cout<<"9 show this manual"<<endl;
	cout<<"0 exit this Emulator"<<endl;
}

int main(void)
{
	SqStack* p=new SqStack;
	SElemType* e=new int;
	printInfo();
	initStack(p);
	int in=1;
	int st;
	while(in)
	{
		cin>>in;
		switch(in)
		{
			case 1:
				cin>> *e;
				push(p,*e);
				cout <<*e<<" Pushed!"<<endl;
				break;
			case 2:
				st=pop(p,e);
				if(st==ERR) cout<<"Stack is empty cannot pop"<<endl;
				else cout<<"Popped "<<*e<<" out"<<endl;
				break;
			case 3:
				showTop(p);
				break;
			case 4:
				initStack(p);
				break;
			case 9:
				printInfo();
				break;
			case 0:
				break;
		}
	}

	return 0;
}

