#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int sum, max, temp;
    char str[1000];
    while (gets(str) != NULL)
    {
        sum = 0;
        max = 1;
        int i;
        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                temp = str[i] - '0';
            }
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                temp = str[i] - 'A' + 10;
            }
            else if (str[i] >= 'a' && str[i] <= 'z')
            {
                temp = str[i] - 'a' + 36;
            }
            else
                continue;
            if (max < temp)
                max = temp;
            sum += temp;
        }

        for (i = max; i < 62; i++)
            if (sum % i == 0)
            {
                printf("%d\n", i + 1);
                break;
            }
        if (i == 62)
            printf("such number is impossible!\n");
    }

    return 0;
}