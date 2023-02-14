#include <stdio.h>
int main()
{
    int H, up, down, S, day = 0;
    scanf("%d%d%d", &H, &up, &down);
    if (down >= up && up < H)
        printf("-1");
    if (down >= up && up >= H)
        printf("1");
    if (up > down)
    {
        while (1)
        {
            S = S + up;
            day++;
            if (S >= H)
            {
                printf("%d", day);
                break;
            }
            S = S - down;
        }
    }
    
    return 0;
}