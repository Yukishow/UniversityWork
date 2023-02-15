int F(int x, int y)
{
    if (x < y)
        return (3 * x + F(x + 1, y));
    if (x > y)
        return (2 * y + F(x, y + 1));
    if (x == y)
        return x * y;
}