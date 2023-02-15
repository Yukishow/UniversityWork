#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
    { //輾轉相除法
        int num = b;
        b = a % b;
        a = num;
    }
    if (a == 1)
        return 1;
    else
        return 0;
}
int main()
{
    int N;
    scanf("%d", &N);
    while (N > 0)
    {
        int arr[1000];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        int number = 0;
        int count = (N - 1);
        while (count >= 0)
        {
            number += count;
            count--;
        }
        // printf("%d\n",number);
        int test = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                test += gcd(arr[i], arr[j]);
            }
        }
        // printf("%d\n",test);
        if (test == 0)
        {
            printf("No estimate for this data set.\n");
        }
        else
        {
            double pi;
            pi = sqrt((double)6 / test * number);
            printf("%.6lf\n", pi);
        }
        scanf("%d", &N);
    }
    
    return 0;
}