#include <stdio.h>
#include <stdlib.h>

int n;

void bubble_sort(int *A);
void bubble_sort_show(int *A);

int main(int argc, char *argv[])
{
   int i;
   n = argc - 1;

   int A[n];

   for (i = 1; i < argc; i++)
      A[i - 1] = atoi(argv[i]);

   printf("A[] =");
   for (i = 0; i < n; i++)
      printf(" %d", A[i]);
   printf("\n");

   bubble_sort_show(A); // 配列A[0]からA[n-1]のバブルソート

   // printf("A[] =");
   // for (i = 0; i < n; i++)
   //    printf(" %d", A[i]);
   // printf("\n");

   return 0;
}

// void bubble_sort(int *A)
// {
//    int i, j;
//    for (i = 0; i < n - 1; i = i + 1)
//    {
//       for (j = n - 1; j > i; j = j - 1)
//       {
//          if (A[j - 1] > A[j])
//          {

//             int t;
//             t = A[j];
//             A[j] = A[j - 1];
//             A[j - 1] = t;
//          }
//       }
//    }
// }

void bubble_sort_show(int *A)
{
   int i, j, k, hikaku = 0, koukan = 0;
   for (i = 0; i < n - 1; i = i + 1)
   {
      printf("A = パス%d:\n", i + 1);
      for (j = n - 1; j > i; j = j - 1)
      {
         if (A[j - 1] > A[j])
         {
            for (k = 0; k < n; k++)
            {
               if (k == j)
               {
                  printf("   >");
               }
               printf("\t %d", A[k]);
            }
            printf("\n");
            int t;
            t = A[j];
            A[j] = A[j - 1];
            A[j - 1] = t;
            hikaku++;
            koukan++;
         }
         else
         {
            for (k = 0; k < n; k++)
            {
               if (k == j)
               {
                  printf("   <");
               }
               printf("\t %d", A[k]);
            }
            printf("\n");
            int t;
            hikaku++;
         }
      }
   }
   printf("比較は%d回でした\n",hikaku);
   printf("交換は%d回でした\n",koukan);
}
