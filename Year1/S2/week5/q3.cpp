// Area of Triangle
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    float x, y;
    bool operator==(Point &P)
    {
        return (this->x == P.x and this->y == P.y);
    }
};

class Segment
{
public:
    Segment(){}
    Segment(Point _a, Point _b)
    {
        a = _a;
        b = _b;
    }
    Point getPointA()
    {
        return a;
    }
    Point getPointB()
    {
        return b;
    }
    void setPoint(Point _a, Point _b)
    {
        a = _a;
        b = _b;
    }
    float getLength()
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    float getDistance(const Point &a);
    float getslope()
    {
        return (a.y - b.y) / (a.x - b.x);
    }

private:
    Point a, b;
};

class Triangle
{
public:
    Triangle(Segment s1, Segment s2, Segment s3)
    {
        seg1 = s1;
        seg2 = s2;
        seg3 = s3;
    }
    static bool isTriangle(Segment, Segment, Segment);
    float getArea();

private:
    Segment seg1, seg2, seg3;
};
float Segment::getDistance(const Point &a)
{   // the height from point to the line which segment lie on.
    // using math equation |ax+by+c|/sqrt(a*a+b*b)
    Point V;
    V.x = this->b.x - this->a.x;
    V.y = this->b.y - this->a.y;
    float c;
    c = V.x * this->a.x - V.y * this->a.y;
    float molecular, denominator;
    molecular = abs(V.x * a.x - V.y * a.y + c);
    denominator = sqrt((V.x * V.x) + (V.y * V.y));
    return molecular / denominator;
}
bool Triangle::isTriangle(Segment L1, Segment L2, Segment L3)
{
    Point test[6];
    test[0] = L1.getPointA();
    test[1] = L1.getPointB();
    test[2] = L2.getPointA();
    test[3] = L2.getPointB();
    test[4] = L1.getPointA();
    test[5] = L3.getPointB();
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (test[i] == test[j] and i != j)
            {
                count++;
            }
        }
    }
    if (count != 6)
        return 0;
    else
        return 1;
}
float Triangle::getArea()
{
    float s1 = seg1.getLength(), s2 = seg2.getLength(), s3 = seg3.getLength();
    float s = (s1 + s2 + s3) / 2;
    return pow((s * (s - s1) * (s - s2) * (s - s3)), 0.5);
}