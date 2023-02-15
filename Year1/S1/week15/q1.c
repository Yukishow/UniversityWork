#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ans(char *x)
{
    //回傳運算符號的位址
    // strpbrk函式只要找到任一目標字元就會回傳當下地址
    char *addsub = strpbrk(x, "+-"); //加減
    char *muldiv = strpbrk(x, "*/"); //乘除
    if (addsub != NULL)
    {
        // strrchr函式從後面找目標字元並回傳地址
        //因為要先執行左邊的運算所以後面開始找
        char *y;
        //判斷從後面先讀到'+'還是'-'
        if (strrchr(x, '+') > strrchr(x, '-'))
        {
            y = strrchr(x, '+');
        }
        else
        {
            y = strrchr(x, '-');
        }
        if (*y == '+')
        {
            *y = '\0';                  //去掉執行完畢的運算符號
            return ans(x) + ans(y + 1); //左字串+右字串
        }
        else
        {
            *y = '\0';                  //去掉執行完畢的運算符號
            return ans(x) - ans(y + 1); //左字串-右字串
        }
    }
    else if (muldiv != NULL)
    {
        char *y;
        //判斷從後面先讀到'*'還是'/'
        if (strrchr(x, '*') > strrchr(x, '/'))
        {
            y = strrchr(x, '*');
        }
        else
        {
            y = strrchr(x, '/');
        }
        if (*y == '*')
        {
            *y = '\0';                  //去掉執行完畢的運算符號
            return ans(x) * ans(y + 1); //左字串*右字串
        }
        else
        {
            *y = '\0';                  //去掉執行完畢的運算符號
            return ans(x) / ans(y + 1); //左字串/右字串
        }
    }
    return atoi(x); //字串轉換成整數
}
int main()
{
    char str[1000];
    gets(str);
    printf("%d", ans(str));

    return 0;
}