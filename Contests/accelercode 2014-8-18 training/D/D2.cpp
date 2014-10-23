#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//int findx(int s[],int l,int r,int index)
//{
//    int i=l,j=r;
//    int x=s[i];
//    while(i<j)
//    {
//        while(i<j&&s[j]>=x)
//            j--;
//        if(i<j) s[i]=s[j];
//        while(i<j&&s[i]<x)
//            i++;
//        if(i<j) s[j]=s[i];
//    }
//    s[i]=x;
//    if(i-l==index) return s[i];
//    else if(i-l<index) return findx(s,i+1,r,index-(i-l)-1);
//    else return findx(s,l,i-1,index);
//}
void sort_insert(int* A,int size,int ele)
{
	if(size!=0)
	{
		int i;
		for( i=size-1;i>=0;i--)
		{
			if(ele<A[i])
			{
				A[i+1]=A[i];
			}
			else
			{
				A[i+1]=ele;
				break;
			}
		}
		if(i<0) A[0]=ele;
	}
	return ;
}
int main()
{
	int T;
	int s[10005];
	int ans[10005];
	scanf("%d",&T);
	while(T--)
	{
		int index,n;
		scanf("%d%d",&index,&n);
		int j=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
			sort_insert(s,i,s[i]);
			if((i+1)%2==1) ans[j++]=s[(i+1)/2];
		}
		printf("%d %d\n",index,(n+1)/2);
		int ii;
		for(ii=0;ii<j;ii++)
		{
			printf("%d",ans[ii]);
			if((ii+1)%10==0 && ii+1!=j) printf("\n");
			else if(ii!=j-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
