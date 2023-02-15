//one
char *mystrcat(char *dest, char *src)
{
    int n = 0;
    while (dest[n] != '\0')
    {
        n++;
    }
    int i = 0;
    for (; src[i] != '\0'; i++)
    {
        dest[n + i] = src[i];
    }
    dest[n + i] = '\0';
    return dest;
}
//two
char *mystrncat(char *dest, char *src, int n)
{
    int N = 0;
    while (dest[N] != '\0')
    {
        N++;
    }
    int i = 0;
    for (; i < n; i++)
    {
        dest[N + i] = src[i];
    }
    dest[N + i] = '\0';
    return dest;
}