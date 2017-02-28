#include "Plane.h"

Plane::Plane(vec3 normal, vec3 point, Material *m): Object(m)
{
    this->n=normal/length(normal);
    this->d=-dot(n,point);
}

bool Plane::hit(const Ray &r, float t_min, float t_max, HitInfo &rec) const{
    //Producto escalar del vector normal del plano y del vector director del rayo
    //Si la multiplicacion da 0, los vectores son perpendiculares, por tanto el plano y el rayo son paralelos
    //o el rayo esta contenido en el plano. En ambos casos, consideramos que no hay hit
    float prod=dot(r.dirVector(),this->n);
    if(abs(prod)<0.00000000001){
        return false;
    }
    float lambda=-(this->d+dot(this->n,r.initialPoint()))/prod;
    vec3 temp_point=r.pointAtParameter(lambda);
    if(t_min<lambda && lambda<t_max){
        rec.t = lambda;
        rec.p = temp_point;
        rec.normal = this->n;
        rec.mat_ptr = material;
        return true;
    }
    return false;
}
