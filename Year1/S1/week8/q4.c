#include <stdio.h>
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int sid1[m], studentID[m], courseID[m];
    int sid2;
    double score;
    double grades[n];
    int grades_count[n];
    int number = 0;
    for (int i = 0; i < n; i++) //初始化矩陣
        grades[i] = 0;
    for (int i = 0; i < n; i++) //初始化矩陣
        grades_count[i] = 0;
    // sid1 儲存編號 studentID 儲存學號 courseID 儲存課程編號
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &sid1[i], &studentID[i], &courseID[i]);
        int isStuNotExist = 1; //先假設此學生還沒登記過變數設1
        for (int j = 0; j < i; j++)
        { //在判斷學生是否有登記過
            if (studentID[j] == studentID[i])
            {
                isStuNotExist = 0; //如果有登記過則把變數變0
                break;
            }
        }
        number += isStuNotExist; //計算人數
    }
    // grades 儲存成績 grades_count 儲存成績個數
    for (int i = 0; i < n; i++)
    {
        scanf("%d%lf", &sid2, &score);
        for (int j = 0; j < n; j++)
        {
            if (sid2 == sid1[j])
            {                       //用迴圈找到與輸入編號相同的儲存編號
                grades[j] += score; //並將對應的成績加到對應的grades陣列
                grades_count[j]++;  //對應的grades_count陣列+1
            }
        }
    }
    int stuFailed[n];
    int fail = 0;
    for (int i = 0; i < n; i++)
    {
        if (grades[i] / grades_count[i] < 60)
        {
            int isFailedStuExist = 1; //先假設此學生不及格變數設1
            for (int j = 0; j < fail; j++)
            { //用迴圈判斷學生是否已經有不及格
                if (studentID[i] == stuFailed[j])
                {
                    isFailedStuExist = 0; //如果有則將變數變0
                    break;
                }
            }
            if (isFailedStuExist == 1)
            { //如果學生沒有重複
                //則將學號存入stuFailed陣列 以利於下次判斷學生是否已經不及格
                stuFailed[fail] = studentID[i];
                fail++; //不及格人數+1
            }
        }
    }
    printf("%d %d", number, fail);

    return 0;
}