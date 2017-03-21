#ifndef TRANSPARENT_H
#define TRANSPARENT_H


#include "Material.h"

class Transparent : public Material
{
public:
    Transparent(float refraction, vec3 Kt);
    float ref;
    vec3 Kt;
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const;
};

#endif // TRANSPARENT_H
