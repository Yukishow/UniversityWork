char *trim(char dest[])
{
    int ptr = 0, count = 0;
    for (int i = 0; dest[i] != '\0'; i++)
    { //計算字串長度
        ptr++;
    }
    ptr--; //最後一個陣列編號為長度-1
           //判斷前面的空白字元
    while (dest[count] != '\0')
    {
        if (dest[count] == '\n' || dest[count] == '\t' || dest[count] == ' ')
            count++; //如果是就計數
        else
            break;
    }
    //判斷後面的空白字元
    while (dest[ptr] == '\n' || dest[ptr] == '\t' || dest[ptr] == ' ')
    {
        dest[ptr] = '\0'; //如果是就更改程結束符號
        ptr--;
    }
    //回傳的地址為原本的地址加上計數的數字才會是沒有空白字元的開頭
    return dest + count;
}