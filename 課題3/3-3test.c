#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // 乱数の範囲

int rn(void); // 線形合同法による乱数生成関数

int main(void) {
    int n; // 乱数の発生回数
    int count[N] = {0}; // 各乱数の発生回数
    double ratio[N] = {0.0}; // 各乱数の発生割合

    printf("乱数の発生回数を入力してください: ");
    scanf("%d", &n);

    // 乱数の発生とカウント
    for (int i = 0; i < n; i++) {
        int r = rn() % N + 1; // 1~10 の乱数を生成
        count[r-1]++; // 対応する要素のカウントを増やす
    }

    // 発生回数と割合の表示
    printf("乱数\t発生回数\t発生割合\n");
    for (int i = 0; i < N; i++) {
        ratio[i] = (double)count[i] / n * 100.0;
        printf("%2d\t%8d\t%6.2f%%\n", i+1, count[i], ratio[i]);
    }

    return 0;
}

// 線形合同法による乱数生成関数
int rn(void) {
    static unsigned int x = 123456789;
    static unsigned int y = 362436069;
    static unsigned int z = 521288629;
    static unsigned int w = 88675123;
    unsigned int t;

    t = x ^ (x << 11);
    x = y; y = z; z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));

    return w;
}