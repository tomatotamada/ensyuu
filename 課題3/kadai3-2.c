#include <stdio.h>

int rn(int x);
double count[9];
double star[9];

int main(){
    double x,n,max,p;
    int c,i;
    printf("乱数の発生回数を入力してください\n");
    scanf("%d",&n);
    x = 1;
    for(i = 0;i < n;i++){
        x = rn(x);
        for(c = 0;c < 10;c++){
            if(x == c){
                count[c]=count[c] + 1;
            }
        }
    }

    //最大値の検索
    max = count[0];
    for (i = 0; i < 10; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }

    p = (double)max / 20;

    for(c = 0;c < 10;c++){
        star[c] = count[c] / p;
    }

    printf("%d\n%d\n",max,p);



    for(c = 0;c < 10;c++){
        printf("%d:",c);
        //printf("%d\n%d\n",count[1],counts[1]);
        /*for(i = 0;i < star[c];i++){
            printf("あ");
        }*/
        printf("%d\n",count[c]);
    }
}

int rn(int x){
    x = (11 * x + 11) % 10;
    return x;
}

