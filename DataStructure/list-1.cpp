/*************************************************************************
  > File Name: list-1.cpp
  > Author: VOID_133
  > QQ: 393952764
  > Mail: zhangjianqiu13@gmail.com
  > Created Time: 2014年07月20日 星期日 08时47分35秒
  > Content:
  线性表的链式存储结构
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
/** 线性表的单链表存储结构 **/
typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

int getElement(LinkList L,int i,int* e);		//L 是链表地址 i是查找位置 e是用来接收查到的元素的
int listInsert(LinkList L,int i,int e);			//在L中第i个位置前面插入一个新元素e L长度加1
int listDel(LinkList L,int i,int* e);			//删除  L 中第 i个元素 并将值返回给 e
int createListHead(LinkList* L,int n);			//用头插法创建链表 长度为 n 随机生成元素
int createListTail(LinkList* L,int n);			//尾插法创建链表 长度 n随机生成元素
void printList(LinkList L);						//打印链表
//int listFind

int getElement(LinkList L,int i,int* e)
{
	int j=1;
	LinkList p=L->next;
	while(p && j<i)							//保证不要越界
	{
		p=p->next;
		j++;
	}
	if(p)
	{
		*e=p->data;
		return 1;									//1 代表正常返回
	}
	else return 0;
}

int listInsert(LinkList L,int i,int e)
{
	int j=1;
	LinkList p=L->next;
	LinkList s;
	while (p && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j>i-1 || !(p->next))
	{
		return 0;
	}
	{
		s=new Node;							//C++ 语法 new 新建LinkList
		s->data=e;
		s->next=p->next;
		p->next=s;
		return 1;
	}
}

int listDel(LinkList L,int i,int* e)			//删除  L 中第 i个元素 并将值返回给 e
{
	int j=1;
	LinkList p=L->next;
	//LinkList tmp;
	while(p && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j>i-1 || !(p->next))
	{
		return 0;
	}
	else
	{
		LinkList t=p->next;
		p->next=t->next;
		t->next=NULL;
		*e=t->data;
		delete t;
		t=NULL;
		return 1;
	}
}

int createListHead(LinkList* L,int n)
{
	LinkList p;
	srand(time(0));							//随机数种子
	*L=new Node;
	(*L)->next=NULL;
	while(n--)
	{
		p=new Node;
		p->next=(*L)->next;
		p->data=rand()%100+1;
		(*L)->next=p;						//将新的节点插入在头指针的后面 即链表的最前端
	}
	return 1;
}

int createListTail(LinkList* L,int n)
{
	LinkList p,r;
	srand(time(0));
	*L=new Node;
	(*L)->next=NULL;
	r=*L;
	while(n--)
	{
		p=new Node;
		p->data=rand()%100+1;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return 1;
}


void printList(LinkList L)
{
	int *e=new int;					//=new int
	int i=1;
	while(getElement(L,i++,e))
	{
		cout<<*e<<"->";
	}
	cout<<"NULL"<<endl;
	return ;
}

int main(void)
{
	LinkList* list1=new LinkList;
	int n;
	cout<<"输入你要建立的链表的大小"<<endl;
	cin>> n;
	createListTail(list1,n);
	int *e;
	cout<<"下面打印链表"<<endl;
	printList(*list1);
	while(n)
	{
		cout<<"请输入你要提取的元素编号 0 表示退出"<<endl;
		cin>>n;
		getElement(*list1,n,e);
		cout<<*e<<endl;
	}
	listInsert(*list1,4,23333);
	printList(*list1);
	listDel(*list1,9,e);
	printList(*list1);
	return 0;
}

