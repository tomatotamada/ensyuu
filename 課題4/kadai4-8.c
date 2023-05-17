#include <stdio.h>

void pinc(int *x,int d){
    printf("Kari-Hikisu x  %p  %p\n", &x, x);
    *x = (*x)+(d);
    }

int main(void){
    int b, x,d;
    printf("INPUT AN INTEGER \n");
    scanf("%d %d", &x,&d);
    b = x;
    printf("2つの数字を入力してください\n");
    printf("Jitsu-Hikisu x  %p  %d\n", &x, x);
    pinc(&x,d);
    printf("%d + %d = %d．\n", b,d,x);
    return 0;
    } 