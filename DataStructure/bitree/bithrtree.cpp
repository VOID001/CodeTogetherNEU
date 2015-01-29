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

//typedef struct Data{
//	ElemType data;	
//	int key;
//}Data;

typedef struct bithrtree{
	bithrtree* left;
	bithrtree* right;
	bithrtree* father;
	ElemType data;
	int ltag;
	int rtag;
}BithrTree;

//Function Prototype
//
//
void visit(BithrTree* T);
Status createBithrtree(BithrTree* T,char* inOrderStr,char* preOrderStr);
void preOrderTransverse(BithrTree* T);

BithrTree* createBithrtree(BithrTree* T,char* inOrderStr,char* preOrderStr)
{
	if(!strcmp(inOrderStr,"")||!strcmp(preOrderStr,"")) return OK;
	T=(BithrTree*)malloc(sizeof(BithrTree));
	T->data=preOrderStr[0];		
	T->right=NULL;
	T->left=NULL;
	int len=strlen(inOrderStr);
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
	int cutlen=pos;
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
	createBithrtree(T->left,inOrder,preOrder);
	for(i=0;i<len-pos;i++)
	{
		inOrder[i]=inOrderStr[pos+i+1];
	}
	for(i=0;i<len-pos;i++)
	{
		preOrder[i]=preOrderStr[len-pos-1+i];
	}
	createBithrtree(T->right,inOrder,preOrder);
	return OK;
}



void preOrderTransverse(BithrTree* T)
{
	if(T==NULL) return ;
	visit(T);
	preOrderTransverse(T->left);	
	preOrderTransverse(T->right);	
}

void visit(BithrTree* T)
{
	printf("%c",T->data);
	return ;
}

int main(void)
{
	char pre[500];
	char in[500];
	BithrTree* T;

	scanf("%s",pre);
	scanf("%s",in);

	createBithrtree(T,in,pre);
	preOrderTransverse(T);
	return 0;
}
