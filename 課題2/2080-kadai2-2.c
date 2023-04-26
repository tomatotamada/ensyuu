#include <stdio.h>
#include <math.h>

long factorial(long x);

int main(){
    for( ; ; ){
        long x;
        scanf("%ld",&x);
        if((1<=x)&&(x<=10)){
            if(factorial(x)<=0){
                printf("桁数の限界で表示できません\n");
            }else{
                printf("%ld! = %ld\n",x,factorial(x));
            }
        }else{
            if(factorial(x)<=0){
                printf("桁数の限界で表示できません\n");
            }else{
                printf("%ld! = %ld\n",x,factorial(x));
                break;
            }
        }
        
    }
}

long factorial(long x){
    if(x == 1){
        return 1;
    }else{
        return x*factorial(x-1);
    }
    
}