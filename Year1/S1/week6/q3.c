#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], str1[100];
    int n, m, D = 0;
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        str1[i] = toupper(str[i]);
    }
    if (n % 2 == 0)
    {
        m = n / 2;
        for (int i = 0; i < m; i++)
        {
            if (str1[i] == str1[n - 1 - i])
                D++;
        }
        if (D == m)
            printf("%s is a palindrome.", str);
        else
            printf("%s is not a palindrome.", str);
    }
    else
    {
        m = (n - 1) / 2;
        for (int i = 0; i < m; i++)
        {
            if (str1[i] == str1[n - 1 - i])
                D++;
        }
        if (D == m)
            printf("%s is a palindrome.", str);
        else
            printf("%s is not a palindrome.", str);
    }

    return 0;
}