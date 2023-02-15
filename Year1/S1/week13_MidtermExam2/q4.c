void removeChar(char *source, char *target)
{
    for (int i = 0; i < strlen(source); i++)
    {
        for (int j = 0; j < strlen(target); j++)
        {
            if (source[i] == target[j])
            {
                for (int k = i; k < strlen(source); k++)
                {
                    source[k] = source[k + 1];
                }
                i--;
            }
        }
    }
}