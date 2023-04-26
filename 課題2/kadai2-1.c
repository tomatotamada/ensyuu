#include <stdio.h>
#include <math.h>

double area(double x,double y,double z);
double s;
double p;
int main(){
    double x,y,z;
    for( ; ; ){
        scanf("%lf %lf %lf",&x,&y,&z);
        if(isnan(area(x,y,z))){
        printf("三角形を形成できません\n");
        }else if((x==y)&&(y==z)){
            break;
        }else{
            printf("MENSEKI = %f\n",area(x,y,z));

        }
    }
    printf("MENSEKI = %f\n",area(x,y,z));
    
    return 0;
}

double area(double x, double y,double z){
    s=(x+y+z)/2;
    p=s*(s-x)*(s-y)*(s-z);
    return sqrt(p);
}