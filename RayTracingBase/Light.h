#ifndef LIGHT_H
#define LIGHT_H

#include <vector>

class Light
{
public:
    Light(vec3);
    vec3 ambient_color;
    vec3 diffuse_color;
    vec3 specular_color;
    vec3 position;

};

#endif // LIGHT_H
