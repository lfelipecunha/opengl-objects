class Point {
    public:
        float x,y,z;
        Point(float x, float y, float z);
        Point operator+(const Point* p) const;
};
