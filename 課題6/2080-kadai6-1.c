#include<stdio.h>

typedef struct{
    int x;
    int y;
}point;

point getMiddlePoint(point  p1,point p2);

int main (void){
    point p1 , p2 ,p3;
    printf("> (x1, y1) \n");
    scanf("%d %d", &p1.x, &p1.y);
    printf("> (x2, y2) \n");
    scanf("%d %d", &p2.x, &p2.y);
    p3 = getMiddlePoint(p1,p2);
    printf("Midpoint between (%d, %d) and (%d, %d) is (%d, %d).",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
}

point getMiddlePoint(point  p1,point p2){
    point p3;

    p3.x = (p1.x + p2.x) / 2;
    p3.y = (p1.y + p2.y) / 2;

    return p3;
}