#include <stdio.h>
int main()
{
    double N, a = 0, b, c;
    scanf("%lf", &N);
    b = N; //賦予上界
    while (b - a >= 0.00001)
    { //使用二分逼近 求得平方根
        c = (a + b) / 2;
        if (c * c >= N)
            b = c;
        else
            a = c;
    }
    printf("%.4f", b);
    
    return 0;
}