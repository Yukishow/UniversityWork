#include <stdio.h>
int main()
{
    int x, i = 2, m, n;
    scanf("%d", &x);
    while (x != 0)
    {
        printf("%d = ", x);
        while (x > 1)
        {
            while (x % i == 0)
            {
                x = x / i;
                printf("%d", i);
                if (x == 1)
                    break;
                printf(" * ");
            }
            i++;
        }
        i = 2;
        printf("\n");
        scanf("%d", &x);
    }

    return 0;
}