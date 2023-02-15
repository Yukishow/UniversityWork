#include <stdio.h>
#include <string.h>
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    char num1[1002], num2[1002];
    gets(num1);
    gets(num2);
    for (int i = 0; i < strlen(num1) / 2; i++)
    {
        swap(&num1[i], &num1[strlen(num1) - 1 - i]);
    }
    for (int i = 0; i < strlen(num2) / 2; i++)
    {
        swap(&num2[i], &num2[strlen(num2) - 1 - i]);
    }
    int a[1002], b[1002];
    int sum[1002];
    for (int i = 0; i < 1002; i++)
    {
        a[i] = 0;
        b[i] = 0;
        sum[i] = 0;
    }
    for (int i = 0; i < strlen(num1); i++)
    {
        a[i] = num1[i] - '0';
    }
    for (int i = 0; i < strlen(num2); i++)
    {
        b[i] = num2[i] - '0';
    }
    int upper = 0;
    for (int i = 0; i < 1002; i++)
    {
        sum[i] = a[i] + b[i] + upper;
        if (sum[i] >= 10)
        {
            sum[i] -= 10;
            upper = 1;
        }
        else
        {
            upper = 0;
        }
    }
    int n = 1001;
    while (sum[n] == 0)
    {
        n--;
    }
    // printf("%d\n",n);
    for (int i = n; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
    
    return 0;
}