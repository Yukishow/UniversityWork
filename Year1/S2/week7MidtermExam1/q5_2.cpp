// Soluation 2
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b and a != 0 and b != 0)
    {
        cout << floor(sqrt(b)) - floor(sqrt(a - 1)) << endl;
    }

    return 0;
}