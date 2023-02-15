// Square Number
// Soluation 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b and a != 0 and b != 0)
    {
        int count = 0;
        for (int i = a; i <= b; i++)
        {
            for (int j = 1; j <= (i + 1) / 2; j++)
            {
                if (j * j == i)
                    count++;
                if (j * j > i)
                    break;
            }
        }
        cout << count << endl;
    }

    return 0;
}