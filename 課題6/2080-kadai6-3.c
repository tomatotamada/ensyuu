#include <stdio.h>
#include <stdlib.h>

int* makeArray(int argc, char* argv[]);

int i, num;
double sum = 0.0;
double* table;

int main(int argc, char *argv[]){
    /*int i, num=0;
    double sum = 0.0;
    double* table;*/

    makeArray(argc,argv);

    for (i = 0; i < num; i++){
        *(table + i) = atof(argv[i + 1]);
    }
    for (i = 0; i < num; i++){
        sum += table[i];
    }
    printf("Average of %d doubles is %.2f.\n", num, sum / num);
    free(table);
    return 0;
}


int* makeArray(int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Arguments are not specified.\n");
        exit(1);
    }
    num = argc -1;
    table = malloc(sizeof(double) * num);
    if (table == NULL){
        fprintf(stderr, "Memory Shortage.\n");
        exit(1);
    }
}