//one
char *replace(char *source, char *pattern, char *replacement)
{
    //計算要被換的字串長度
    int pattern_l = strlen(pattern);
    //計算替換字串的長度
    int replacement_l = strlen(replacement);
    //找到要被換的字串開頭位置
    char *ret;
    for (int i = 0; source[i] != '\0'; i++)
    {
        if (source[i] == pattern[0])
        {
            int test = 1;
            for (int j = i, k = 0; k < pattern_l; j++, k++)
            {
                if (source[j] != pattern[k])
                {
                    test = 0;
                    break;
                }
            }
            if (test == 1)
            {
                ret = &source[i];
                break;
            }
        }
    }
    //另外要找到原字串中被替換後的剩餘字串開頭
    //為要被換的字串開頭位置加要被換的字串長度
    //並暫存於temp字串
    char *str = ret + pattern_l;
    char temp[1000];
    // strcpy(temp,str);
    int i = 0;
    for (; str[i] != '\0'; i++)
    {
        temp[i] = str[i];
    }
    temp[i] = '\0';
    // start為要被替換的字元陣列開頭
    int start = ret - source;
    //用迴圈接替換字串
    for (i = 0; i < replacement_l; i++)
    {
        source[start] = replacement[i];
        start++;
    }
    //把暫存的字串接回去
    for (i = 0; temp[i] != '\0'; i++)
    {
        source[start] = temp[i];
        start++;
    }
    //最後補上結束符號
    source[start] = '\0';
    return source;
}
//two
char *replaceAll(char *source, char *pattern, char *replacement)
{
    int pattern_l = strlen(pattern);
    int replacement_l = strlen(replacement);
    int find = 0; //判斷有沒有找到
                  //找到要被換的字串開頭位置
    char *ret;
    for (int i = 0; source[i] != '\0'; i++)
    {
        if (source[i] == pattern[0])
        {
            int test = 1;
            for (int j = i, k = 0; k < pattern_l; j++, k++)
            {
                if (source[j] != pattern[k])
                {
                    test = 0;
                    break;
                }
            }
            if (test == 1)
            {
                ret = &source[i];
                find = 1;
                break;
            }
        }
    }
    //找到要被換的字串開頭位置
    //如果找到進入迴圈
    while (find)
    {
        find = 0;
        char *str = ret + pattern_l;
        char temp[1000];
        // strcpy(temp,str);
        int i = 0;
        for (; str[i] != '\0'; i++)
        {
            temp[i] = str[i];
        }
        temp[i] = '\0';
        int start = ret - source;
        for (int i = 0; i < replacement_l; i++)
        {
            source[start] = replacement[i];
            start++;
        }
        for (int i = 0; temp[i] != '\0'; i++)
        {
            source[start] = temp[i];
            start++;
        }
        source[start] = '\0';
        for (int i = 0; source[i] != '\0'; i++)
        {
            if (source[i] == pattern[0])
            {
                int test = 1;
                for (int j = i, k = 0; k < pattern_l; j++, k++)
                {
                    if (source[j] != pattern[k])
                    {
                        test = 0;
                        break;
                    }
                }
                if (test == 1)
                {
                    ret = &source[i];
                    find = 1;
                    break;
                }
            }
        }
    }
    return source;
}