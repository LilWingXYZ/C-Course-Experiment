#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <cmath>

class Point {
public:
    Point(double x = 0, double y = 0, double distance = 0) :
            x(x), y(y), distance(distance) {
    }
    void print();
    void distanceTo();
    bool operator >(Point &point);
    ~Point() {}
private:
    double x;
    double y;
    double distance;
};

void Point::distanceTo() {
    distance = sqrt(x * x + y * y);
}

bool Point::operator >(Point &point) {
    if (this -> distance > point.distance)
        return true;
    else
        return false;
}

#endif // POINT_H_INCLUDED
