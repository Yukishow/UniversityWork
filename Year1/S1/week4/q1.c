#include <stdio.h>
int main()
{
    int x, sum;
    scanf("%d", &x);
    while (x != 0)
    {
        sum += x;
        scanf("%d", &x);
    }
    printf("%d", sum);

    return 0;
}