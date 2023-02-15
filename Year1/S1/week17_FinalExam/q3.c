#include <stdio.h>
#include <string.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    double rate[100] = {0};
    double grades[100] = {0};
    for (int i = 0; i < m; i++)
    {
        scanf("%lf", &rate[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double temp;
            scanf("%lf", &temp);
            grades[i] += temp * (rate[j] / 100);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int ans;
        ans = (grades[i] + 0.5);
        printf("%d\n", ans);
    }

    return 0;
}