#include <stdio.h>
int main()
{
    int n;
    float sum;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[j] > a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
    for (int i = 0; i < n; i++)
        sum += a[i];
    sum = sum - (a[0] + a[1] + a[2]);
    sum = sum - (a[n - 1] + a[n - 2] + a[n - 3]);
    printf("%.2f", sum / (n - 6));

    return 0;
}