//Solution 1
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int maze[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &maze[i][j]); //建立迷宮
    }
    // 0代表可以走 1代表障礙物 2代表走過
    maze[0][0] = 2;
    int visit = 1;
    while (visit == 1)
    { //利用迴圈走迷宮 判斷是否會走到出口
        visit = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (maze[x][y] == 2)
                {
                    if (y < n - 1 && maze[x][y + 1] == 0)
                    { //往右
                        maze[x][y + 1] = 2;
                        visit = 1;
                    }
                    else if (x < n - 1 && maze[x + 1][y] == 0)
                    { //往下
                        maze[x + 1][y] = 2;
                        visit = 1;
                    }
                    else if (y > 0 && maze[x][y - 1] == 0)
                    { //往左
                        maze[x][y - 1] = 2;
                        visit = 1;
                    }
                    else if (x > 0 && maze[x - 1][y] == 0)
                    { //往上
                        maze[x - 1][y] = 2;
                        visit = 1;
                    }
                }
            }
        }
    }
    if (maze[n - 1][n - 1] == 2) //如果陣列出口值為2則代表有走過
        printf("Yes");
    else
        printf("No");
        
    return 0;
}