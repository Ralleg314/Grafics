#include "Material.h"



Material::Material():
    diffuse(1.0f)
  {}

Material::Material(vec3 diffuse, vec3 specular, vec3 ambient, int shiness){
    this->diffuse=diffuse;
    this->specular=specular;
    this->ambient=ambient;
    this->opacity=1;
    this->shiness=shiness;
}

Material::Material(vec3 diffuse, vec3 specular, vec3 ambient, float opacity, int shiness){
    this->diffuse=diffuse;
    this->specular=specular;
    this->ambient=ambient;
    this->opacity=opacity;
    this->shiness=shiness;
}

Material::~Material()
{}

vec3 Material::RandomInSphere() const {
    vec3 p;
    do {
        p = 2.0f*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    } while (glm::length(p) >=  1.0f);
    return p;
}

