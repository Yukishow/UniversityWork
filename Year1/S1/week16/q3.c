#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    char country[2000][75], temp[75];
    char woman[2000][75];
    int count[2000];
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        int test = 1;
        for (int i = 0; i < find; i++)
        {
            if (strcmp(temp, country[i]) == 0)
            {
                count[i]++;
                test = 0;
                break;
            }
        }
        if (test == 1)
        {
            strcpy(country[find], temp);
            count[find] += 1;
            find++;
        }
        gets(woman[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(country[i], country[j]) > 0)
            {
                char x[75];
                strcpy(x, country[i]);
                strcpy(country[i], country[j]);
                strcpy(country[j], x);
                int y = count[i];
                count[i] = count[j];
                count[j] = y;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (count[i] > 0)
        {
            printf("%s %d\n", country[i], count[i]);
        }
    }

    return 0;
}