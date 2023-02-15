// Overloading operators
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
    int getX() const
    {
        return x;
    }
    int getY() const
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
    void showCoordInfo() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    bool operator>(const Coordinate &P)
    {
        return (this->x > P.x && this->y > P.y);
    }
    bool operator<(const Coordinate &P)
    {
        return (this->x < P.x && this->y < P.y);
    }
    Coordinate operator+(const Coordinate &P)
    {
        int X, Y;
        X = this->x + P.x;
        Y = this->y + P.y;
        return Coordinate(X, Y);
    }
    Coordinate operator-(const Coordinate &P)
    {
        int X, Y;
        X = this->x - P.x;
        Y = this->y - P.y;
        return Coordinate(X, Y);
    }
    bool operator==(const Coordinate &P)
    {
        return (this->x == P.x && this->y == P.y);
    }
    Coordinate &operator=(const Coordinate &P)
    {
        this->x = P.x;
        this->y = P.y;
        return *this;
    }

private:
    int x, y;
};