#include <stdio.h>
int main()
{
    int x, n = 0;
    int a[100];
    scanf("%d", &x);
    while (x != 0)
    {
        a[n] = x % 10;
        x = x / 10;
        n++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            printf("----- ");
        if (a[i] == 1)
            printf(".---- ");
        if (a[i] == 2)
            printf("..--- ");
        if (a[i] == 3)
            printf("...-- ");
        if (a[i] == 4)
            printf("....- ");
        if (a[i] == 5)
            printf("..... ");
        if (a[i] == 6)
            printf("-.... ");
        if (a[i] == 7)
            printf("--... ");
        if (a[i] == 8)
            printf("---.. ");
        if (a[i] == 9)
            printf("----. ");
    }

    return 0;
}