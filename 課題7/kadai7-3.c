#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cell {
    int data;
    struct cell *next;
} CELL;

CELL head; /* ダミーのセル */

void InsertCell(int x);
void PrintList();
void DeleteCell(int x);
void DeletePositiveCell();
void DeleteNegativeCell();
void DeleteEvenCell();


int main(void){
    int x;
    char comand[2];

    while(1){
        printf("コマンドを入力してください(i,d,p,n,e,s,x)\n");
        scanf("%s",comand);

        if (strcmp(comand,"d") == 0)
        {
            //データ削除
            printf("削除したい数字を入れてください>\n");
            scanf("%d",&x);
            DeleteCell(x);
        }else if(strcmp(comand,"p") == 0){
            //正のデータ削除
            DeletePositiveCell();
        }else if(strcmp(comand,"n") == 0){
            //負のデータ削除
            DeleteNegativeCell();
        }else if(strcmp(comand,"e") == 0){
            //偶数データ削除
            DeleteEvenCell();
        }else if(strcmp(comand,"s") == 0){
            //リスト表示
            PrintList();
        }else if(strcmp(comand,"x") == 0){
            //プログラム終了
            return 0;
        }else if (strcmp(comand,"i") == 0)
        {
            //リスト挿入
            while(1){
            printf("整数を入力してください: ");
            scanf("%d", &x);
            if( x == 0) break;
            InsertCell(x);
            }
        }else{
            printf("コマンドが正しくありません\n");
        }
    }
    
    
}

/* 新しいセルの挿入用関数 */
void InsertCell(int x){ 
    CELL *p, *new;
    new = (CELL *)malloc(sizeof(CELL));
    new->data = x;
    for(p = &head ; p->next != NULL ; p = p->next) {
        if(new->data < (p->next)->data) {
            new->next = p->next;
            p->next = new;
            return;
        }
    // xがすでにリストにあるときは、何もしないで終了
        else if(new->data == (p->next)->data)
        return;
    }
    new->next = NULL;
    p->next = new;
}

/* 画面表示用関数 */
void PrintList(){ 
    CELL *p;
    for(p = &head ; p->next != NULL ; p = p->next)
        printf("%d ", (p->next)->data);
        printf("\n");
    
}

//任意のセルの削除
void DeleteCell(int x){
    CELL *p;
    p = &head;
    while((p->next)->data != x){
        p = p->next;
        if(p->next == NULL){
            printf("そのような数字のセルはありません\n");
            return;
        }
    }
    p->next = p->next->next;
    printf("削除完了\n");
    return;
}

//正の数のセルの削除
void DeletePositiveCell(){
    CELL *p;
    p = &head;
    while(p->next != NULL){
        if(p->next->data > 0){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    printf("削除完了\n");
    return;
}

//負の数のセルの削除
void DeleteNegativeCell(){
    CELL *p;
    p = &head;
    while(p->next != NULL){
        if(p->next->data < 0){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    printf("削除完了\n");
    return;
}


//偶数のセルの削除
void DeleteEvenCell(){
    CELL *p;
    p = &head;
    while(p->next != NULL){
        if(p->next->data % 2 == 0){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    printf("削除完了\n");
    return;
}