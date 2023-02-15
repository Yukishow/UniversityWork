//input/output with C++
#include <bits/stdc++.h>
using namespace std;
void out()
{
    char a;
    cin >> a;
    if (a == '.')
        return;
    out();
    cout << a;
}
int main()
{
    out();

    return 0;
}