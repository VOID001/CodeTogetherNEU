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
typedef long long LL;
using namespace std;
const int MAX=100000;
int L[MAX];
int R[MAX];
LL deseqnum=0;
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
	int cnt=first;						//the array we should merge is from A[first] to A[end] so we can only modify these value ,we shouldn'tmodify other A values
	//The Problem has fixed
	while(li<=lenL && ri <=lenR)
	{
		int tmp;
		if(L[li]>R[ri])
		{
			tmp=R[ri];
			ri++;
			deseqnum+=lenL-li+1;
		}
		else
		{
			tmp=L[li];
			li++;
		}
		A[cnt++]=tmp;
	}
	if(li<=lenL)
	{
		while(li<=lenL)
		{
			A[cnt++]=L[li++];	
			//deseqnum+=lenR;
		}
		//deseqnum-=lenR;
	}
	while(ri<=lenR)
	{
		A[cnt++]=R[ri++];
	}
	return ;
}


int main(void)
{
	int arr[MAX];
	int n;
	while(	scanf("%d",&n)!=EOF)
	{
		deseqnum=0;
		for(int i=1;i<=n;i++) cin>>arr[i];
		mergesort(arr,1,n);
		//for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
		cout<<deseqnum<<endl;
	}

	return 0;
}
