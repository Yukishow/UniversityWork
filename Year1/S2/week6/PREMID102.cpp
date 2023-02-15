#include <iostream>
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
    F operator+(F f)
    {
        int x, y;
        x = this->a + f.a;
        y = this->b + f.b;
        return F(x, y);
    }
    F operator-(F &f)
    {
        int x, y;
        x = this->a - f.a;
        y = this->b - f.b;
        return F(x, y);
    }

private:
    int a, b;
};
int main()
{
    int a, b, j, c, d;
    std::cin >> a >> b >> c >> d;
    F f(a, b), f2(c, d);
    for (j = 0; j < 10; j++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << (f + f2).S(x) << std::endl;
        std::cout << (f - f2).G(x, y) << std::endl;
    }
    
    return 0;
}