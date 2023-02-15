// Intersection of two segment using coordinate(1)
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
class Segment // using two Coordinate to represent a segment
{
public:
    Segment(Coordinate _a, Coordinate _b)
    {
        a = _a;
        b = _b;
    }
    // return the intersection with another segment if exist, return NULL when there are no intersection.
    Coordinate *getIntersection(Segment s)
    { // 計算與另一條線的交點，如果只有一個交點就回傳該交點，其他狀況則回傳NULL
        float m1, m2, slope1, slope2, b1, b2;
        float X, Y;
        int testX1 = 0, testY1 = 0, testX2 = 0, testY2 = 0;
        // m1 m2判斷是否為鉛直線
        m1 = b.getX() - a.getX();
        m2 = s.b.getX() - s.a.getX();
        if (m1 == 0 and m2 == 0)
        {
            return NULL;
        }
        else if (m1 == 0 and m2 != 0)
        {
            slope2 = (s.b.getY() - s.a.getY()) / (float)(s.b.getX() - s.a.getX());
            b2 = s.a.getY() - slope2 * s.a.getX();
            X = a.getX();
            Y = slope2 * X + b2;
            if (Y >= a.getY() and Y <= b.getY())
                testY1 = 1;
            if (Y >= b.getY() and Y <= a.getY())
                testY1 = 1;
            if (Y >= s.a.getY() and Y <= s.b.getY())
                testY2 = 1;
            if (Y >= s.b.getY() and Y <= s.a.getY())
                testY2 = 1;
            if (X >= s.a.getX() and X <= s.b.getX())
                testX2 = 1;
            if (X >= s.b.getX() and X <= s.a.getX())
                testX2 = 1;
            if (testY1 == 1 and testX2 == 1 and testY2 == 1)
            {
                Coordinate *P = new Coordinate(X, Y);
                return P;
            }
            else
            {
                return NULL;
            }
        }
        else if (m1 != 0 and m2 == 0)
        {
            slope1 = (b.getY() - a.getY()) / (float)(b.getX() - a.getX());
            b1 = a.getY() - slope1 * a.getX();
            X = s.a.getX();
            Y = slope1 * X + b1;
            if (Y >= a.getY() and Y <= b.getY())
                testY1 = 1;
            if (Y >= b.getY() and Y <= a.getY())
                testY1 = 1;
            if (Y >= s.a.getY() and Y <= s.b.getY())
                testY2 = 1;
            if (Y >= s.b.getY() and Y <= s.a.getY())
                testY2 = 1;
            if (X >= a.getX() and X <= b.getX())
                testX1 = 1;
            if (X >= b.getX() and X <= a.getX())
                testX1 = 1;
            if (testX1 == 1 and testY1 == 1 and testY2 == 1)
            {
                Coordinate *P = new Coordinate(X, Y);
                return P;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            slope1 = (b.getY() - a.getY()) / (float)(b.getX() - a.getX());
            b1 = a.getY() - slope1 * a.getX();
            slope2 = (s.b.getY() - s.a.getY()) / (float)(s.b.getX() - s.a.getX());
            b2 = s.a.getY() - slope2 * s.a.getX();
            if (slope1 == slope2)
            {
                return NULL;
            }
            else
            {
                X = (b2 - b1) / (slope1 - slope2);
                Y = slope1 * X + b1;
                if (Y >= a.getY() and Y <= b.getY())
                    testY1 = 1;
                if (Y >= b.getY() and Y <= a.getY())
                    testY1 = 1;
                if (Y >= s.a.getY() and Y <= s.b.getY())
                    testY2 = 1;
                if (Y >= s.b.getY() and Y <= s.a.getY())
                    testY2 = 1;
                if (X >= a.getX() and X <= b.getX())
                    testX1 = 1;
                if (X >= b.getX() and X <= a.getX())
                    testX1 = 1;
                if (X >= s.a.getX() and X <= s.b.getX())
                    testX2 = 1;
                if (X >= s.b.getX() and X <= s.a.getX())
                    testX2 = 1;
                if (testX1 == 1 and testY1 == 1 and testX2 == 1 and testY2 == 1)
                {
                    Coordinate *P = new Coordinate(X, Y);
                    return P;
                }
                else
                {
                    return NULL;
                }
            }
        }
    }

    float length()
    {
        return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
    }

    Coordinate getCoordinateA() { return a; }

    Coordinate getCoordinateB() { return b; }

private:
    Coordinate a, b;
};
