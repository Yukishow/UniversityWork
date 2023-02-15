int is(int x)
{
    if (x % 3 == 1 && x % 5 == 1 && x % 7 == 1)
        return 1;
    else
        return -1;
}