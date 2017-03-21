#include "Metal.h"

Metal::Metal(const vec3& diffuse, const vec3& ambient, const vec3& specular, float shiness)
{
    this->diffuse=diffuse;
    this->specular=specular;
    this->ambient=ambient;
    this->opacity=1;
    this->shiness=shiness;
    this->fuzzy=0.0f;
}

bool Metal::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const  {
    vec3 target = r_in.direction - 2.0f*rec.normal*dot(r_in.direction,rec.normal);
    scattered = Ray(rec.p, target+this->fuzzy*RandomInSphere());
    color = specular;
    return true;
}
