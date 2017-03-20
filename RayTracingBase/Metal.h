#ifndef METAL_H
#define METAL_H

#include "Material.h"

class Metal : public Material
{
public:
    Metal(const vec3& diffuse, const vec3& ambient, const vec3& specular, float shiness);
    float fuzzy;

    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const;
};

#endif // METAL_H
