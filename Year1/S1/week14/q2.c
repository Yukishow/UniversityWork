#include <stdio.h>
#include <string.h>
int main()
{
    char str[500];
    scanf("%s", str);
    int FGcount = 0, numcount = 0, temp = 0;
    char FG[500];
    int num[500];
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'F' || str[i] == 'G')
        {
            FG[FGcount] = str[i];
            FGcount++;
            if (temp != 0)
            {
                num[numcount] = temp;
                numcount++;
            }
            temp = 0;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            temp *= 10;
            temp += (str[i] - '0');
        }
        else
        {
            if (temp != 0)
            {
                num[numcount] = temp;
                numcount++;
            }
            temp = 0;
        }
    }
    int n = numcount - 1, m = FGcount - 1;
    for (int i = m; i >= 0; i--)
    {
        if (FG[i] == 'F')
        {
            num[n]++;
        }
        else
        {
            num[n - 1] += num[n];
            n--;
        }
    }
    printf("%d", num[0]);

    return 0;
}