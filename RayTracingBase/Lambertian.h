#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material
{

public:
    Lambertian(const vec3& diffuse, const vec3& ambient, const vec3& specular, float shiness);
    virtual ~Lambertian();
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const;

};

#endif // LAMBERTIAN_H
