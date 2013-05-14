#include "Point.h"
class Object {
    public:
        Object(Point *p);
        Object(Point* p, int pS, Point *initial);
        Point* getPoints();
        Point* getPoints(bool initial);
        int getPointsSize();
        void setStartPoint(Point *p);
        Point* getStartPoint();


    protected:
        Point* points;
        int pointsSize;
        Point *startPoint;

};
