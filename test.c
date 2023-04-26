/*
 * C言語のサンプルプログラム - Webkaru
 * - 入力した2つの整数を足し算・引き算 -
 */
#include <stdio.h>
 
int main(void)
{

  int a, b;

  /* 2つ整数を入力 */
  printf("1つ目の整数: a = ");
  scanf("%d", &a);
  printf("2つ目の整数: b = ");
  scanf("%d", &b);

  /* 足し算の計算・出力 */
  printf("a + b = %d\n", a+b);

  /* 引き算の計算・出力 */
  printf("a - b = %d\n", a-b);

  return 0;
}