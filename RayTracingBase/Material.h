#ifndef MATERIAL_H
#define MATERIAL_H


#include "Ray.h"
#include "Hitable.h"

// Classe abstracte Material. Totes les seves filles hauran de definir el metode abstracte sccater
class Material
{
public:

    Material();
    Material(vec3, vec3, vec3, int);
    Material(vec3, vec3, vec3, float, int);
    ~Material();

    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const = 0;

    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float opacity;
    int shiness;

protected:
    vec3 RandomInSphere() const;
};

#endif // MATERIAL_H
