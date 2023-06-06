#include<stdio.h>
#include<math.h>
#include<stdlib.h>


typedef struct{
    double x;
    double y;
}point;

double nomal (double a,double b);
double rn(double a,double b,int n);
int GetRandom(double min, double max);

int main(void){
    int n,i;
    double a,b;

    printf("積分区間の下限値aを入力して下さい >\n");
    scanf("%lf",&a);
    printf("積分区間の上限値bを入力して下さい >\n");
    scanf("%lf",&b);
    printf("乱数を発生する回数を入力して下さい(1000万回以下) >\n");
    scanf("%d",&n);

    rn(a,b,n);

    printf("--- 計算結果 ---\n");
    printf("積分値(理論値) = %lf\n",nomal(a,b));
    printf("積分値(シミュレーション値) = %lf\n",rn(a,b,n));
    printf("積分値の誤差 = %lf\n",(rn(a,b,n)) - (nomal(a,b)));


}


double nomal (double a,double b){
    return ((b*b*b) - (a*a*a)) / 3;
}

double rn (double a,double b,int n){
    double x,y,AllArea,percent;
    int i,count = 0;
    point p[n];

    x = b - a;
    if(a*a > b* b){
        y = a*a;
    }else{
        y = b*b;
    }

    AllArea = x * y;

    for ( i = 0; i < n; i++)
    {
        p[i].x = GetRandom(a,b);
        p[i].y = GetRandom(0,y);

        if(p[i].y < (p[i].x) * (p[i].x)){
            count++;
        }
    }

    //percent = (count / n);

    // for ( i = 0; i < n; i++)
    // {
    //     printf("%lf %lf\n",p[i].x * p[i].x,p[i].y);
    // }
    // printf("%d %lf\n",count,count /n);

    return AllArea * count / n;

}

int GetRandom(double min, double max)
{
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
