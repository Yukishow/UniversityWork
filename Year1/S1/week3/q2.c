#include <stdio.h>
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    if (m % n == 0)
        printf("%d is a multiple of %d.", m, n);
    else
        printf("%d is not a multiple of %d.", m, n);

    return 0;
}