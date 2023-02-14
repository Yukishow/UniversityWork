#include <stdio.h>
int main()
{
    int x, m = 0;
    scanf("%d", &x);
    while (x != 0)
    {
        for (int i = 1; i <= x; i++)
            if (x % i == 0)
                m++;
        if (m == 2)
            printf("prime");
        else
            printf("not a prime");
        printf("\n");
        m = 0;
        scanf("%d", &x);
    }

    return 0;
}