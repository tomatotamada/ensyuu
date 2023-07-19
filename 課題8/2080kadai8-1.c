#include <stdio.h>
#define STACK_SIZE 10 /* スタック(配列)に格納するデータの最大個数 */

int array[STACK_SIZE]; /* データ格納用の配列 */
int stack_ptr = 0;     /* スタックポインタの初期化 */
/* このプログラムではスタックポインタを */
/* 格納されているデータ個数としている */

void push(int x)
{                         /* push関数の定義 */
    array[stack_ptr] = x; /* x を配列 array[stack_ptr] に格納 */
    stack_ptr++;          /* スタックポインタを1 増やす */
}

int pop(void)
{                                 /* pop 関数の定義 */
    int x = array[stack_ptr - 1]; /* 整数型変数 x の宣言と配列 array[stack_ptr-1] の値の代入 */
    stack_ptr = stack_ptr - 1;    /* スタックポインタを1 減らす */
    return x;                     /* 変数 x を返す */
}

int main(void)
{
    int i, x, y; /* pop, pushを繰り返すカウンタi, pushする整数 x の宣言 */

    while (1)
    {
        printf("番号を入力して下さい (1) PUSH, (2) POP, (3) SHOW (4) EXIT >");
        scanf("%d", &y);

        if (y == 1)
        {
            if (stack_ptr == 10)
            {
                printf("スタックはフルのためプッシュできません．");
            }
            else
            {
                printf("pushする整数を入力して下さい > "); /* 画面表示と改行 */
                scanf("%d", &x);                           /* キーボードからx の入力 */
                push(x);                                   /* push関数の呼び出し(データx を格納) */
            }
        }
        else if (y == 2)
        {
            if (stack_ptr == 0)
            {
                printf("スタックは空のためポップできません．\n");
            }
            else
            {
                printf("ポップします．\n");
                pop();
            }
        }
        else if (y == 3)
        {
            for (i = 1; i < stack_ptr + 1; i++)
            {
                printf("スタック %d つ目は %d ．\n", i, array[i - 1]);
            }
        }
        else if (y == 4)
        {
            printf("終了します.");
            break;
        }
        else
        {
            printf("1 から 4 までの番号を入力して下さい．");
        }
    }

    return 0;
}