#include <stdio.h>
int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int a[x][y];
    int m, n, p;
    //初始化矩陣
    for (int i = 0; i < x; i++) 
        for (int j = 0; j < y; j++)
            a[i][j] = 0;
    for (int i = 1; i <= z; i++)
    { //傳值給對應的矩陣位置
        scanf("%d%d%d", &m, &n, &p);
        a[m][n] = p;
    }
    for (int i = 0; i < x; i++)
    { //輸出矩陣的值
        for (int j = 0; j < y; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}