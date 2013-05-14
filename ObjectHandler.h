#include "Object.h"

class ObjectHandler {
    public:
        static Object translate(Object o, float dx, float dy, float dz);
        static Object scale(Object o, float sx, float sy, float sz);
        static Object rotate(Object o, float angle, int axis);
};
