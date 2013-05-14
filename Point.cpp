#include "Point.h"

Point::Point(float x, float y, float z) {
    Point::x = x;
    Point::y = y;
    Point::z = z;
}

Point Point::operator+(const Point* p) const {
    Point actual = *this;
    Point result(actual.x, actual.y, actual.z);
    result.x += p->x;
    result.y += p->y;
    result.z += p->z;

    return result;
}
