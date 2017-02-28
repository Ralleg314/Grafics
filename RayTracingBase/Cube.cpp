#include "Cube.h"

Cube::Cube(vec3 i,vec3 e, Material *m) : Object(m){
    this->p1=i;
    this->p2=e;
}

bool Cube::hit(const Ray& r, float t_min, float t_max, HitInfo& rec)const{
    vec3 n = cross(this->p2-this->p1)/length(cross(this->p2-this->p1));
    float prod=dot(r.dirVector(),n);
    if(abs(prod)<0.00000000001){
        return false;
    }

}
