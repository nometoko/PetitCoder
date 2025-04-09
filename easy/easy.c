#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n = 0;
    double theta = M_PI / 16;
    // 入力 nを受け取る
    scanf("%d", &n);

    // 初項からn項目までの値を格納する配列を動的に確保
    double *a = (double *)calloc(n + 1, sizeof(double));

    // 初期化
    a[0] = 1;
    a[1] = cos(theta);

    // ループ文による計算 i = 2から始めることに注意
    for (int i = 2; i <= n; i++)
    {
        a[i] = 2 * cos(theta) * a[i - 1] - a[i - 2];
    }

    printf("%.3f\n", a[n]);
    free(a);
    return 0;
}

