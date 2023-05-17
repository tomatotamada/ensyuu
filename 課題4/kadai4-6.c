#include <stdio.h>
int main(void){
    int x = 77, y = 115;
    int tmp;
    int *p;

    printf("HENSU  ADDRESS  VALUE\n");
    printf("x  %p  %d\n", &x, x);
    printf("y  %p  %d\n", &y, y);

    tmp = y;
    p = &x;

    printf(" exchange x and y\n");
    printf("x  %p  %d\n", p,tmp);

    tmp = x;
    p = &y;

    printf("y  %p   %d\n", p,tmp);

    return 0;
    }
