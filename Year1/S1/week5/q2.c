#include <stdio.h>
int main()
{
    int x, y, z, n, temp;
    while (scanf("%d%d%d", &x, &y, &z) != EOF)
    {
        //排列數字由小到大
        if (x > y)
        {
            temp = x;
            x = y;
            y = temp;
        }
        if (x > z)
        {
            temp = x;
            x = z;
            z = temp;
        }
        if (y > z)
        {
            temp = y;
            y = z;
            z = temp;
        }
        if (x == 0)
        {//如果最小的數是零則求後兩數的最大公因數
            for (int i = 1; i <= y; i++)
            //只需要檢查到較小數的最大因數
                if (y % i == 0 && z % i == 0) 
                //如果除於i都等於零則為他們的最大公因數
                    n = i;
        }
        else
        {// 求三數最大公因數
            for (int i = 1; i <= x; i++)
            //只需要檢查到較小數的最大因數
                if (x % i == 0 && y % i == 0 && z % i == 0) 
                //如果除於i都等於零則為他們的最大公因數
                    n = i;
        }
        printf("%d\n", n);
    }

    return 0;
}