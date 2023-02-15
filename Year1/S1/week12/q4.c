#include <stdio.h>
#include <string.h>
int main()
{
    char str[100000];
    gets(str);                  //輸入字串
    int test = strlen(str) - 1; //找出字串長度(減一配合陣列)
    while (test >= 0)
    { //從後面開始找空白
        if (str[test] == ' ')
        { //找到空白利用迴圈輸出字串(i加一是為了找到空白的下一個字元)
            for (int i = test + 1; str[i] != '\0' && str[i] != ' '; i++)
            {
                printf("%c", str[i]);
            }
            printf(" "); //印出字串後要補空白
        }
        else if (test == 0)
        { //因為第一個字串前面沒有空白所以要特別設條件讓他印出來
            for (int i = test; str[i] != '\0' && str[i] != ' '; i++)
            {
                printf("%c", str[i]);
            }
        }
        test--;
    }

    return 0;
}