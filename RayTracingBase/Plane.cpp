#include "Plane.h"

Plane::Plane(vec3 normal, vec3 point, Material *m): Object(m)
{
    this->n=normal/length(normal);
    this->d=-dot(n,point);
}

bool Plane::hit(const Ray &r, float t_min, float t_max, HitInfo &rec) const{
    float lambda;
    float prod=dot(r.dirVector(),this->n);
    float d;
    vec3 temp_point;
    vec3 dist_vec;
    if(abs(prod)<0.00000000001){
        return false;
    }
    lambda=-(this->d+dot(this->n,r.initialPoint()))/prod;
    temp_point=r.pointAtParameter(lambda);
    dist_vec=temp_point-r.initialPoint();
    d=length(dist_vec);
    if(t_min<d && d<t_max){
        rec.t = lambda;
        rec.p = temp_point;
        rec.normal = this->n;
        rec.mat_ptr = material;
        return true;
    }
    return false;
}
