#include <stdio.h>

int rn(int x);
int countfn(int c);

int main(){
    int x,y,i,j,p ;
    scanf("%d",&y);
    int count[9][y];
    x = 1;
    for(i = 1;i < y + 1;i++){
        printf("%d\n",rn(x));
        for(j = 0;j < 11;j++){
            p = 0;
            if(j == rn(x)){
                count[j][p] = rn(x);
                p = p + 1;
            }
            x = rn(x);
        }

        //x = rn(x);
    }
    printf("",);

}

int rn(int x){
    x = (11 * x + 11) % 10;
    /*if(x == 0){
        x = 10;
    }*/
    return x;
}

int countfn(int c){
    int i,j;
    for(i = 0;i < 11;i++){
        for(j = 0;j < y;j++){
            if(i == )

        }
    }

}