#include "Cube.h"

Cube::Cube(vec3 i,vec3 e, Material *m) : Object(m){
    this->p1=i;
    this->p2=e;
}

bool Cube::hit(const Ray& r, float t_min, float t_max, HitInfo& rec)const{
    float tnear =0.000000000001;
    float tfar = 11111111111111;
    vec3 n = r.dirVector()/length(r.dirVector());
    if(n.x==0){//Rayo paralelo
        if(r.initialPoint().x < p1.x || r.initialPoint().x > p2.x){
            return false;
        }
    }
    else{//Rayo no paralelo
        float t1 = (p1.x-r.initialPoint().x)/n.x;
        float t2 = (p2.x-r.initialPoint().x)/n.x;


        if(t1>t2){
            float temp = t1;
            t1 = t2;
            t2 = temp;
        }
        if(t1>tnear){tnear=t1;}
        if(t2<tfar){tfar=t2;}

    }
    if(tnear > tfar){return false;}
    if(tfar < 0){return false;}

    return true;



}
