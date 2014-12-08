/*************************************************************************
    > File Name: K.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月07日 星期日 15时39分39秒
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

typedef struct stu{
	int votenum;
	int candy;
	int friendID;
	int suff;
	int id;
}Stu;

bool cmp_votes(const Stu& a,const Stu& b)
{
	return a.votenum>b.votenum;
}

bool cmp_suff(const Stu& a,const Stu& b)
{
	if(a.suff!=b.suff)
		return a.suff<b.suff;
	return a.votenum>b.votenum;
}

Stu student[101];

int mapIDtoPos(int id)
{
	for(int i=1;i<=100;i++)
	{
		if(student[i].id==id) return i;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int num;
		scanf("%d",&num);
		student[1].suff=1000000;
		for(int i=1;i<=num;i++)
		{
			student[i].id=i;
			student[i].votenum=0;
		}

		for(int i=2;i<=num;i++)
		{
			scanf("%d",&student[i].friendID);
			student[student[i].friendID].votenum++;
		}

		for(int i=2;i<=num;i++)
		{
			scanf("%d",&student[i].candy);
		}
		//Initialize is OK
		int needcandy=0;
		//InitialSort
		sort(student+1,student+num,cmp_votes);
		int maxvote=student[1].votenum;
		int minvote=student[num].votenum;
		while(maxvote!=student[mapIDtoPos(1)].votenum || minvote+1>=maxvote)
		{
			//int cur=1;
			//while(maxvote==student[cur].votenum)
			//{
				//if(student[cur].id==1) {cur++;continue;}
				for(int i=1;i<=num;i++)
				{
					if(student[i].id!=1 && student[i].friendID!=1)
					{
						int curvotenum=student[mapIDtoPos(student[i].friendID)].votenum;
						//if(student[i].friendID==student[cur].id)
						if(curvotenum==maxvote)
						{
							student[i].suff=student[i].candy;
						}
						else
						{
							student[i].suff=student[i].candy*2;
						}
					}
				}
				//cur++;
			//}
			sort(student+1,student+num,cmp_suff);
			int tmpi;
			for(int i=1;i<=num;i++)
			{
				if(student[i].id!=1)
				{
					if(student[i].friendID!=1)
					{
						needcandy+=student[i].candy;
						tmpi=i;
						break;
					}
				}
			}
			student[mapIDtoPos(student[tmpi].friendID)].votenum--;
			student[tmpi].friendID=1;
			student[mapIDtoPos(1)].votenum++;
			sort(student+1,student+num,cmp_votes);
			maxvote=student[1].votenum;
			minvote=student[num].votenum;
			//printf("NOW Stu id %d has maxvotenum %d votes\n",student[1].id,maxvote);
		}
		printf("%d\n",needcandy);
	}
	return 0;
}



