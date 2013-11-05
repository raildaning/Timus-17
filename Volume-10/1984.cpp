#include <cstdio>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#include <math.h>
#undef _USE_MATH_DEFINES
#endif

using namespace std;

int main() {
	int n;
	double x;
	scanf("%d", &n);
	if(n == 1)	x = 1.0;
	else if(n == 2) x = 2.0;
	else {
		double alpha = M_PI / 2.0 - (M_PI / n);
		x = 1 + 1 / cos(alpha);
	}
	printf("%.9lf\n", x);
	return 0;
}
