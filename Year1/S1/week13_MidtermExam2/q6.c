#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    int ans = 0, temp = 0;
    char sign = '+';
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            continue;
        else if (str[i] >= '0' && str[i] <= '9')
        {
            temp *= 10;
            temp += str[i] - '0';
        }
        else
        {
            if (sign == '+')
                ans += temp;
            else
                ans -= temp;
            temp = 0;
            sign = str[i];
        }
    }
    if (sign == '+')
        ans += temp;
    else
        ans -= temp;
    printf("%d", ans);
    
    return 0;
}