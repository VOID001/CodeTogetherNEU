/*********
  线性表的链式存储结构
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
#define OK 0
#define ERR 1
#define EOL -1
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
int listClear(LinkList *L);						//清空链表
int listSearch(LinkList L,int i,int* e);		//查找 元素 i出现的第一个位置 并把下标值返回给 e

int getElement(LinkList L,int i,int* e)
{
	if(L==NULL) return -1;
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
		return OK;									//1 代表正常返回
	}
	else return ERR;
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
		return ERR;
	}
	{
		s=new Node;							//C++ 语法 new 新建LinkList
		s->data=e;
		s->next=p->next;
		p->next=s;
		return OK;
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
		return ERR;
	}
	else
	{
		LinkList t=p->next;
		p->next=t->next;
		t->next=NULL;
		*e=t->data;
		delete t;
		t=NULL;
		return OK;
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
	return OK;
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
	return OK;
}


void printList(LinkList L)
{
	int *e=new int;					//=new int
	int i=1;
	while(!getElement(L,i++,e))
	{
		cout<<*e<<"->";
	}
	cout<<"NULL"<<endl;
}

int listClear(LinkList* L)
{
	LinkList p=(*L)->next;
	LinkList curdel=*L;
	*L=NULL;
	while(p)
	{
		delete curdel;
		curdel=NULL;
		curdel=p;
		p=p->next;
	}
	p=NULL;
	return OK;
}

int listSearch(LinkList L,int i,int*e)
{
	int j=1;
	LinkList p=L->next;
	while(p)
	{
		if(p->data==i) 
		{
			*e=j;
			return OK;
		}
		else 
		{
			p=p->next;
			j++;
		}
	}
	return ERR;
}



int main(void)
{
	LinkList* list1=new LinkList;
	int n;
	cout<<"输入你要建立的链表的大小"<<endl;
	cin>> n;
	createListTail(list1,n);
	int *e=new int;
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
	cout<<"Input an Element you want to find"<<endl;
	cin>>n;
	int status=listSearch(*list1,n,e);
	if(status) 
	{
		cout<<"ERROR!"<<endl;
	}
	else 
	{
		cout<<*e<<endl;
	}
	listClear(list1);
	printList(*list1);
	return 0;
}

