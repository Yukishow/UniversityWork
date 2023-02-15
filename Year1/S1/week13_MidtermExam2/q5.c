int *findMax(int *a, int *b)
{
    int *max = a;
    for (int *i = a; i < b; i++)
    {
        if (*i > *max)
            max = i;
    }
    return max;
}