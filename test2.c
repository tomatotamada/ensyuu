#include <stdio.h>
#include <math.h>

int main(){
    int i,j;  
    for(i=1;i<6;i++){
        for(j=1;j<6;j++){
        printf("%d X %d = %d\n",i,j,i*j);  
    }   
        printf("--------------------\n");
    }  
    double x,y;
    x=2;
    y=sqrt(x);
    printf("%lf",y);
    return 0; 
} 