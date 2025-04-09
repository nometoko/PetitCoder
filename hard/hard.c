#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define theta (M_PI/16)

double func(int n, double* a);

int main(void)
{
	int n;
	scanf("%d", &n);

    // 計算結果を保存する配列を動的に確保
    double *a = (double*)calloc(n + 1, sizeof(double));

    // 初期化
    for (int i = 0; i <= n; i++) {
        a[n] = INFINITY;
    }

    // 初期状態
    a[0] = 1;
    a[1] = cos(theta);

	printf("%.3f\n", func(n, a));
    free(a);

	return 0;
}

double func(int n, double *a) {
    double val;

    if (a[n] != INFINITY) {
        // n項目が初期化した値でない、つまり既に計算済みならその値を返す
        val = a[n];
    }
    else {
        // そうでないなら、n項目を計算する。
        val = 2 * cos(theta) * cos(func(n - 1, a)) - func(n - 2, a) + 0.1 * sin(theta);
        // 計算結果を配列に保存する
        a[n] = val;
    }

    return val;
}
