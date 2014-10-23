#include<stdio.h>
#define MAX 100009


int main(void)
{
    int M;
    int op;
    int element;
    int which[10000];//cases
    int count=0;//counter
    while(scanf("%d",&M)!=EOF)
    {

        count++;
        //Initialize
        int queue[MAX]={0};
        int stack[MAX]={0};
        int *front=queue;
        int *end=queue;
        int *top=stack;
        for(int oo=1;oo<=M;oo++)
        {
            scanf("%d%d",&op,&element);
            if(op==1)//Add in
            {
                *end=element;
                *top=element;
                end++;
                top++;
            }
            //printf("Queue :%d Stack :%d\n",*front,*(top-1));
            if(op==2)//POP out
            {
                if(*front==element && *(top-1)!=element)//It's a Queue
                {
                    front++;
                    which[count]=1;
                    continue;
                }
                else if(*front!=element && *(top-1)==element)//It's a Stack
                {
                    top--;
                    which[count]=2;
                    continue;
                }
                else if(*front==element && *(top-1)==element)
                {
                    front++;
                    top--;
                    if(which[count]!=1 && which[count]!=2 )which[count]=0;
                    continue;
                }
                else if(which[count]!=1 && which[count]!=2) which[count]=0;
            }
        }
    }
    for(int i=1;i<=count;i++)
    {
        //printf("%d %d\n",i,which[i]);
        if(which[i]==0) {printf("Not Sure"); if(i<count) printf("\n");}
        else if(which[i]==1) {printf("Queue"); if(i<count) printf("\n");}
        else if(which[i]==2) {printf("Stack"); if(i<count) printf("\n");}
    }
}
