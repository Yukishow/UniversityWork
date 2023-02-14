#include <stdio.h>
int main()
{
    float x, y;
    scanf("%f%f", &x, &y);
    printf("%f + %f = %.2f\n", x, y, x + y);
    printf("%f - %f = %.2f\n", x, y, x - y);
    printf("%f * %f = %.2f\n", x, y, x * y);
    printf("%f / %f = %.2f\n", x, y, x / y);
    
    return 0;
}