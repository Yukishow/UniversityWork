#include <stdio.h>
int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a < b)
    {
        if (c < d)
        {
            if (c > a && c < b)
                printf("overlay");
            else if (c < a && d > b)
                printf("overlay");
            else if (d > a && d < b)
                printf("overlay");
            else if (a == c && b == d)
                printf("overlay");
            else
                printf("no overlay");
        }
        else
        {
            if (d > a && d < b)
                printf("overlay");
            else if (d < a && c > b)
                printf("overlay");
            else if (c > a && c < b)
                printf("overlay");
            else
                printf("no overlay");
        }
    }
    else
    {
        if (c < d)
        {
            if (c > b && c < a)
                printf("overlay");
            else if (c < b && d > a)
                printf("overlay");
            else if (d > b && d < a)
                printf("overlay");
            else
                printf("no overlay");
        }
        else
        {
            if (d > b && d < a)
                printf("overlay");
            else if (d < b && c > a)
                printf("overlay");
            else if (c > b && c < a)
                printf("overlay");
            else if (a == c && b == d)
                printf("overlay");
            else
                printf("no overlay");
        }
    }

    return 0;
}