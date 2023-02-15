#include <stdio.h>
#include <string.h>
int main()
{
    char item[500][150], temp[150];
    int paid[500] = {0};
    int count[500] = {0};
    int exit = 0;
    while (scanf("%s", temp) != EOF)
    {
        int pay;
        scanf("%d", &pay);
        int found = 1;
        for (int i = 0; i < exit; i++)
        {
            if (strcmp(temp, item[i]) == 0)
            {
                paid[i] += pay;
                count[i]++;
                found = 0;
            }
        }
        if (found)
        {
            strcpy(item[exit], temp);
            paid[exit] += pay;
            count[exit]++;
            exit++;
        }
    }
    for (int i = 0; i < exit; i++)
    {
        for (int j = i + 1; j < exit; j++)
        {
            if (paid[j] > paid[i])
            {
                strcpy(temp, item[i]);
                strcpy(item[i], item[j]);
                strcpy(item[j], temp);
                int x = paid[i];
                paid[i] = paid[j];
                paid[j] = x;
            }
            if (paid[j] == paid[i] && count[j] > count[i])
            {
                strcpy(temp, item[i]);
                strcpy(item[i], item[j]);
                strcpy(item[j], temp);
                int x = paid[i];
                paid[i] = paid[j];
                paid[j] = x;
            }
        }
    }
    for (int i = 0; i < exit; i++)
    {
        printf("%s %d\n", item[i], paid[i]);
    }

    return 0;
}