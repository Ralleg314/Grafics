#ifndef TRANSPARENT_H
#define TRANSPARENT_H


#include "Material.h"

class Transparent : public Material
{
public:
    Transparent(const vec3& diffuse, const vec3& ambient, const vec3& specular, float shiness);

    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const;
};

#endif // TRANSPARENT_H
