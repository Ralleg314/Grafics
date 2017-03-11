#ifndef LIGHT_H
#define LIGHT_H



class Light
{
public:
    Light(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float a, float b, float c);
private:
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float a;
    float b;
    float c;
};

#endif // LIGHT_H
