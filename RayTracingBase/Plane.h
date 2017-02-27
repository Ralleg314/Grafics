#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

class Plane: public Object
{
public:
    Plane(vec3, vec3, Material*);
    bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
private:
    vec3 n;
    float d;
};

#endif // PLANE_H
