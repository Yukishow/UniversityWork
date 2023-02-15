#include <stdio.h>
int main()
{
    int price, pay, sum;
    while (scanf("%d%d", &price, &pay) != EOF)
    {
        sum = pay - price;
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0;
        if (sum / 2000 != 0)
        {
            a = sum / 2000;
            sum = sum % 2000;
        }
        if (sum / 1000 != 0)
        {
            b = sum / 1000;
            sum = sum % 1000;
        }
        if (sum / 500 != 0)
        {
            c = sum / 500;
            sum = sum % 500;
        }
        if (sum / 200 != 0)
        {
            d = sum / 200;
            sum = sum % 200;
        }
        if (sum / 100 != 0)
        {
            e = sum / 100;
            sum = sum % 100;
        }
        if (sum / 50 != 0)
        {
            f = sum / 50;
            sum = sum % 50;
        }
        if (sum / 10 != 0)
        {
            g = sum / 10;
            sum = sum % 10;
        }
        if (sum / 5 != 0)
        {
            h = sum / 5;
            sum = sum % 5;
        }
        i = sum;
        printf("%d %d %d %d %d %d %d %d %d \n", a, b, c, d, e, f, g, h, i);
    }
    
    return 0;
}