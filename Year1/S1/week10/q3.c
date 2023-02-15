int merger(int *a, int *b, int *c)
{
    for (int i = 0; i < 5; i++)
    {
        *(c + i) = *(a + i);
        *(c + i + 5) = *(b + i);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (*(c + j) < *(c + i))
            {
                int temp = *(c + j);
                *(c + j) = *(c + i);
                *(c + i) = temp;
            }
        }
    }
}