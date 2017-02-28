#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

class Cube : public Object
{
public:
    Cube();
    ~Cube() {}
    bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
private:
    vec3 p1;
    vec3 p2;
};

#endif // CUBE_H
