#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int max = x, min = x;
    while (scanf("%d", &x) != EOF)
    {  
        if (min > x) //求出最小值
            min = x;
        if (max < x) //求出最大值
            max = x;
    }
    printf("%d %d", max, min);

    return 0;
}