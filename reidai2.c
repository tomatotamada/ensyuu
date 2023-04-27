#include <stdio.h>

int area(int x,int y);
int main(){
    int x,y;
    x=3;
    y=6;
    printf("MENSEKI = %d\n",area(x,y));
    return 0;
}

int area(int x, int y){
    return x*y;
}