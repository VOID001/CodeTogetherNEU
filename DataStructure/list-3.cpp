/*************************************************************************
    > File Name: list-3.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月24日 星期四 11时59分04秒
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
#define OK 0
#define ERR -1
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Node* CycleLinkList;

int createListHead(CycleLinkList* Lrear,int n)
{
	CycleLinkList p;
	(*Lrear)=new Node;
	srand(clock());
	(*Lrear)->next=*Lrear; n++; while(n--)
	{
		p=new Node;
		p->next=(*Lrear)->next;
		p->data=rand()%100+1;
		(*Lrear)->next=p;						//最后一个节点是头结点
	}	
	return OK;
}

int merge2List(CycleLinkList Lrear1,CycleLinkList Lrear2)
{
	CycleLinkList p=(Lrear1)->next;
	(Lrear1)->next=(Lrear2)->next->next;
	CycleLinkList q=(Lrear2)->next;
	(Lrear2)->next=p;
	free(q);
	q=NULL;
	//Lrear1=NULL;
	return OK;
}

void printList(CycleLinkList L)
{
	CycleLinkList p=L->next->next;				//游标初始定位为头指针
	while(p!=L)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
	cout<<"DEBUG"<<L->data<<endl;
}

int main(void)
{
	CycleLinkList* cyclist1=new CycleLinkList;
	CycleLinkList* cyclist2=new CycleLinkList;
	createListHead(cyclist1,2);
	cout<<"************LIST1***************"<<endl;
	printList(*cyclist1);
	createListHead(cyclist2,2);
	cout<<"************LIST2***************"<<endl;
	printList(*cyclist2);
	merge2List(*cyclist1,*cyclist2);
	printList(*cyclist2);
	return 0;
}


//这个代码会在合并之后的链表多输出一个 0 原因就是 这个循环链表建立的时候 ，尾指针没存data  默认为 0 了
