/*************************************************************************
    > File Name: stack-3.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月29日 星期二 09时44分03秒
    > Content 链栈
 ************************************************************************/
#include<iostream>
#define OK 0
#define ERR -1

using namespace std;
typedef int ElemType;
typedef struct Node{
	struct Node* next;
	ElemType data;	
}Node,*LinkStackPtr;

typedef struct LinkStack{
	LinkStackPtr top;
	int count;
}LinkStack;

int initStack(LinkStack* S)
{
	while(S->top!=NULL)					//零 代表空栈 
	{
		LinkStackPtr p=S->top;
		S->top=S->top->next;
		delete p;
		S->count--;
	}
	S->top=NULL;
	return OK;
}


int push(LinkStack* S,int e)
{
	LinkStackPtr p=new Node;
	p->data=e;
	p->next=S->top;
	S->top=p;
	S->count++;
	return OK;				
}

int pop(LinkStack* S,int* e)
{
	if(S->top==NULL) return ERR;
	*e=S->top->data;
	LinkStackPtr p=S->top;
	S->top=S->top->next;
	S->count--;
	return OK;
}

int main(void)
{
	LinkStack* stack=new LinkStack;
	int* e=new int;
	initStack(stack);
	push(stack,3);
	push(stack,100);
	push(stack,99);
	push(stack,23333);
	pop(stack,e);
	cout<<*e<<endl;
	pop(stack,e);
	cout<<*e<<endl;
	pop(stack,e);
	cout<<*e<<endl;

	return 0;
}
