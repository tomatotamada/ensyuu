#include <stdio.h>

int rn(int x);
int countfn(int c);

int x,y,i,j,p ;
scanf("%d",&y);
int count[9];

int main(){
    /*int x,y,i,j,p ;
    scanf("%d",&y);
    int count[9];*/
    x = 1;
    for(i = 0;i < y + 1;i++){
        printf("%d\n",rn(x));
        for(j = 0;j < 11;j++){
            x = rn(x);
        }
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

/*int countfn(int c){
    int i,j;
    for(i = 0;i < 11;i++){
        for(j = 0;j < y;j++){
            if(i == rn(x)){
                count[i] = count[i] + 1;
            }

}*/

int countfn(int c){
    for(i = 0;i < y;i++){
        if(c == rn(x)){
            count[c] = count[c] + 1;
        }
    }
}