#include <stdio.h>
#include <math.h>

struct point{
    int x; /* x座標 */
    int y; /* y座標 */
};

double distance(struct point p1);

int main(void){
    struct point p1;
    printf("> (x, y) ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Distance between (%d, %d) and (0, 0) is %f \n", p1.x, p1.y, distance(p1));
    return 0;
}

double distance(struct point  p1){
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}
