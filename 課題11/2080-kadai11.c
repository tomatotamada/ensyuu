#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main(int argc, char *argv[])
{
    BSTREE_NODE *bstree = NULL;
    BSTREE_NODE *result;
    BSTREE_NODE *min;
    BSTREE_TYPE x;
    
    int i, n1;
    bstree = inputBSTree(bstree, &argv[1], argc - 1, &n1);
    if (n1 < 1 || argc - 1 - n1 < 2)
        error("引数の指定方法：整数1 整数 2 … -- X1 X2 …");
    printf("入力データ ");
    printBSTree(bstree, 0, 1);

    deleteMinNode(bstree,x);
    printBSTree(bstree,0,1);

    for (i = n1 + 2; i < argc ; i++)
    {
        x = atoi(argv[i]);
        printf("deleteNode(%d)\n", x);
        result = deleteNode(bstree, x);
        printf(" ==> ");
        printBSTree(result, 0, 1);
        bstree = result;
    }



    destroyBSTree(bstree);
    return 0;
}
