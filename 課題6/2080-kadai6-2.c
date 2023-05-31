#include<stdio.h>
#include<math.h>


typedef struct{
    double x;
    double y;
}point;

double henkan(double *dt);
point rotatePoint(point  *p1,double dt);


int main (void){
    point p1;
    double dt;
    printf("> (x1, y1) \n");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("> (dt) \n");
    while(scanf("%lf",&dt) != EOF){
        henkan(&dt);
        rotatePoint(&p1,dt);
        printf("(%lf, %lf).\n",p1.x,p1.y);
        printf("> (dt) \n");
    }
}

point rotatePoint(point  *p1,double dt){
    double x,y;
    x = p1->x;
    y = p1->y;
    p1->x = x * cos(dt) - y * sin(dt);
    p1->y = x * sin(dt) + y * cos(dt);
}

double henkan(double *dt){
    *dt = (*dt) * M_PI / 180;
}