#include <stdio.h>
#include <ctype.h>
int main()
{
    char alpha[26];
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 'A' + i;
        count[i] = 0;
    }
    int n;
    char temp[1000];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        gets(temp);
        for (int i = 0; temp[i] != '\0'; i++)
        {
            if (isalpha(temp[i]))
            {
                count[toupper(temp[i]) - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (count[i] < count[j])
            {
                int x = count[i];
                count[i] = count[j];
                count[j] = x;
                char y = alpha[i];
                alpha[i] = alpha[j];
                alpha[j] = y;
            }
            if (count[i] == count[j])
            {
                if (alpha[i] > alpha[j])
                {
                    char y = alpha[i];
                    alpha[i] = alpha[j];
                    alpha[j] = y;
                }
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c %d\n", alpha[i], count[i]);
        }
    }
    
    return 0;
}