/*************************************************************************
    > File Name: list-2.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月22日 星期二 06时46分34秒
    > Content:
		静态链表的实现
 ************************************************************************/
#define OK 0
#define ERR 1
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

const int MAXLENGTH=1000;
using namespace std;

typedef struct {
	int data;
	int cur;
}Component,StaticLinkList[MAXLENGTH];

int getElement(StaticLinkList L,int i,int* e);
int initList(StaticLinkList space);			//初始化静态链表
int malloc_SSL(StaticLinkList space);
int listInsert(StaticLinkList L,int i,int e);	//在链表第 i个元素前插入 e
void printList(StaticLinkList space);
int listDel(StaticLinkList space,int i,int* e);
int listLength(StaticLinkList L);				//获得链表的长度
int createLinkListHead(StaticLinkList L,int n);		//头插法创建链表
int createLinkListTail(StaticLinkList L,int n);		//尾插法创建链表
int listClear(StaticLinkList L);

int initList(StaticLinkList space)			//初始化静态链表数组首位的cur存的是第一个空闲的位置的下标 初始化为1 
{
	for(int i=0;i<MAXLENGTH-1;i++)
	{
		space[i].cur=i+1;
	}
	space[MAXLENGTH-1].cur=0;
	space[MAXLENGTH-1].data=0;					//Head Node is for storing the ListLength
	return OK;
}

int malloc_SSL(StaticLinkList space)
{
	int i=space[0].cur;						//第一个元素的下标就是
											//备用链表第一个元素的位置
	if(space[0].cur)
	{
		space[0].cur=space[i].cur;			//更改备用链表的可用性
	}
	return i;
}

int listInsert(StaticLinkList L,int i,int e)	//在链表第 i个元素前插入 e
{
	int j=1;
	int kcur=L[MAXLENGTH-1].cur;				//定位至头结点
	if(i<1 || i>listLength(L)-1)
		return ERR;
	j=malloc_SSL(L);
	L[j].data=e;
	for(int cnt=1;cnt<i-1;cnt++)
	{
		kcur=L[kcur].cur;						//kcur相当于list-1里的p指针 可以随意移动 这里 让指针指向 链表里第 i-1个元素
	}
	L[j].cur=L[kcur].cur;						//改变两个指针的指向
	L[kcur].cur=j;
	L[MAXLENGTH-1].data++;
	return OK;
}

int getElement(StaticLinkList L,int i,int* e)
{
	int j=1;
	int kcur;
	kcur=L[MAXLENGTH-1].cur;					//头指针
	if(i>listLength(L)-1)
		return ERR;
	for(j=1;j<i;j++)	
	{
		kcur=L[kcur].cur;
	}
	*e=L[kcur].data;
	return OK;
}

int createLinkListHead(StaticLinkList L,int n)		//头插法
{
	int j;
	srand(time(0));
	L[MAXLENGTH-1].data=n;
	while(n--)
	{
		j=malloc_SSL(L);
		L[j].data=rand()%100+1;	
		L[j].cur= L[MAXLENGTH-1].cur;
		L[MAXLENGTH-1].cur=j;
	}
	//	L[MAXLENGTH-1].data=n;			在这写这句 这时候n都变成 -1 了 n的值已经不是原来的链表长度了
	return OK;
}

int createLinkListTail(StaticLinkList L,int n)
{
	int j,r;
	srand(time(0));
	r=MAXLENGTH-1;							//将游标放在头结点
	L[MAXLENGTH-1].data=n;
	while(n--)
	{
		j=malloc_SSL(L);
		L[j].data=rand()%100+1;
		L[j].cur=L[r].cur;
		L[r].cur=j;
		r=j;
	}	
	//	L[MAXLENGTH-1].data=n;			在这写这句 这时候n都变成 -1 了 n的值已经不是原来的链表长度了
	return OK;
}

void printList(StaticLinkList L)
{
	int j=MAXLENGTH-1;
	while(L[j].cur)
	{
		j=L[j].cur;
		cout<<L[j].data<<"->";
	}
	cout<<"NULL"<<endl;
}

int free_SSL(StaticLinkList L,int j)			//释放的思路： 让这个结点变为备用链表里的节点 也就是 让 备用链表头节点变为当前节点 让当前节点指向下一个节点
{
	L[j].cur=L[0].cur;
	L[0].cur=L[j].cur;
	return OK;
}

int listDel(StaticLinkList L,int i,int* e)
{
	int j=1;
	int kcur=L[MAXLENGTH-1].cur;
	if(i>listLength(L)-1) return ERR;
	for(j=1;j<i-1;j++)
	{
		kcur=L[kcur].cur;
	}
	int p=L[kcur].cur;
	L[kcur].cur=L[p].cur;
	free_SSL(L,p);
	L[MAXLENGTH-1].data--;
	return OK;
}

int listLength(StaticLinkList L)
{
	return L[MAXLENGTH-1].data;
}

int listClear(StaticLinkList L)
{
	int kcur=L[MAXLENGTH-1].cur;
	int tmp;
	while(L[kcur].cur)
	{
		tmp=kcur;
		kcur=L[kcur].cur;
		free_SSL(L,tmp);
	}
	L[MAXLENGTH-1].cur=0;
	L[MAXLENGTH-1].data=0;
	return OK;
}

int main(void)
{
	int* e=new int;
	StaticLinkList SLL;
	initList(SLL);
	createLinkListTail(SLL,10);
	printList(SLL);
	getElement(SLL,4,e);
	cout<<*e<<endl;
	listDel(SLL,4,e);
	printList(SLL);
	cout<<*e<<endl;
	listInsert(SLL,4,233333);
	printList(SLL);
	listClear(SLL);
	printList(SLL);
	initList(SLL);
	createLinkListHead(SLL,20);
	printList(SLL);
	return 0;
}
