#include <stdio.h>

void psquare (int *x){
    printf(“Kari-Hikisu x ¥t %p ¥t %p¥n”, &x, x);
    *x = (*x)*(*x);
    }

int main(void){
    int b, x;
    printf(“INPUT AN INTEGER ”);
    scanf(“%d”, &x);
    b = x;
    printf(“ ¥t ADDRESS ¥t VALUE¥n”);
    printf(“Jitsu-Hikisu x ¥t %p ¥t %d¥n”, &x, x);
    psquare(&x);
    printf(“SQUARE of %d IS %d．¥n”, b, x);
    return 0;
    } 