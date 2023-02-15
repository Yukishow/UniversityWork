// UVA 11150 Cola
#include <iostream>
using namespace std;
int main()
{
    int sum, n;
    while (cin >> n)
    {
        sum = n;
        while (n >= 3)
        {
            n -= 2;
            sum += 1;
        }
        if (n == 2)
        {
            sum++;
        }
        cout << sum << endl;
    }

    return 0;
}