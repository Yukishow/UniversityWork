#include <stdio.h>
#include <string.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int polt[500][500];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &polt[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (polt[i][j] == 1)
            {
                int count = 0;
                if (polt[i - 1][j - 1] == 1 && i - 1 >= 0 && j - 1 >= 0)
                    count++;
                if (polt[i - 1][j] == 1 && i - 1 >= 0)
                    count++;
                if (polt[i - 1][j + 1] == 1 && i - 1 >= 0 && j + 1 < m)
                    count++;
                if (polt[i][j - 1] == 1 && j - 1 >= 0)
                    count++;
                if (polt[i][j + 1] == 1 && j + 1 < m)
                    count++;
                if (polt[i + 1][j - 1] == 1 && i + 1 < n && j - 1 >= 0)
                    count++;
                if (polt[i + 1][j] == 1 && i + 1 < n)
                    count++;
                if (polt[i + 1][j + 1] == 1 && i + 1 < n && j + 1 < m)
                    count++;
                if (!count)
                {
                    polt[i][j] = 0;
                }
            }
            if (polt[i][j] == 0)
            {
                int count = 0;
                if (polt[i - 1][j - 1] == 0 && i - 1 >= 0 && j - 1 >= 0)
                    count++;
                if (polt[i - 1][j] == 0 && i - 1 >= 0)
                    count++;
                if (polt[i - 1][j + 1] == 0 && i - 1 >= 0 && j + 1 < m)
                    count++;
                if (polt[i][j - 1] == 0 && j - 1 >= 0)
                    count++;
                if (polt[i][j + 1] == 0 && j + 1 < m)
                    count++;
                if (polt[i + 1][j - 1] == 0 && i + 1 < n && j - 1 >= 0)
                    count++;
                if (polt[i + 1][j] == 0 && i + 1 < n)
                    count++;
                if (polt[i + 1][j + 1] == 0 && i + 1 < n && j + 1 < m)
                    count++;
                if (!count)
                {
                    polt[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", polt[i][j]);
        }
        printf("\n");
    }

    return 0;
}