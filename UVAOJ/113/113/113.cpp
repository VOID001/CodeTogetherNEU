#include<math.h>
#include<cstdio>
#include<string>
using namespace std;
int main(void)
{
	double root, power;
	while (scanf("%lf%lf", &power, &root) == 2)
	{
		printf("%.0lf\n", pow(root, 1 / power));				//难得这么精简的代码 用double就可以了 开n次根就相当于根的 1/n次方 输出注意用.0lf去除小数位
	}
}