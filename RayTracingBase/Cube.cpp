#include "Cube.h"

Cube::Cube(vec3 i,vec3 e, Material *m) : Object(m){
    this->p1=i;
    this->p2=e;
}

bool Cube::hit(const Ray& r, float t_min, float t_max, HitInfo& rec)const{
    ve3 n = r.dirVector()/length(r.dirVector());

}
