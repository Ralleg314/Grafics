#include "Transparent.h"

Transparent::Transparent(float ref, vec3 Kt)
{
    this->ref=1.0f/ref;
    this->Kt=Kt;
}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const  {
    vec3 N;
    if(dot(r_in.direction,rec.normal)>0){
        N=-rec.normal;
    }else{
        N=rec.normal;
    }
    float c_theta=dot(-r_in.direction,N)/(length(r_in.direction)*length(N));
    if(1-(pow(this->ref,2)*(1-pow(c_theta,2)))>=0){
        vec3 target = refract(r_in.direction, N, ref);
        scattered=Ray(rec.p,target);
        color = this->Kt;
    }else{
        vec3 target = reflect(r_in.direction, N);
        scattered = Ray(rec.p, target);
        color = vec3(1.0f) - this->Kt;
    }
    return true;
}
