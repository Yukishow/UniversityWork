#include <stdio.h>
int main()
{
    int x, a, b, c, d;
    scanf("%d", &x);
    a = x / 1000;
    b = x % 1000 / 100;
    c = x % 100 / 10;
    d = x % 10 / 1;
    printf("%d%d%d%d", d, c, b, a);

    return 0;
}