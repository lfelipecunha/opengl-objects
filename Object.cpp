#include "Object.h"
#include "stdlib.h"

Object::Object(Point *initial) {
    setStartPoint(initial);
    points = (Point*)malloc(sizeof(Point*)*2);
    points[0] = Point(1,1,0);
    points[1] = Point(1,5,0);
    pointsSize = 2;
}

Object::Object(Point* p, int pS, Point *initial) {
    setStartPoint(initial);
    points = p;
    pointsSize = pS;
}

int Object::getPointsSize() {
    return pointsSize;
}

void Object::setStartPoint(Point *p) {
    startPoint = p;
}

Point* Object::getStartPoint() {
    return startPoint;
}

Point* Object::getPoints() {
    return getPoints(false);
}

Point* Object::getPoints(bool initial) {
    Point* result = (Point*) malloc(sizeof(Point*)*getPointsSize());
    for (int i=0; i<pointsSize; i++) {
        if (!initial) {
            result[i] = points[i] + startPoint;
        } else {
            result[i] = points[i];
        }
    }

    return result;
}
