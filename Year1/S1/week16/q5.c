#include <stdio.h>
#include <string.h>
int main()
{
    int n, m, Field = 0;
    scanf("%d%d", &n, &m);
    while (n != 0 && m != 0)
    {
        Field++;
        char test[n][m + 1];
        char ans[n][m + 1];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &test[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (test[i][j] == '*')
                {
                    ans[i][j] = '*';
                }
                else
                {
                    int count = 0;
                    if (i - 1 >= 0 && j - 1 >= 0 && test[i - 1][j - 1] == '*')
                        count++;
                    if (i - 1 >= 0 && test[i - 1][j] == '*')
                        count++;
                    if (i - 1 >= 0 && j + 1 < m && test[i - 1][j + 1] == '*')
                        count++;
                    if (j - 1 >= 0 && test[i][j - 1] == '*')
                        count++;
                    if (j + 1 <= m && test[i][j + 1] == '*')
                        count++;
                    if (i + 1 < n && j - 1 >= 0 && test[i + 1][j - 1] == '*')
                        count++;
                    if (i + 1 < n && test[i + 1][j] == '*')
                        count++;
                    if (i + 1 < n && j + 1 < m && test[i + 1][j + 1] == '*')
                        count++;
                    ans[i][j] = count + '0';
                }
            }
        }
        printf("Field #%d:\n", Field);
        for (int i = 0; i < n; i++)
        {
            ans[i][m] = '\0';
            printf("%s\n", ans[i]);
        }
        printf("\n");
        scanf("%d%d", &n, &m);
    }

    return 0;
}