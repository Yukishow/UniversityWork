#include <stdio.h>
#include <string.h>
void swap(char *str1, char *str2)
{
    char temp[55];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
int main()
{
    char str[100][55];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
                swap(str[i], str[j]);
        }
    }
    for (int i = 0; i < n; i++)
        printf("%s\n", str[i]);

    return 0;
}