#include <stdio.h>
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m], b[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (n > b[i])
        {
            sum += a[i] * b[i];
            n -= b[i];
        }
        else
        {
            sum += a[i] * n;
            break;
        }
    }
    printf("%d", sum);
    
    return 0;
}