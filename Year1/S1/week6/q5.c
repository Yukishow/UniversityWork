#include <stdio.h>
#include <math.h>
int main()
{
    int c, n, x, y, ymin = 0, m = 0;
    float sum = 0, x1;
    int a[100], b[100]; // a陣列代表X軸的值 b陣列代表Y軸的值
    scanf("%d", &c);    //輸入例數
    float size[c];      //開一個大小為總例數的陣列(存放各別答案)
    for (int i = 1; i <= c; i++)
    {
        scanf("%d", &n); //輸入座標總數
        for (int j = 0; j < n; j++)
        {
            scanf("%d%d", &a[j], &b[j]); //輸入座標
        }
        for (int i = 0; i < n; i++) //將X軸的值由大到小排列並將對應Y值一起排列
            for (int j = 0; j < n; j++)
                if (a[j] < a[i])
                {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                    temp = b[j];
                    b[j] = b[i];
                    b[i] = temp;
                }
        for (int i = 0; i < (n - 1); i++)
        {
            if (b[i + 1] > ymin)
            {                                            //如果y座標大於ymin則要計算斜邊 小於就不會被夕陽照到不用算(初始ymin=0邊大小)
                x = -(a[i + 1] - a[i]);                  // x軸的邊長(因為是由小減大所以加負號)
                y = (b[i + 1] - ymin);                   // y軸的邊長
                x1 = (float)(x * y) / (b[i + 1] - b[i]); //找出對應相似三角形的x軸邊長
                sum += sqrt((x1 * x1) + (y * y));        //算出斜邊並加入sum
                ymin = b[i + 1];                         //更新ymin
            }
        }
        size[m] = sum; //將各別sum值存入
        m++;
        // printf("%.2f\n",sum);
        sum = 0;  //重製初始條件
        ymin = 0; //重製初始條件
    }
    for (int i = 0; i < c; i++) //輸出各別的sum值
        printf("%.2f\n", size[i]);

    return 0;
}