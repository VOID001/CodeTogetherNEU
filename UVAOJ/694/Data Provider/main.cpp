#include<stdio.h>
#include<stdlib.h> /**srand() rand() included**/
#include<time.h> /**time() included**/

int n=2147483645,m=10000;

double random();
int random(int m);

int main()
{
    freopen("input.txt","w",stdout);
    srand(time(NULL));
    //printf("%d %d\n",n,m);
    for(int i=0;i<1000;i++)
    {
        //if(rand()%2==0) printf("A"); else printf("B");
        int X,Y;
        for(;;)
        {
            X=random(n)+1;
            Y=random(n)+1;
            if(X<Y) break;
        }
        printf(" %d %d\n",X,Y);
    }
    return 0;
}

double random()
{
    return (double)rand()/RAND_MAX;
}

int random(int m)
{
    return (int)(random()*(m-1)+0.5);
}
