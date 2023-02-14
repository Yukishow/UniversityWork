#include <stdio.h>
int main()
{
    int candidate, vote, x;
    scanf("%d%d", &candidate, &vote);
    while (candidate != 0 && vote != 0)
    {
        int a[candidate];
        for (int i = 0; i < candidate; i++)
            a[i] = 0;
        for (int i = 1; i <= vote; i++)
        {
            scanf("%d", &x);
            if (x <= candidate)
            {
                a[x - 1]++;
            }
        }
        int b[candidate];
        for (int i = 0; i < candidate; i++)
            b[i] = a[i];
        for (int i = 0; i < candidate; i++)
            for (int j = 0; j < candidate; j++)
                if (a[j] > a[i])
                {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
        if (a[candidate - 1] == a[candidate - 2])
            printf("No winner\n");
        else
        {
            if (a[candidate - 1] > (vote) / 2)
            {
                for (int i = 0; i < candidate; i++)
                    if (b[i] == a[candidate - 1])
                        printf("Majoritarian winner %d\n", i + 1);
            }

            else
            {
                for (int i = 0; i < candidate; i++)
                    if (b[i] == a[candidate - 1])
                        printf("Plurality winner %d\n", i + 1);
            }
        }
        scanf("%d%d", &candidate, &vote);
    }

    return 0;
}