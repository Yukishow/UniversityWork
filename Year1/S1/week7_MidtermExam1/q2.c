#include <stdio.h>
int main()
{
    int x, num = 0;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                num++;
        }
        if (num == 2)
        {
            int a, b = 0;
            a = i;
            while (a != 0)
            {
                b = b * 10 + a % 10;
                a = a / 10;
            }
            if (i == b)
            {
                printf("%d ", i);
            }
        }
        num = 0;
    }
    
    return 0;
}