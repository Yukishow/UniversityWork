//Solution 2
#include <stdio.h>
char maze[150][150];
int n;
void judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return;
    else if (maze[x][y] == 0)
    {
        maze[x][y] = 2;
        judge(x - 1, y);
        judge(x + 1, y);
        judge(x, y - 1);
        judge(x, y + 1);
        return;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    judge(0, 0);
    if (maze[n - 1][n - 1] == 2)
        printf("Yes");
    else
        printf("No");

    return 0;
}