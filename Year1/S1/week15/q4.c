#include <stdio.h>
#include <string.h>
int main()
{
    char num1[5], num2[5];
    scanf("%s%s", num1, num2);
    int Acount = 0, Bcount = 0;
    for (int i = 0; i < 4; i++)
    {
        if (num1[i] == num2[i])
        {
            Acount++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (num1[i] == num2[j] && i != j)
            {
                Bcount++;
            }
        }
    }
    printf("%d %d", Acount, Bcount);

    return 0;
}