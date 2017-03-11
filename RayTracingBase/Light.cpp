#include "Light.h"

Light::Light(vec3 position, vec3 ambient,vec3 diffuse, vec3 specular, float a, float b,float c)
{
    this->position=position;
    this->ambient=ambient;
    this->diffuse=diffuse;
    this->specular=specular;
    this->a=a;
    this->b=b;
    this->c=c;
}


