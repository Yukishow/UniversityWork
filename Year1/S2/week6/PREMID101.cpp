#include <iostream>
using namespace std;
class F
{
public:
    F(int _a, int _b)
    {
        a = _a;
        b = _b;
    }
    int S(int x)
    {
        int sum = 0, n = x + 1;
        for (int i = 0; i <= x; i++)
        {
            sum += i;
        }
        return (this->a * sum + this->b * n);
    }
    int G(int x, int y)
    {
        int sum = 0, n = y - x + 1;
        for (int i = x; i <= y; i++)
        {
            sum += i;
        }
        return (this->a * sum + this->b * n);
    }

private:
    int a, b;
};
int main()
{
    int a, b, j;
    cin >> a >> b;
    F f(a, b);
    for (j = 0; j < 10; j++)
    {
        int x, y;
        cin >> x >> y;
        cout << f.S(x) << endl;
        cout << f.G(x, y) << endl;
    }
    
    return 0;
}