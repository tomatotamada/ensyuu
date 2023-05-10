#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX_FREQ 20

int rn(int *seed){
    int a = 1103515245, b = 12345, m = 2147483648;
    *seed = (a * (*seed) + b) % m;
    return *seed % N + 1;
}

int main(){
    int n, i, seed, freq[N+1] = {0}, max_freq = 0;
    double percentage[N+1];

    srand((unsigned)time(NULL));
    seed = rand();

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        int r = rn(&seed);
        freq[r]++;
    }

    printf("Frequency Distribution\n");

    for(i = 1; i <= N; i++){
        if(freq[i] > max_freq){
            max_freq = freq[i];
        }
    }

    for(i = max_freq; i >= 1; i--){
        printf("%2d |", i);
        int j;
        for(j = 1; j <= N; j++){
            if(freq[j] >= i){
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("| ");
        for(j = 1; j <= N; j++){
            printf("%2d ", freq[j]);
        }
        printf("\n");
    }

    printf("   +");
    for(i = 1; i <= N; i++){
        printf("---");
    }
    printf("+\n");

    printf("    ");
    for(i = 1; i <= N; i++){
        printf("%2d ", i);
    }

    printf("\n\n");

    return 0;
}
