#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    if (x % 2 == 0)
        printf("even");
    else
        printf("odd");

    return 0;
}