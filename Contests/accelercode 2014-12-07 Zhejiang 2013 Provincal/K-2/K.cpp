/*************************************************************************
    > File Name: K.cpp
    > Author: VOID_133
    > ################### 
    > Mail: ################### 
    > Created Time: 2014年12月18日 星期四 10时50分08秒
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

typedef struct stu
{
	int votenum;
	int friendid;
	int ID;
	int candyneed;
	bool used;
}Stu;

bool cmp_candy(const Stu& a,const Stu& b)
{
	//if(a.candyneed!=b.candyneed)
	return a.candyneed<b.candyneed;
}

Stu student[110];
Stu tmp[110];

inline int mapID(int ID)
{
	for(int i=1;i<=100;i++) if(student[i].ID==ID) return i;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;	
		//int maxvote=0;
		scanf("%d",&N);

		memset(student,0,sizeof(student));
		for(int i=1;i<=N;i++)
		{
			student[i].ID=i;
			student[i].used=false;
		}
		for(int i=2;i<=N;i++)
		{
			scanf("%d",&student[i].friendid);
			student[student[i].friendid].votenum++;
		}
		for(int i=2;i<=N;i++)
		{
			scanf("%d",&student[i].candyneed);
		}

		//Init Complete
		int needvote=student[1].votenum;
		int mincandy=900000;
		//Enumeration	
		while(needvote<=N-1)
		{
		for(int i=1;i<=N;i++)
		{
			student[i].used=false;
		}
			int needtoget=needvote-student[1].votenum;
			int toget=0;								//how many votes I must get
			bool fail=false;
			int sumcandy=0;
			for(int i=2;i<=N && !fail;i++)
			{
				if(student[i].votenum>=needvote)
				{
					toget+=student[i].votenum-needvote+1;
					if(toget>needtoget) 
					{
						fail=true;
					}
				}
			}
			//Greedy
			if(!fail)
			{
				for(int i=2;i<=N;i++)
				{
					if(student[i].votenum>=needvote)
					{
						int getnum=student[i].votenum-needvote+1;
						int cur=0;
						//Find out and put all the students vote for ID=i to tmp Array
						for(int j=2;j<=N;j++)	
						{
							if(student[j].friendid==i)
							{
								tmp[cur++]=student[j];
							}
						}
						sort(tmp,tmp+cur,cmp_candy);
						for(int j=0;j<getnum;j++)
						{
							sumcandy+=tmp[j].candyneed;
							student[mapID(tmp[j].ID)].used=true;
						}
					}
				}
				int cur=0;
				for(int i=2;i<=N;i++)
					if(!student[i].used && student[i].friendid!=1) tmp[cur++]=student[i];
				if(cur)
				{
					sort(tmp,tmp+cur,cmp_candy);
					for(int i=0;i<needtoget-toget;i++)
						sumcandy+=tmp[i].candyneed;
				}
				if(sumcandy<mincandy) mincandy=sumcandy;
			}
			needvote++;
		}
		printf("%d\n",mincandy);
	}	
	return 0;
}
