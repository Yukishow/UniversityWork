int countChar(char str[], int type)
{
    int count = 0;
    if (type == 1)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (isalpha(str[i]))
            {
                count++;
            }
        }
        return count;
    }
    if (type == 2)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (isdigit(str[i]))
            {
                count++;
            }
        }
        return count;
    }
    if (type == 3)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (isalnum(str[i]))
            {
                count++;
            }
        }
        return strlen(str) - count;
    }
}