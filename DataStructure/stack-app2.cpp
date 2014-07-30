/*************************************************************************
    > File Name: stack-app2.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月29日 星期二 21时46分46秒
    > Content 递归不写了，直接写四则表达式运算:
 ************************************************************************/
#include<iostream>
#include<cstring>
#include<cstdio>
#define OK 0
#define ERR -1

using namespace std;
typedef char ElemType;
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


int push(LinkStack* S,ElemType e)
{
	LinkStackPtr p=new Node;
	p->data=e;
	p->next=S->top;
	S->top=p;
	S->count++;
	return OK;				
}

int pop(LinkStack* S,ElemType* e)
{
	if(S->top==NULL) return ERR;
	*e=S->top->data;
	LinkStackPtr p=S->top;
	S->top=S->top->next;
	S->count--;
	return OK;
}

bool isEmpty(LinkStack* S)
{
	if(S->top==NULL) return true;
	return false;
}

int getTop(LinkStack* S,ElemType* e)
{
	*e=S->top->data;
	return OK;
}

bool priorjudge(char op,char top)					//True 出栈 False NO POP 
{
	if(top=='(') return false;
	if(op=='+' || op=='-')
	{
		return true;
	}
	if(op=='*' || op== '/')
	{
		if(top=='+' || top== '-' ) return false;
		return true;
	}
}

char* normToRPN(char* str)
{
	char* expRPN=new char[1000];
	memset(expRPN,0,sizeof(expRPN));
	LinkStack* opstack=new LinkStack;
	initStack(opstack);
	int len=strlen(str);
	int cnt=0;
	char* tmpc=new char;
	char* tope=new char;

	for(int i=0;i<len;i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			expRPN[cnt]=str[i];
			cnt++;
		}
		else
		{
			if(expRPN[cnt-1]!=' ')
			{
				expRPN[cnt]=' ';
				cnt++;
			}
			if(isEmpty(opstack))
			{
				push(opstack,str[i]);
			}
			else
			{
				getTop(opstack,tope);
				if(str[i]==')')
				{
					while(*tope!='(')
					{
						pop(opstack,tmpc);
						expRPN[cnt]=*tmpc;
						cnt++;
						getTop(opstack,tope);
					}
					pop(opstack,tmpc);		//左右括号不入表达式
					//右括号不入栈
				}
				else if(str[i]=='(')
				{
					push(opstack,str[i]);
				}
				else if(priorjudge(str[i],*tope))
				{
					while(!isEmpty(opstack) && priorjudge(str[i],*tope))
					{
						pop(opstack,tmpc);
						expRPN[cnt]=*tmpc;
						cnt++;
						if(isEmpty(opstack)) break;
						getTop(opstack,tope);
					}
					push(opstack,str[i]);
					//Pop them out of the stack and push current element into stack
				}
				else
				{
					push(opstack,str[i]);
					//push it into stack
				}
			}
		}
	}
	while(!isEmpty(opstack))
	{
		pop(opstack,tmpc);
		expRPN[cnt]=*tmpc;
		cnt++;
	}
	return expRPN;
}

int main(void)
{
	char *expmain=new char[1000];
	char s[1000];
	scanf("%s",s);
	expmain=normToRPN(s);
	printf("%s\n",expmain);

	return 0;
}
