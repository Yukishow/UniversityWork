int G(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++)
        sum += i * i;
    sum += 3 * x;
    return sum;
}