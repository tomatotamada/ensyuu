#include<stdio.h>


int rn(int x);


int main(void){
    int n,i,j,x,stari[10];
    int count[10] = {};
    double p[10] = {},t,star[10],max = 0;

    printf("乱数の発生回数を入力してください\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        x = rn(x);
        switch (x)
        {
        case 1:
            count[1]++;
            break;
        
        case 2:
            count[2]++;
            break;

        case 3:
            count[3]++;
            break;

        case 4:
            count[4]++;
            break;

        case 5:
            count[5]++;
            break;

        case 6:
            count[6]++;
            break;

        case 7:
            count[7]++;
            break;

        case 8:
            count[8]++;
            break;

        case 9:
            count[9]++;
            break;

        case 0:
            count[0]++;
            break;

        default:
            break;
        }
    }


    // printf("それぞれ\n");
    // for(i=0;i<10;i++){
    //     printf("%d\n",count[i]);
    // }

    // for(i=0;i<10;i++){
    //     p[i] = count[i] / n;
    // }


    for(i=0;i<10;i++){
        if(max < count[i]){
            max = count[i];
        }
    }

    //max * t =20

    // printf("%f\n",max);

    t = 20 / max;

    // printf("%f\n",t);

    printf("ここから\n");


    for(i=0;i<10;i++){
        star[i] = p[i] * t;
        stari[i] = (int)star[i];
        for(j=0;j<stari[i];i++){
            printf("?");
        }
        printf("%d\n",stari[i]);
        printf("\n");
    }

}





int rn(int x){
    x = (11 * x + 11) % 10;
    return x;
}
