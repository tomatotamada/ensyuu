#include<stdio.h>

typedef struct{
    int x;
    int y;
}point;

int main (void){
    point p[100] = {0};
    point table[5][100] = {0};
    int count=0,j,i;

    while(scanf("%d  %d",&p[count].x,&p[count].y) != EOF){
        count++;
    }

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
        if(table[1][j].x != 0 && table[1][j].y !=0){
            printf("(%d,%d)\n",table[1][j].x,table[1][j].y);
        }
    }

    printf("The number of II quadrant (LUQ)\n");
    for(j = 0;j < count;j++){
        if(table[2][j].x != 0 && table[2][j].y !=0){
            printf("(%d,%d)\n",table[2][j].x,table[2][j].y);
        }
    }

    printf("The number of III quadrant (LLQ)\n");
    for(j = 0;j < count;j++){
        if(table[3][j].x != 0 && table[3][j].y !=0){
            printf("(%d,%d)\n",table[3][j].x,table[3][j].y);
        }
    }

    printf("The number of IV quadrant (RLQ)\n");
    for(j = 0;j < count;j++){
        if(table[4][j].x != 0 && table[4][j].y !=0){
            printf("(%d,%d)\n",table[4][j].x,table[4][j].y);
        }
    }
    


}