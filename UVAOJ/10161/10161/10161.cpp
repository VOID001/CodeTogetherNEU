#include<stdio.h>
#include<math.h>

int main(void)
{
	int n;
	while (scanf("%d", &n) && n!=0)
	{
		int l = ceil((sqrt(1.0*n)));			//l指的是这个数所处的层数
		int lmid= l*l-(l-1);							//lmax是这个层的中间那个数
		int dis = n - lmid;
		//分情况讨论
		if (l % 2==0 && dis >= 0) printf("%d %d", l, l - dis);
		else if (l % 2==0 && dis < 0) printf("%d %d", l + dis, l);
		else if (l % 2 && dis>=0) printf("%d %d", l - dis, l);
		else if (l % 2 && dis < 0) printf("%d %d", l, l + dis);
		printf("\n");
	}
	return 0;
}