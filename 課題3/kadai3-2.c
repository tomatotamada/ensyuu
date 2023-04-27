#include <stdio.h>

int rn(int x);
int countfn(int c,int y,int x);
int count[9];

int main(){
    int x,y,i,j,p;
    scanf("%d",&y);
    x = 1;
    for(i = 0;i < y;i++){
        printf("%d\n",rn(x));
        for(j = 0;j < 11;j++){
            x = rn(x);
            printf("キンタマ%d%d\n",j,countfn(j,y,x));
        }
    }

    /*for(i = 0;i < 10;i++){
        printf("キンタマ%d\n",countfn(i,y,x));
    }*/

}

int rn(int x){
    x = (11 * x + 11) % 10;
    /*if(x == 0){
        x = 10;
    }*/
    return x;
}

int countfn(int c,int y,int x){
    int i;
    for(i = 0;i < y;i++){
        if(c == rn(x)){
            count[c] = count[c] + 1;
        }
    }
    return count[c];
}