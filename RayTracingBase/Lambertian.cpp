#include "Lambertian.h"

Lambertian::Lambertian(const vec3& color):Material()
{
    diffuse = color;
}

Lambertian::~Lambertian()
{}

bool Lambertian::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const  {
    vec3 target = rec.p + rec.normal + this->RandomInSphere();
    scattered = Ray(rec.p, target-rec.p);
    color = diffuse;
    return true;
}

