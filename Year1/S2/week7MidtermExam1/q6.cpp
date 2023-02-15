// UVA 10050 Hartal
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, day;
    int parties[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> day >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> parties[j];
        }
        int test[3650] = {0};
        for (int j = 0; j < m; j++)
        {
            for (int k = 1; k <= day; k++)
            {
                if (k % parties[j] == 0 and k % 7 != 0 and k % 7 != 6)
                    test[k - 1] = 1;
            }
        }
        int count = 0;
        for (int j = 0; j < day; j++)
        {
            if (test[j] == 1)
                count++;
        }
        cout << count << endl;
    }

    return 0;
}