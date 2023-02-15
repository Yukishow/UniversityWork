// Geometric progression
#include <bits/stdc++.h>
using namespace std;
class F
{
private:
    double a, r;

public:
    F(double _a, double _r)
    {
        a = _a;
        r = _r;
    }
    double at(int x)
    {
        double ans = a;
        ans = a * pow(r, x);
        return ans;
    }
    double *S()
    {
        if (!(r < 1 and r > -1))
            return NULL;
        double *ans = new double;
        *ans = a / (1 - r);
        return ans;
    }
};
int main()
{
    int j, k;
    double a, r;
    cin >> a >> r;
    F f(a, r);
    for (k = 0; k < 3; k++)
        printf("%.2lf\n", f.at(k));
    double *s = f.S();
    if (s == NULL)
        printf("NULL\n");
    else
        printf("%.2lf\n", *s);
}