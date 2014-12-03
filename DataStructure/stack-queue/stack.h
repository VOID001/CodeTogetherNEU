/*************************************************************************
    > File Name: stack.h
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月01日 星期一 17时43分43秒
	> Description: A SqStack
 ************************************************************************/

#include<cstdio>
#include<cstdlib>

//typedef struct Node{
//	ElemType data;
//	struct Node* pre;
//}Node;


typedef Status int;
#define OK 0
#define ERR -1
#define OVERFLOW -2

const int STACK_INIT_SIZE=100;
const int STACK_INCREMENT=10;


typedef struct Stack{
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;

Status initStack(SqStack& S);
Status destroyStack(SqStack& S);
Status isEmpty(SqStack& S);
Status getlength(SqStack& S);
Status getTop(SqStack& S,ElemType& e);
Status push(SqStack& S,ElemType& e);
Status pop(SqStack& S,ElemType& e);

Status initStack(SqStack& S)
{
	
}



