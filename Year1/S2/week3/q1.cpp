// coordinate(1)
#include <bits/stdc++.h>
using namespace std;
class Coordinate
{
public:
    Coordinate()
    {
        x = 0;
        y = 0;
    }
    Coordinate(const Coordinate &obj)
    {
        x = obj.x;
        y = obj.y;
    }
    Coordinate(int _x, int _y)
    {
        setX(_x);
        setY(_y);
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setX(int val)
    {
        x = val;
    }
    void setY(int val)
    {
        y = val;
    }
    void showCoordInfo()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

private:
    int x, y;
};