#include <stdio.h>
void printfarray(int arr[][100], int left, int up, int down, int right)
{
    //離開條件(左邊>右邊 或 上>下)
    if (left > right || up > down)
    {
        return;
    }
    //往右
    for (int i = left; i <= right; i++)
    {
        printf("%d ", arr[up][i]);
    }
    up++;
    //往下
    for (int i = up; i <= down; i++)
    {
        printf("%d ", arr[i][right]);
    }
    right--;
    //往左
    for (int i = right; i >= left; i--)
    {
        printf("%d ", arr[down][i]);
    }
    down--;
    //往上
    for (int i = down; i >= up; i--)
    {
        printf("%d ", arr[i][left]);
    }
    left++;
    //重新進入函式
    printfarray(arr, left, up, down, right);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[100][100];
    //輸入n*m的矩陣
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    //定義上下左右邊界
    int left = 0, up = 0, down = n - 1, right = m - 1;
    printfarray(arr, left, up, down, right);

    return 0;
}