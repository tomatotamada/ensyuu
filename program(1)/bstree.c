#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

int gShortFormat = 1;

void error(char *msg){
   fflush(stdout);
   fprintf(stderr, "%s\n", msg);
   exit(1);
}

void destroyNode(BSTREE_NODE *del){
   memset(del, 0, sizeof(BSTREE_NODE));
   free(del);
}

void destroyBSTree(BSTREE_NODE *p){
   if(p == NULL) return;
   destroyBSTree(p->left);
   destroyBSTree(p->right);
   destroyNode(p);
}

int isLeafNode(BSTREE_NODE *p){return(p->left == NULL) && (p->right == NULL);}

void printSubBSTree(BSTREE_NODE *p){
   if(p == NULL){printf("_"); return;}
   if(gShortFormat !=0 && isLeafNode(p)){printf("%d", p->value);}
   else{
      printf("[ ");
      printf("%d ", p->value);
      printSubBSTree(p->left);
      printf(" ");
      printSubBSTree(p->right);
      printf(" ]");
   }
}

void printBSTree(BSTREE_NODE *p, int tabs, int brief){
   int i;

   gShortFormat = brief;
   for(i = 0; i < tabs; i++) printf("\t");
   printSubBSTree(p);
   printf("\n");
   fflush(stdout);
}

BSTREE_NODE *createNode(BSTREE_TYPE x){
   BSTREE_NODE *new;

   new = malloc(sizeof(BSTREE_NODE));
   if(new == NULL) error("createNode:　メモがありません");
   new->value = x;
   new->left = NULL;
   new->right = NULL;
   return new;
}

BSTREE_NODE *findNode(BSTREE_NODE *p, BSTREE_TYPE x){
   if(p == NULL)         {return NULL;                 } /* 規則A1 */ 
   else if(p->value == x){return p;                    } /* 規則A2 */
   else if(p->value > x) {return findNode(p->left, x); } /* 規則A3 */
   else                  {return findNode(p->right, x);} /* 規則A4 */
}

BSTREE_NODE *insertNode(BSTREE_NODE *p, BSTREE_TYPE x){
   if(p == NULL)         {p = createNode(x);                  } /* 規則B1 */
   else if(p->value == x){error("insertNode: 指定ノードあり");} /* 規則B2 */
   else if(p->value > x) {p->left = insertNode(p->left, x);   } /* 規則B3 */
   else                  {p->right = insertNode(p->right, x); } /* 規則B4 */
   return p;
}

BSTREE_NODE *deleteNode(BSTREE_NODE *p, BSTREE_TYPE x){
   if(p == NULL)         error("deleteNode: 指定ノードなし");          /*規則C1*/
   if(p->value == x)    {return deleteRootNode(p, x);                 }/*規則C2*/
   else if(p->value > x){p->left = deleteNode(p->left, x); return p;  }/*規則C3*/
   else                 {p->right = deleteNode(p->right, x); return p;}/*規則C4*/
}

BSTREE_NODE *deleteRootNode(BSTREE_NODE *p, BSTREE_TYPE x){
   BSTREE_NODE *sub;
   BSTREE_TYPE min;

   if (isLeafNode(p)){			/* 規則D1 */
      destroyNode(p);
      return NULL;
   }
   else if(p->right == NULL){		/* 規則D2 */
      sub = p->left;
      destroyNode(p);
      return sub;
   }
   else if (p->left == NULL){		/* 規則D2 */
      sub = p->right;
      destroyNode(p);
      return sub;
   }
   else {				/* 規則D3 */
      p->right = deleteMinNode(p->right, &min);
      p->value = min;
      return p;
   }
}

BSTREE_NODE *inputBSTree(BSTREE_NODE *btree, char *str[], int len, int *end){
   BSTREE_TYPE x;
   int i, n = 0;

   for(i = 0; i < len; i++){
      if(!strcmp(str[i], "--")) break; /* データの終わり？ */
      x = atoi(str[i]);
      if(btree == NULL) btree = createNode(x);
      else btree = insertNode(btree, x);
      n++;
   }
   *end = n;
   return btree;
}

BSTREE_NODE *deleteMinNode(BSTREE_NODE *p, BSTREE_TYPE *min){
}

