#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++) // 輸入n*m的矩陣
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int left = 0, up = 0, down = n - 1, right = m - 1; //定義上下左右邊界
    int count = 0;                                     //計錄輸出幾次
    while (1)
    {
        for (int i = left; i <= right; i++)
        { // 向右輸出
            printf("%d ", a[up][i]);
            count++;
        }
        up++;               //輸出完更新上界
        if (count == n * m) //如果計數等於矩陣大小則跳出迴圈
            break;
        for (int i = up; i <= down; i++)
        { // 向下輸出
            printf("%d ", a[i][right]);
            count++;
        }
        right--;            //輸出完更新右界
        if (count == n * m) //如果計數等於矩陣大小則跳出迴圈
            break;
        for (int i = right; i >= left; i--)
        { // 向左輸出
            printf("%d ", a[down][i]);
            count++;
        }
        down--;             //輸出完更新下界
        if (count == n * m) //如果計數等於矩陣大小則跳出迴圈
            break;
        for (int i = down; i >= up; i--)
        { // 向上輸出
            printf("%d ", a[i][left]);
            count++;
        }
        left++;             //輸出完更新左界
        if (count == n * m) //如果計數等於矩陣大小則跳出迴圈
            break;
    }
    
    return 0;
}