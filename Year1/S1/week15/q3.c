#include <stdio.h>
#include <string.h>
int Winner(char board[][20], int x, int y)
{
    char temp = board[x][y];
    int count = 1;
    int dx = 1, dy = 1; //方便計算往上下左右
    //往下找是否有五個相連
    while (board[x + dx][y] == temp && count < 5)
    {
        dx++;
        count++;
        //如果找到五個回傳1
        if (count == 5)
        {
            return 1;
        }
    }
    count = 1, dx = 1; //重置條件
    //往右找是否有五個相連
    while (board[x][y + dy] == temp && count < 5)
    {
        dy++;
        count++;
        //如果找到五個回傳1
        if (count == 5)
        {
            return 1;
        }
    }
    count = 1, dy = 1; //重置條件
    //往右上找是否有五個相連
    while (board[x - dx][y + dy] == temp && count < 5)
    {
        dx++;
        dy++;
        count++;
        //如果找到五個回傳1
        if (count == 5)
        {
            return 1;
        }
    }
    count = 1, dx = 1, dy = 1; //重置條件
    //往右下找是否有五個相連
    while (board[x + dx][y + dy] == temp && count < 5)
    {
        dx++;
        dy++;
        count++;
        //如果找到五個回傳1
        if (count == 5)
        {
            return 1;
        }
    }
    //如果沒有找到就回傳0
    return 0;
}
int main()
{
    char board[19][20];
    for (int i = 0; i < 19; i++)
    {
        scanf("%s", &board[i]);
    }
    int Owin = 0, Xwin = 0;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (board[i][j] == 'O')
            {
                Owin = Winner(board, i, j);
                //找到就離開迴圈
                if (Owin)
                {
                    break;
                }
            }
            else if (board[i][j] == 'X')
            {
                Xwin = Winner(board, i, j);
                //找到就離開迴圈
                if (Xwin)
                {
                    break;
                }
            }
        }
        //如果白子贏輸出並離開迴圈
        if (Owin)
        {
            printf("White");
            return 0;
        }
        //如果黑子贏輸出並離開迴圈
        else if (Xwin)
        {
            printf("Black");
            return 0;
        }
    }
    if (!Owin && !Xwin)
        printf("No winner");

    return 0;
}