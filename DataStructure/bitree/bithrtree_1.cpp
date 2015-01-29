/*************************************************************************
    > File Name: bithrtree.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2014年12月13日 星期六 08时52分44秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;

typedef int ElemType ;
typedef int Status ;

const int OK=0;
const int ERR=-1;

typedef enum {link,thread} PointerType;


//typedef struct Data{
//	ElemType data;
//	int key;
//}Data;

typedef struct bithrtree{
	bithrtree* left;
	bithrtree* right;
	bithrtree* father;
	ElemType data;
	//int ltag;
	//int rtag;
	PointerType ltag,rtag;
}Bithrtree;

//Function Prototype
//
//
void visit(Bithrtree* T);
Bithrtree* createBithrtree(char* inOrderStr,char* preOrderStr);
void preOrderTransverse(Bithrtree* T);
Bithrtree* InOrderThreading(Bithrtree* T);
void inThreading(Bithrtree* T);
void inOrderTransverse_Thr(Bithrtree* T);

//Global Variable
//
//
Bithrtree* pre;

//Function Body
Bithrtree* createBithrtree(char* inOrderStr,char* preOrderStr)
{
    ///printf("%s %s\n",inOrderStr,preOrderStr);
	if(inOrderStr[0]=='\0'||preOrderStr[0]=='\0') return NULL;
	Bithrtree *T=(Bithrtree*)malloc(sizeof(Bithrtree));
	//printf("%s %s\n",inOrderStr,preOrderStr);
	T->data=preOrderStr[0];
	T->right=NULL;
	T->left=NULL;
	T->rtag=link;
	T->ltag=link;
	int len=strlen(inOrderStr);
	//if(len==1)  return T;
	int pos=-1;
	int i;
	for(int i=0;i<len;i++)
	{
		if(inOrderStr[i]==preOrderStr[0])
		{
			pos=i;
			break;
		}
	}
	//Process the two Strings CREATE LEFT Sub-TREE
	char inOrder[1000]="";
	char preOrder[1000]="";
	memset(inOrder,0,sizeof(inOrder));
	memset(preOrder,0,sizeof(preOrder));
	for(i=0;i<pos;i++)
	{
		inOrder[i]=inOrderStr[i];
	}
	for(i=0;i<pos;i++)
	{
		preOrder[i]=preOrderStr[i+1];
	}
	//printf("%s %s %d mark\n",inOrder,preOrder,pos);
	T->left=createBithrtree(inOrder,preOrder);
    memset(inOrder,0,sizeof(inOrder));
	memset(preOrder,0,sizeof(preOrder));
	int now=0;
	for(i=pos+1;i<len;i++)
	{
		inOrder[now]=inOrderStr[i];
		preOrder[now++]=preOrderStr[i];
	}
	//printf("%s %s %d mark\n",inOrderStr,preOrder,pos);
	T->right=createBithrtree(inOrder,preOrder);
	return T;

}
Bithrtree* InOrderThreading(Bithrtree* T)
{
	Bithrtree* Thrt=(Bithrtree*)malloc(sizeof(Bithrtree));
	if(!Thrt) return NULL;
	Thrt->ltag=link;
	Thrt->rtag=thread;
	Thrt->right=Thrt;
	if(!T) Thrt->left=Thrt;
	else
	{
		Thrt->left=T;
		pre=Thrt;
		inThreading(T);
		pre->right=Thrt;
		pre->rtag=thread;
		Thrt->right=pre;
	}
	return Thrt;
}

void inThreading(Bithrtree* T)
{
	if(T)
	{
		inThreading(T->left);
		if(!T->left)
		{
            //
			T->ltag=thread;
			T->left=pre;
		}
		if(!pre->right)
		{
			pre->rtag=thread;
			pre->right=T;
		}
		pre = T;
		inThreading(T->right);
	}
	return ;
}

void reverseOrderTransverse(Bithrtree* T) { if(T==NULL) return ; reverseOrderTransverse(T->left);
	reverseOrderTransverse(T->right);
	visit(T);
}

void visit(Bithrtree* T)
{
	printf("%c",T->data);
	return ;
}

void inOrderTransverse_Thr(Bithrtree* T)
{
	//Find Head
	Bithrtree* p=T->left;
	while(p!=T)
	{
		while(p->ltag==link) p=p->left;
		visit(p);
		while(p->rtag==thread && p->right!=T)
		{
			p=p->right;
			visit(p);
		}
		p=p->right;
	}
	return ;

}

//Main Body
//
//

int main(void)
{
	char pre[500];
	char in[500];
	Bithrtree* T;
    freopen("test.in","r",stdin);
	scanf("%s",pre);
	scanf("%s",in);
	Bithrtree* threadhead=NULL;
	T=createBithrtree(in,pre);
	//reverseOrderTransverse(T);
	threadhead=InOrderThreading(T);
	//visit(threadhead->left);
	inOrderTransverse_Thr(threadhead);			//Application
	printf("\n");

	return 0;
}
