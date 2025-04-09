#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define theta (M_PI/16)

double func(int n);

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%.3f\n", func(n));
	return 0;
}

double func(int n)
{
    double val;

    if (n <= 1) {
        // n = 0なら1を、n = 1ならcos(theta)を返す
        val = cos(n * theta);
    }
    else {
        // 再帰的にa_{n - 1}, a_{n - 2}を計算する
        double a_n1, a_n2;
        a_n1 = func(n - 1);
        a_n2 = func(n - 2);

        val = 2 * cos(theta) * cos(a_n1) - a_n2 + 0.1 * sin(theta);
    }

    return val;
}
