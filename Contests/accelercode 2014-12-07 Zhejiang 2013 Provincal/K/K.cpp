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
	if(a.votenum!=b.votenum)
		return a.votenum>b.votenum;
	return a.id>b.id;
}

bool cmp_suff(const Stu& a,const Stu& b)
{
	if(a.suff!=b.suff)
		return a.suff<b.suff;
	return a.votenum>b.votenum;
}

void showInfo(int num,int maxvotenum);

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
		//DEBUG
		//printf("------------------------TEST CASE---------------------\n");	
		//END DEBUG
		int num;
		int maxvote;
		int minvote;
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
		maxvote=student[1].votenum;
		minvote=student[num].votenum;
		//while(maxvote!=student[mapIDtoPos(1)].votenum || minvote+1>=maxvote)
		while(student[1].id!=1 || minvote+1>=maxvote)
		{
			//showInfo(num,maxvote);
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
			//Give one certain student candy
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

			//DEBUG
		//	printf("###I give %d candies to Student No %d and he won't vote for Student No %d anymore\n",student[tmpi].candy,student[tmpi].id,student[mapIDtoPos(student[tmpi].friendID)].id);
			//END OF DEBUG
			student[mapIDtoPos(student[tmpi].friendID)].votenum--;
			student[tmpi].friendID=1;
			student[mapIDtoPos(1)].votenum++;
			sort(student+1,student+num,cmp_votes);
			maxvote=student[1].votenum;
			minvote=student[num].votenum;
		}
		//printf("ULTIMATE RESULT\n");
		//showInfo(num,maxvote);
		printf("%d\n",needcandy);
		//DEBUG
		//printf("------------------------END CASE---------------------\n");	
		//END DEBUG
	}
	return 0;
}


void showInfo(int num,int maxvotenum)
{
	printf("The vote result Now is:\n\n");
	printf("ID\t\t\tVOTES\n");
	for(int i=1;i<=num;i++)
	{
		if(student[mapIDtoPos(i)].votenum==maxvotenum) printf("*");
		printf("%d\t\t\t%d\n",i,student[mapIDtoPos(i)].votenum);
	}
}


