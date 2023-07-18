#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitree.h"




int main(int argc, char *argv[])
{
    BITREE_NODE *bitree = NULL;
    int n1;

    bitree = inputBITree(&argv[1], argc - 1, &n1);
    printBITree(bitree, 1, 0);
    printf("==>合計は%dです。\n", sumValue(bitree));
    printf("==>左部分木の合計は%dです。\n", sumValue(bitree->left));
    printf("==>右部分木の合計は%dです。\n", sumValue(bitree->right));

    destroyBITree(bitree);
    return 0;
}


