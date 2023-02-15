// collision of two triangle
#include <bits/stdc++.h>
class Point
{
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double x, y;
};

class Triangle
{
public:
    Triangle(Point a, Point b, Point c)
    {
        point[0] = a;
        point[1] = b;
        point[2] = c;
    }
    double getArea()
    {
        double A = sqrt(pow(point[0].x - point[1].x, 2) + pow(point[0].y - point[1].y, 2));
        double B = sqrt(pow(point[1].x - point[2].x, 2) + pow(point[1].y - point[2].y, 2));
        double C = sqrt(pow(point[2].x - point[0].x, 2) + pow(point[2].y - point[0].y, 2));
        double S = (A + B + C) / 2;
        return sqrt(S * (S - A) * (S - B) * (S - C));
    }
    double Area(Point &P1, Point &P2, Point &P3)
    {
        double A = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
        double B = sqrt(pow(P1.x - P3.x, 2) + pow(P1.y - P3.y, 2));
        double C = sqrt(pow(P2.x - P3.x, 2) + pow(P2.y - P3.y, 2));
        double S = (A + B + C) / 2;
        return sqrt(S * (S - A) * (S - B) * (S - C));
    }
    // override operator* with one parameter which is also a object of Triangle and return true if two triangle collision, return false if not.
    // Two triangle collision if they overlap or share the same point or segment.
    bool operator+(Triangle &T)
    {
        for (int i = 0; i < 3; i++)
        {
            double sumArea = 0;
            sumArea += (Area(T.point[i], this->point[0], this->point[1]));
            sumArea += (Area(T.point[i], this->point[0], this->point[2]));
            sumArea += (Area(T.point[i], this->point[1], this->point[2]));
            if (sumArea == this->getArea())
                return 1;
        }
        for (int i = 0; i < 3; i++)
        {
            double sumArea = 0;
            sumArea += (Area(this->point[i], T.point[0], T.point[1]));
            sumArea += (Area(this->point[i], T.point[0], T.point[2]));
            sumArea += (Area(this->point[i], T.point[1], T.point[2]));
            if (sumArea == T.getArea())
                return 1;
        }
        return 0;
    }

private:
    Point point[3];
};

int main()
{
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a2(x1, y1), b2(x2, y2), c2(x3, y3);
    Triangle t1(a, b, c), t2(a2, b2, c2);
    std::cout << t1 + t2 << std::endl;
}