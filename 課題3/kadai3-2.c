#include <stdio.h>

int rn(int x);
int countfn(int c,int y,int x);
int count[9];
long counts[9];
int max(int nums[]);

int main(){
    int x,y,c,i,max;
    long p;
    scanf("%d",&y);
    x = 1;
    for(i = 0;i < y;i++){
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
    p = max / 20;
    for(c = 0;c < 10;c++){
        counts[c] = count[c] * p;
    }



    for(c = 0;c < 10;c++){
        printf("%d:",c);
        for(i = 0;i < counts[c];i++){
            printf("あ");
        }
        printf("%d\n",count[c]);
    }
}

int rn(int x){
    x = (11 * x + 11) % 10;
    return x;
}

