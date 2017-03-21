#include "Transparent.h"

Transparent::Transparent(float ref, vec3 Kt)
{
    this->ref=1.0f/ref;
    this->Kt=Kt;
}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& scattered) const  {
    float ref_temp;
    vec3 R=normalize(r_in.direction);
    float c_theta=dot(R,rec.normal);//Dado que ambos son unitarios, no necesitamos dividir entre su modulo
    if(1-(pow(ref_temp,2)*(1-pow(c_theta,1)))>0){
        vec3 N;
        if(dot(R,rec.normal)>0){
            N=-rec.normal;
            ref_temp=1.0f/this->ref;
        }else{
            N=rec.normal;
            ref_temp=this->ref;
        }
        vec3 target = refract(R, N, ref_temp);
        scattered=Ray(rec.p,target);
        color = this->Kt;
    }else{
        vec3 target = reflect(r_in.direction, rec.normal);
        scattered = Ray(rec.p, target);
        color = vec3(1.0f) - this->Kt;
    }
    return true;
}
