/*************************************************************************
    > File Name: stack-2.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月28日 星期一 14时28分26秒
    > Content : Double Stack
 ************************************************************************/
#include<iostream>
#define OK 0
#define ERR -1
using namespace std;

const int MAXSIZE=1000;

typedef int DSElemType;
typedef struct {
	DSElemType data[MAXSIZE];
	int top1;
	int top2;
}DoubleSqStack;

int initStack(DoubleSqStack* S)
{
	S->top1=-1;					//初始化两个栈为空栈 
	S->top2=MAXSIZE;
	return OK;
}

int push(DoubleSqStack* S,int e,int number)
{
	if(S->top1+1==S->top2) return ERR;
	if(number==1)
	{
		S->top1++;
		S->data[S->top1]=e;
	}
	else
	{
		S->top2--;
		S->data[S->top2]=e;
	}
	return OK;
}


int pop(DoubleSqStack* S,int* e,int number)
{
	if(number==1 && S->top1==-1 || number==2 && S->top2==MAXSIZE) return ERR;
	if(number==1)
	{
		*e=S->data[S->top1];
		S->top1--;
	}
	else
	{
		*e=S->data[S->top2];
		S->top2++;
	}
	return OK;
}

int main(void)
{
	DoubleSqStack* stack1=new DoubleSqStack;
	int* e=new int;
	push(stack1,2,1);
	push(stack1,1000,2);
	push(stack1,233,1);
	push(stack1,1101010,1);
	pop(stack1,e,1);
	cout<<*e<<endl;
	pop(stack1,e,2);
	cout<<*e<<endl;
	return 0;
}
