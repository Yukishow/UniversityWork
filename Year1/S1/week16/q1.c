#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    getchar();
    for (int i = 0; i < n; i++)
    {
        char temp[31];
        char spices[500][31];
        int count[500] = {0};
        int found = 0;
        double total = 0;
        while (gets(temp) != NULL && temp[0] != '\0')
        {
            int test = 1;
            for (int j = 0; j < found; j++)
            {
                if (strcmp(temp, spices[j]) == 0)
                {
                    count[j]++;
                    total++;
                    test = 0;
                }
            }
            if (test)
            {
                strcpy(spices[found], temp);
                count[found]++;
                total++;
                found++;
            }
        }
        for (int j = 0; j < found; j++)
        {
            for (int k = j + 1; k < found; k++)
            {
                if (strcmp(spices[j], spices[k]) > 0)
                {
                    strcpy(temp, spices[j]);
                    strcpy(spices[j], spices[k]);
                    strcpy(spices[k], temp);
                    int x = count[j];
                    count[j] = count[k];
                    count[k] = x;
                }
            }
        }
        for (int j = 0; j < found; j++)
        {
            printf("%s %.4lf\n", spices[j], (count[j] / total) * 100);
        }
        printf("\n");
    }

    return 0;
}