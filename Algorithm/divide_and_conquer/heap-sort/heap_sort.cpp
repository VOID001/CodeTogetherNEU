/*************************************************************************
    > File Name: heap_sort.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月09日 星期六 09时39分19秒
 ************************************************************************/
#define LEFT(a) (a)<<1
#define RIGHT(a) (((a)<<1)+1)
#define PARENT(a) (a)>>1
#include<iostream>
#include<cstdio>
using namespace std;
void swap(int& a,int& b);

void maxHeapify(int* A,int i,int heapsize)
{
	int l=LEFT(i);
	int r=RIGHT(i);
	int large;
	if(l<=heapsize && A[l] > A[i])
	{
		large=l;
	}
	else large=i;
	if(r<=heapsize && A[r]> A[large])
	{
		large=r;
	}
	if(large!=i)
	{
		swap(A[i],A[large]);
		maxHeapify(A,large,heapsize);
	}
}

void buildHeap(int* A,int length)
{
	for(int i=length/2;i>=1;i--)
	{
		maxHeapify(A,i,length);
	}
	return ;
}


void heapSort(int* A,int length)
{
	buildHeap(A,length);
	while(length>=2)
	{
		swap(A[1],A[length]);
		maxHeapify(A,1,--length);			//Be sure the Heapsize isreduced by one
	}
	return ;
}

void swap(int& a,int& b)
{
	int tmp=a;
	a=b;
	b=tmp;
	return ;
}

int main(void)
{
	int n;
	int heaparr[1000000];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&heaparr[i]);
		heapSort(heaparr,n);
		for(int i=1;i<=n;i++) 
			printf(" %d",heaparr[i]);
		printf("\n");
	}
	return 0;
}
