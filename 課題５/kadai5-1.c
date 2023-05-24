#include<stdio.h>

typedef struct{
    int x;
    int y;
}point;

int main (void){
    point p[100];
    point table[5][100];
    int count=0,j,i;

    while(scanf("%d %d",&p[i].x,&p[i].y) != EOF){
        count++;
    }
    //printf("%d,%d",p[2].x,p[2].y);
    //printf("%d",count);


    for(i = 0;i<count;i++){
        if(p[i].x >0 && p[i].y>0){
            table[1][i] = p[i];
        }else if(p[i].x <0 && p[i].y>0){
            table[2][i] = p[i];
        }else if(p[i].x <0 && p[i].y<0){
            table[3][i] = p[i];
        }else if(p[i].x >0 && p[i].y<0){
            table[4][i] = p[i];
        }else{
            table[0][i] = p[i];
        }
    }
    
    printf("The number of I quadrant (RUQ)\n");
    for(j = 0;j < count;j++){
        printf("(%d,%d)\n",table[1][j].x,table[1][j].y);
    }
    


}