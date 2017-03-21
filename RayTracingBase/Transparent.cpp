#include "Transparent.h"

Transparent::Transparent(const vec3& diffuse, const vec3& ambient, const vec3& specular, float shiness,float ref)
{
    this->diffuse=vec3(1.0f)-diffuse;
    this->specular=specular;
    this->ambient=ambient;
    this->opacity=1;
    this->shiness=shiness;
    this->ref=ref;
}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const  {
    vec3 N;
    if(dot(r_in.direction,rec.normal)>0){
        N=-normalize(rec.normal);
    }else{
        N=normalize(rec.normal);
    }
    float c_theta=dot(-normalize(r_in.direction),normalize(N));
    if(1-pow(this->ref,2)*(1-pow(c_theta,2))>=0){
        scattered=Ray(rec.p,-(this->ref*r_in.direction)+N*float((this->ref)*c_theta - sqrt(1-pow(this->ref,2)*(1-pow(c_theta,2)))));
    }else{
        vec3 target = r_in.direction - float(2)*rec.normal*dot(r_in.direction,rec.normal);
        scattered = Ray(rec.p, target);
    }
    color = diffuse;
    return true;
}
