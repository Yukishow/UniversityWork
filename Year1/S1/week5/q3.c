#include <stdio.h>
int main()
{
    int x, sum = 0, m, a = 1, p = 0, q = 0;
    scanf("%d", &x);
    if (x % 2 == 0)
    {
        for (int i = 1; i <= (x / 2); i++)
        {
            m = x - a;
            for (int j = 1; j <= a; j++)
                if (a % j == 0)
                    p++;
            if (p == 2)
                for (int j = 1; j <= m; j++)
                    if (m % j == 0)
                        q++;
            if (q == 2 && p == 2)
                sum++;
            a++;
            q = 0;
            p = 0;
        }
    }
    else
    {
        for (int i = 1; i <= (x + 1) / 2; i++)
        {
            m = x - a;
            for (int j = 1; j <= a; j++)
                if (a % j == 0)
                    p++;
            if (p == 2)
                for (int j = 1; j <= m; j++)
                    if (m % j == 0)
                        q++;
            if (q == 2 && p == 2)
                sum++;
            a++;
            q = 0;
            p = 0;
        }
    }
    printf("%d", sum);
    
    return 0;
}