#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int BITREE_TYPE;  	/* 格納データの型 */

struct node {
	BITREE_TYPE value; 		/* ノードの値 */
	struct node *left; 		/* 左ノードのアドレス */
	struct node *right; 	/* 右ノードのアドレス */
};
typedef struct node BITREE_NODE;

int gShortFormat = 1;

void error(char *msg);
BITREE_NODE *createNode(BITREE_TYPE x);
void destroyBITree(BITREE_NODE *p);
int isLeafNode(BITREE_NODE *p);
void printBITree(BITREE_NODE *p, int tabs, int brief);
BITREE_NODE *inputBITree(char *str[], int len, int *end);
BITREE_TYPE sumValue(BITREE_NODE *p);


void error(char *msg)
{
    fflush(stdout);
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

BITREE_NODE *createNode(BITREE_TYPE x)
{
    BITREE_NODE *new;

    new = malloc(sizeof(struct node));
    if (new == NULL)
        error("createNode: メモリがありません");
    new->value = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void destroyBITree(BITREE_NODE *p)
{
    if (p == NULL)
        return;

    destroyBITree(p->left);
    destroyBITree(p->right);
    memset(p, 0, sizeof(struct node));
    free(p);
}

int isLeafNode(BITREE_NODE *p)
{
    return (p->left == NULL) && (p->right == NULL);
}

void printSubtree(BITREE_NODE *p)
{
    if (p == NULL)
    {
        printf("_");
        return;
    }
    if (gShortFormat != 0 && isLeafNode(p))
    {
        printf("%d", p->value);
    }
    else
    {
        printf("[ ");
        printf("%d ", p->value);
        printSubtree(p->left);
        printf(" ");
        printSubtree(p->right);
        printf(" ]");
    }
}

void printBITree(BITREE_NODE *p, int tabs, int brief)
{
    int i;

    gShortFormat = brief;
    for (i = 0; i < tabs; i++)
        printf("\t");
    printSubtree(p);
    printf("\n");
    fflush(stdout);
}

BITREE_NODE *inputBITree(char *str[], int len, int *end)
{
    BITREE_NODE *p;
    int i = 0;

    if (len < 1)
        error("inputBITree:データがありません");

    /*短縮形の処理*/
    if (strcmp(str[0], "[") != 0)
    {
        if (strcmp(str[0], "_") == 0)
            error("inputBTITree:値に＿は指定できません");
        *end = 1;
        return createNode(atoi(str[0]));
    }

    /*短縮形でないときの処理*/
    if (len < 5)
        error("inputBITree:入力データが正しくありません");

    if (strcmp(str[1], "_") == 0)
        error("inputBITree:値に＿は指定できません");
    p = createNode(atoi(str[1]));

    i = 2;
    if (strcmp(str[i], "_") != 0)
    {
        p->left = inputBITree(&str[i], len - i, end);
        i += *end;
    }
    else
    {
        i++;
    }

    if (strcmp(str[i], "_") != 0)
    {
        p->right = inputBITree(&str[i], len - i, end);
        i += *end;
    }
    else
    {
        i++;
    }

    if (strcmp(str[i], "]") != 0)
        error("inputBITree: 入力データが]で終わっていません");
    *end = i + 1;
    return p;
}

BITREE_TYPE sumValue(BITREE_NODE *p){
	BITREE_TYPE L;
	BITREE_TYPE R;


	if (p == NULL) {
		return 0;
	}

	L = sumValue(p->left);
	R = sumValue(p->right);
	return (L + R + p->value);
	
}