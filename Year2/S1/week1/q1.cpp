#include <stdio.h>
#include <stdlib.h>
void allocArray(int ***p, int m, int n)
{
    int **ptr1 = (int**)malloc(sizeof(int*)*m);
    int *ptr2 = (int*)malloc(sizeof(int)*m*n);
    for (int i=0;i<m;i++){
        ptr1[i] = ptr2 + i*n;
    }
    *p = ptr1; 
}
int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));

    return 0;
}