#include <stdio.h>

int rn(int x);

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
    printf("%ld\n",sizeof(count[0]) / sizeof(count[0][0]));

}

int rn(int x){
    x = (11 * x + 11) % 10;
    /*if(x == 0){
        x = 10;
    }*/
    return x;
}