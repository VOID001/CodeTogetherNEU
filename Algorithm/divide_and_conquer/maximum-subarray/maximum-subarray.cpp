/*************************************************************************
    > File Name: maximum-subarray.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年08月07日 星期四 14时29分38秒
	> Content: Find the maximum sub array(Continious) in the array
				Using Divide and Conquer
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
const int MAXN=1000000;
using namespace std;

typedef long long LL;

class CData{
	public:
		int first;
		int end;
		LL maxsum;
		CData(int a=0,int b=0,LL c=0):first(a),end(b),maxsum(c){}
};

typedef CData dat;
LL max(LL a,LL b)
{
	return a>b?a:b;
}

dat maximumCrossSubarray(LL* A,int first,int mid,int end);

dat maximumSubarray(LL* A,int first,int end)
{
	if(first==end)
		return dat(first,end,A[first]);
	int mid = (first+end)/2;
	dat left=maximumSubarray(A,first,mid);
	dat right=maximumSubarray(A,mid+1,end);
	dat cross=maximumCrossSubarray(A,first,mid,end);
	LL maxn=max(left.maxsum,max(right.maxsum,cross.maxsum));
	if(maxn==left.maxsum) return left;
	if(maxn==right.maxsum) return right;
	if(maxn==cross.maxsum) return cross;
}

dat maximumCrossSubarray(LL* A,int first,int mid,int end)
{
	LL sum=0;
	LL maxs=A[mid];
	dat tmp;
	tmp.first=mid;				//如果不加这两句 程序返回的下标是错误的
	tmp.end=mid;
	int i;												//I think the fault maybe is in the judge-max sub 
	for(i=mid;i>=first;i--)
	{
		sum+=A[i];
		//if(sum<maxs) break;						这不是乱写么 。。。。sum暂时小于maxs当然可以啦，竟然被我给跳出去不往后看了，，好坑
		if(sum>maxs)
		{
			tmp.first=i;
			maxs=sum;
		}
	}
	tmp.maxsum+=maxs;
	sum=0;
	maxs=A[mid+1];
	for(i=mid+1;i<=end;i++)
	{
		sum+=A[i];
		if(sum>maxs)
		{
			tmp.end=i;
			maxs=sum;
		}
	}
	tmp.maxsum+=maxs;
	return tmp;
}

int main(void)
{
	dat testdata;
	int N;
	LL arr[MAXN];
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=1;i<=N;i++) cin>>arr[i];
		testdata=maximumSubarray(arr,1,N);
		printf("The maximum Sub array is from arr[%d] to arr[%d] sum is %lld\n",testdata.first,testdata.end,testdata.maxsum);
	}
	return 0;
}


//代码如果不加那两句话输出的下标有问题 这是为什么。。
