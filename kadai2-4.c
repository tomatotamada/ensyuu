#include <stdio.h>


int gcd(int x, int y);

int main(){
    int x,y;
    scanf("%d %d",&x, &y);
    printf("%dと%dの最大公約数は%dです\n",x,y,gcd(x,y));

}

int gcd(int x,int y){
    if(x<0){
        x=x*-1;
    }
    if(y<0){
        y=y*-1;
    }

    if(y == 0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}