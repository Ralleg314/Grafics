#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"

class Triangle: public Object
{
public:
    Triangle(vec3,vec3,vec3, Material *m);
    ~Triangle() {}
    bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
private:
    vec3 A;
    vec3 B;
    vec3 C;
};

#endif // TRIANGLE_H
