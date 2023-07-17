#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{                      /* 構造体 cell の定義 */
    int element;       /* メンバelement はスタックに格納されるデータ */
    struct cell *next; /* メンバnext は次のcellを指すポインタ */
} CELL;                /* CELL型の定義 */

void *push(int x, CELL *init)
{                                     /* push関数の定義 (教科書図 2.7 と同様) 注(1)(2) */
    CELL *q, *r;                      /* CELL型のポインタ変数 *q, *r の宣言 */
    r = (CELL *)malloc(sizeof(CELL)); /* pushするための新しいポインタ*rの獲得 */
    q = init;                         /* init が指しているセル(スタックの先頭)を*q に代入 */
    init = r;                         /* その時点でinit が指すセルを*r に変更 */
    r->element = x;
    r->next = q;   /* rのメンバelement にx を格納 * r->next=q; /* rのメンバnext にq を代入 */
    return (init); /* push後の init(先頭のセルを指すポインタ変数)を戻す */
}

void *pop(CELL *init)
{            /* pop 関数の定義 (教科書図 2.7 と同様) 注(1)(2) */
    CELL *q; /* CELL型のポインタ変数 *q の宣言 */
    if (init != NULL)
    {                      /* init==NULL(すなわち空状態)でなければ{ }内を実行 */
        q = init;          /* init が指しているセル(スタックの先頭)を*q に代入 */
        init = init->next; /* init の次のセル(先頭から2 番目のセル)をinit に変更 */
        free(q);           /* *q が指していたセルがpop されたので，メモリ解放 */
        return (init);     /* pop 後のinit(先頭のセルを指すポインタ変数)を戻す */
    }
    else
    {                                   /* init==NULL(すなわち空状態)であれば{ }内を実行 */
        printf("スタックは空です．\n"); /* スタックは空ですと画面表示して改行 */
        exit(1);                        /* 終了 */
    }
}
void printstack(CELL *init)
{                              /* pointstack()関数の定義 注(1)(2) */
    CELL *p;                   /* CELL型のポインタ変数 *p の宣言 */
    p = init;                  /* init が指しているセル(スタックの先頭)を*p に代入 */
    printf("\t");              /* 例題 8-2 と同じ */
    printf("スタックの中 [ "); /* 例題 8-2 と同じ */
    while (p != NULL)
    {                             /* p=NULL(すなわちスタックの末尾)でなければ{ }内を実行 */
        printf("%d", p->element); /* CELL型ポインタ変数 p のメンバelment の値を画面に表示 */
        printf(" ");              /* 例題 8-2 と同じ */
        p = p->next;              /* p のメンバnext(pが次に指しているセル)をp に変更 */
    }
    printf("]\n");
    fflush(stdout); /* p=NULL(スタックの末尾)であれば "]"を画面に表示 */
}

void printstackadd(CELL *init)
{                              /* pointstack()関数の定義 注(1)(2) */
    CELL *p;                   /* CELL型のポインタ変数 *p の宣言 */
    p = init;                  /* init が指しているセル(スタックの先頭)を*p に代入 */
    printf("\t");              /* 例題 8-2 と同じ */
    printf("スタックの中 [ "); /* 例題 8-2 と同じ */
    while (p != NULL)
    {                    /* p=NULL(すなわちスタックの末尾)でなければ{ }内を実行 */
        printf("%p", &p); /* CELL型ポインタ変数 p のメンバelment の値を画面に表示 */
        printf(" ");     /* 例題 8-2 と同じ */
        p = p->next;     /* p のメンバnext(pが次に指しているセル)をp に変更 */
    }
    printf("]\n");
    fflush(stdout); /* p=NULL(スタックの末尾)であれば "]"を画面に表示 */
}

int main(void)
{
    CELL *init; /* CELL型のポインタ変数 *init の宣言 */
    CELL *q;    /* CELL型のポインタ変数 *r の宣言 */
    int i;      /* int 型変数 i の宣言 */
    int x, y;   /* int 型変数 x の宣言 */

    init = NULL; /* CELL型ポインタ変数 init の初期化(init=NULL で空状態) */

    while (1)
    {
        printf("番号を入力して下さい (1) PUSH, (2) POP, (3) SHOW(data), (4) SHOW(add), (5) EXIT >");
        scanf("%d", &y);

        if (y == 1)
        {
            printf("プッシュする整数を入力して下さい：");
            scanf("%d", &x);
            init = push(x, init);
        }
        else if (y == 2)
        {
            if (init == NULL)
            {
                printf("スタックは空のためポップできません．\n");
            }
            else
            {
                printf("ポップします．\n");
                init = pop(init);
            }
        }
        else if (y == 3)
        {
            printstack(init);
        }
        else if (y == 4)
        {
            printstackadd(init);
        }
        else if (y == 5)
        {
            printf("終了します．");
            break;
        }else{
            printf("1 から 5 までの番号を入力して下さい．");
        }
    }
    return 0;
}