/*************************************************************************
    > File Name: mergesort.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月06日 星期三 14时17分16秒
	> Content : Divide and Conquer Classic Problem 
					MergeSort
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=1000000;
int L[MAX];
int R[MAX];
void mergesort(int* A,int first,int end);
void merge(int *A,int first,int mid,int end);
void mergesort(int* A,int first,int end)
{
	if(first<end)
	{
		int mid=(first+end)/2;		
		mergesort(A,first,mid);			 
		mergesort(A,mid+1,end);	//Solve the problem recursively
		merge(A,first,mid,end);
	}
	return ;
}

void merge(int *A,int first,int mid,int end)
{
	int lenL=mid-first+1;
	int lenR=end-mid;
	for(int i=1;i<=lenL;i++) L[i]=A[first+i-1];
	for(int i=1;i<=lenR;i++) R[i]=A[mid+i];
	int li=1;
	int ri=1;
	int cnt=1;
	//the code below has fatal error
	while(li<=lenL && ri <=lenR)
	{
		int tmp;
		if(L[li]>R[ri])
		{
			tmp=R[ri];
			ri++;
		}
		else
		{
			tmp=L[li];
			li++;
		}
		A[cnt++]=tmp;
	}
	while(li<=lenL)
	{
		A[cnt++]=L[li++];	
	}
	while(ri<=lenR)
	{
		A[cnt++]=R[ri++];
	}
	return ;
}


int main(void)
{
	int arr[1000];
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;i++) cin>>arr[i];
		mergesort(arr,1,n);
		for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	}
	return 0;
}
