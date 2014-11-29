/*************************************************************************
    > File Name: bitree-1.cpp
    > Author: VOID_133
    > ###################
    > Mail: ###################
    > Created Time: 2014年10月28日 星期二 12时40分57秒
	> A Demo for BiTree First Create a Tree(Constant) Then Transverse it
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

#define MALLOC (Node*)malloc(sizeof(Node))
using namespace std;


typedef struct Node{
	struct Node* left=NULL;
	struct Node* right=NULL;
	int data=0;
}Node;

typedef Node* BiTree;				//Declare the BiTree
void goFarLeft(BiTree T,stack<Node*>& nodeStack);

BiTree createTree()
{
	BiTree T=NULL;
	Node* father=(Node*)malloc(sizeof(Node));
	T=father;
	father->data=1;
	father->right=MALLOC;
	father->left=MALLOC;
	Node* rchild1,*lchild1;
	rchild1=father->right;
	lchild1=father->left;
	rchild1->data=3;
	lchild1->data=2;
	rchild1->left=NULL;
	rchild1->right=MALLOC;
	rchild1->right->data=4;
	lchild1->right=MALLOC;
	lchild1->right->data=9;
	lchild1->left=MALLOC;
	lchild1->left->data=7;
	lchild1->right->left=MALLOC;
	lchild1->right->left->data=0;

	return T;
}


void visit(int a)
{
	printf("%d",a);
	return ;
}

void preOrderTransverse(BiTree T)
{
	if(T==NULL) return;
	visit(T->data);
	preOrderTransverse(T->left);
	preOrderTransverse(T->right);
}

void midOrderTransverse(BiTree T)
{
	if(T==NULL) return;
	midOrderTransverse(T->left);
	visit(T->data);
	midOrderTransverse(T->right);
}

void postOrderTransverse(BiTree T)
{
	if(T==NULL) return;
	postOrderTransverse(T->left);
	postOrderTransverse(T->right);
	visit(T->data);
}

void preOrderTransverse_non_recursion(BiTree T)
{
	stack<Node*> nodeStack;
	goFarLeft(T,nodeStack);
	while(T && !nodeStack.empty())
	{
        Node* t=nodeStack.top();
        nodeStack.pop();
        goFarLeft(t,nodeStack);
	}
	return ;
}

void goFarLeft(BiTree T,stack<Node*>& nodeStack)
{
    while(T!=NULL)
    {
        visit(T->data);
        if(T->right)
        {
            nodeStack.push(T->right);
        }
        T=T->left;
    }
    return ;
}


int main(void)
{
	BiTree T=createTree();
	preOrderTransverse(T);
	printf("\n");
	preOrderTransverse_non_recursion(T);
//	midOrderTransverse(T);
//	printf("\n");
//	postOrderTransverse(T);
//	printf("\n");
}
