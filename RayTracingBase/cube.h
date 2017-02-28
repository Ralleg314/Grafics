#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

class Cube : public Object
{
public:
        Cube(vec3 i, vec3 e, Material *m);
        bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
private:


};

#endif // CUBE_H
