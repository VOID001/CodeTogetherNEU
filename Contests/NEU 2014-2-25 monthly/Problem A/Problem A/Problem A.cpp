#include<stdio.h>
#include<math.h>

const double small = 1e-9;
int main()
{
	double a, b, c, l, m, n, vol;
	double t1, t2, t3, t4, t5;
	while (scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &l, &m, &n) == 6)
	{
		int ok = 1;
		t3 = acos((a*a + b*b - l*l) / (2.0*a*b));
		t1 = acos((c*c + b*b - n*n) / (2.0*b*c));
		t2 = acos((a*a + c*c - m*m) / (2.0*a*c));
		t4 = (t1 + t2 + t3) / 2.0;
		double mid = sin(t4)*sin(t4 - t1)*sin(t4 - t2)*sin(t4 - t3);
		//判断是否是三角形
		if (a + b <= c || a + c <= b || b + c <= a) ok = 0;
		if (a + b <= l || a + l <= b || b + l <= a) ok = 0;
		if (m + b <= c || m + c <= b || b + c <= m) ok = 0;
		if (a + n <= c || a + c <= n || n + c <= a) ok = 0;
		//END
		t5 = sqrt(mid);
		vol = a*b*c*t5 / 3.0;
		if (ok)
			printf("%.2f\n", vol);
		else
			printf("-1.00\n");
	}
	return 0;
}