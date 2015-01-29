/*************************************************************************
    > File Name: balanced_bitree.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月27日 星期六 09时17分15秒
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

typedef enum {OK,ERR} Status;

const int LH=1;
const int RH=-1;
const int EH=0;

//Define the struct
//
//

typedef struct node{
	int bf;
	ElemType data;
	node* left;
	node* right;
}AVLNode;

typedef AVLNode* AVLNodePtr;

//Class Definition
//@author:VOID001
//@Description:
//	  create an Balanced Search tree and
//	  enable user to modify the tree such as insert delete 
//	  and find the elem

class AVLTree{
	private:
		AVLNodePtr avl;	
		void R_Rotate(AVLNodePtr& p);
		void L_Rotate(AVLNodePtr& p);
		void leftBalance(AVLNodePtr& p);
		void rightBalance(AVLNodePtr& p);
		void AVL_free(AVLNodePtr& T);
		//Private sub functions 
		Status pr_Insert(AVLNodePtr& T,const ElemType& elem);
		Status pr_Del(AVLNodePtr& T,const ElemType& elem);
		AVLNodePtr pr_Search(AVLNodePtr& T,const ElemType& key);
		//void AVL_Balance(AVLNodePtr& p,
	public:
		//Status AVL_Insert(const ElemType& elem,const AVLNodePtr& T);
		Status AVL_Insert(const ElemType& elem);
		Status AVL_Del(const ElemType& elem);
		AVLNodePtr AVL_Search(const ElemType& key);
		AVLTree();
		~AVLTree();
				
};

AVLTree::~AVLTree()
{
	AVL_free(avl);	
}

AVLTree::AVLTree():avl(NULL)
{

}

void AVLTree::AVL_free(AVLNodePtr& p)			//Free the whole tree
{
	if(p)
	{
		AVL_free(p->left);
		AVL_free(p->right);
		free(p);
		p=NULL;
	}
	return ;
}

Status AVLTree::AVL_Insert(const ElemType& elem)
{
	return pr_Insert(avl,elem);
}

Status AVLTree::pr_Insert(AVLNodePtr& T,const ElemType& elem,bool taller=false)
{
	if(!T)
	{
		T=(AVLNodePtr)malloc(sizeof(AVLNode));
		T->data=elem;
		T->left=T->right=NULL;
	}
	else
	{
		if(elem==T->data)
		{
			taller=false;
			return ERR;					//The element has already exist in the AVLTree
		}
		if(elem<T->data)
		{
			if(!pr_Insert(T->left,elem,taller)) return ERR;			//Not Inserted
			if(taller)
			{
				switch(T->bf)
				{
					case LH:
						leftBalance(T);
						taller=false;
						break;
					case EH:
						taller=true;					
						T->bf=LH;
						break;
					case RH:
						taller=false;
						T->bf=EH;
						break;
				}
			}
		}
		else 
		{
			if(!pr_Insert(T->right,elem,taller)) return ERR;
			if(taller)
			{
				switch(T->bf)
				{
					case LH:
						taller=false;
						T->bf=EH;
						break;
					case EH:
						taller=true;
						T->bf=RH;
						break;
					case RH:
						rightBalance(T);
						taller=false;
						break;
				}
			}
		}
	}
	return OK;
}

void AVLTree::leftBalance(AVLNodePtr& T)
{
	
}

void AVLTree::rightBalance(AVLNodePtr& T)
{

}

void R_Rotate(AVLNodePtr& T)
{

}

void L_Rotate(AVLNodePtr& T)
{

}

int main()
{
	AVLTree T;
	return 0;
}
