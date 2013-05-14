#include "ObjectHandler.h"
#include "lib/Matrix.h"
#include "math.h"

Object ObjectHandler::translate(Object o, float dx, float dy, float dz) {
    Matrix identity(4,4);
    identity.setValue(1,0,0);
    identity.setValue(1,1,1);
    identity.setValue(1,2,2);
    identity.setValue(1,3,3);
    identity.setValue(dx,0,3);
    identity.setValue(dy,1,3);
    identity.setValue(dz,2,3);

    Point* points  = o.getPoints(true);
    for (int i=0; i<o.getPointsSize(); i++) {
        Matrix m(1,4);
        m.setValue(points[i].x,0,0);
        m.setValue(points[i].y,0,1);
        m.setValue(points[i].z,0,2);

        Matrix result = m * identity;
        points[i].x = result.getValue(0,0);
        points[i].x = result.getValue(0,1);
        points[i].x = result.getValue(0,2);

    }

    return Object(points, o.getPointsSize(), o.getStartPoint());

}
Object ObjectHandler::scale(Object o, float sx, float sy, float sz) {
    Matrix identity(4,4);
    identity.setValue(sx,0,0);
    identity.setValue(sy,1,1);
    identity.setValue(sz,2,2);
    identity.setValue(1,3,3);

    Point* points  = o.getPoints(true);
    for (int i=0; i<o.getPointsSize(); i++) {
        Matrix m(1,4);
        m.setValue(points[i].x,0,0);
        m.setValue(points[i].y,0,1);
        m.setValue(points[i].z,0,2);

        Matrix result = m * identity;
        points[i].x = result.getValue(0,0);
        points[i].x = result.getValue(0,1);
        points[i].x = result.getValue(0,2);

    }

    return Object(points, o.getPointsSize(), o.getStartPoint());
}
Object ObjectHandler::rotate(Object o, float angle, int axis) {
    float PI = 3.1415;
    angle = angle * PI / 180;
    Matrix identity(4,4);
    if (axis == 0) {
        identity.setValue(1,0,0);
        identity.setValue(cos(angle),1,1);
        identity.setValue(-1*sin(angle),1,2);
        identity.setValue(sin(angle),2,1);
        identity.setValue(cos(angle),2,2);
        identity.setValue(1,3,3);
    }

    Point* points  = o.getPoints(true);
    for (int i=0; i<o.getPointsSize(); i++) {
        Matrix m(1,4);
        m.setValue(points[i].x,0,0);
        m.setValue(points[i].y,0,1);
        m.setValue(points[i].z,0,2);

        Matrix result = m * identity;
        points[i].x = result.getValue(0,0);
        points[i].x = result.getValue(0,1);
        points[i].x = result.getValue(0,2);

    }

    return Object(points, o.getPointsSize(), o.getStartPoint());
}
