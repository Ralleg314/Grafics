#include "Cube.h"

Cube::Cube(vec3 i,vec3 e, Material *m) : Object(m){
    this->p1=i;
    this->p2=e;
}

bool Cube::hit(const Ray& r, float t_min, float t_max, HitInfo& rec)const{
    float tnear = -std::numeric_limits<float>::infinity();
    float tfar = std::numeric_limits<float>::infinity();
    float t1,t2,temp;
    vec3 n = normalize(r.dirVector());
    vec3 norm;
    //Check X planes
    if(n.x==0){//Rayo paralelo
        if(r.initialPoint().x < p1.x || r.initialPoint().x > p2.x){
            return false;
        }
    }else{//Rayo no paralelo
        t1 = (p1.x-r.initialPoint().x)/n.x;
        t2 = (p2.x-r.initialPoint().x)/n.x;


        if(t1>t2){
            temp = t1;
            t1 = t2;
            t2 = temp;
        }

        if(t1>tnear)
            tnear=t1;

        if(t2<tfar)
            tfar=t2;

        if(tnear>tfar)
            return false;

        if(tfar<0)
            return false;

        norm=vec3(1,0,0);

    }

    //Check Y planes
    if(n.y==0){//Rayo paralelo
        if(r.initialPoint().y < p1.x || r.initialPoint().y > p2.y){
            return false;
        }
    }else{//Rayo no paralelo
        t1 = (p1.y-r.initialPoint().y)/n.y;
        t2 = (p2.y-r.initialPoint().y)/n.y;


        if(t1>t2){
            temp = t1;
            t1 = t2;
            t2 = temp;
        }

        if(t1>t2){
            temp = t1;
            t1 = t2;
            t2 = temp;
        }

        if(t1>tnear)
            tnear=t1;

        if(t2<tfar)
            tfar=t2;

        if(tnear>tfar)
            return false;

        if(tfar<0)
            return false;

        norm=vec3(0,1,0);
    }

    //Check Z planes
    if(n.z==0){//Rayo paralelo
        if(r.initialPoint().z < p1.z || r.initialPoint().z > p2.z){
            return false;
        }
    }else{//Rayo no paralelo
        t1 = (p1.z-r.initialPoint().z)/n.z;
        t2 = (p2.z-r.initialPoint().z)/n.z;


        if(t1>t2){
            temp = t1;
            t1 = t2;
            t2 = temp;
        }

        if(t1>t2){
            temp = t1;
            t1 = t2;
            t2 = temp;
        }

        if(t1>tnear)
            tnear=t1;

        if(t2<tfar)
            tfar=t2;

        if(tnear>tfar)
            return false;

        if(tfar<0)
            return false;

        norm=vec3(0,0,1);
    }
    if(tnear>0){
        vec3 p=r.pointAtParameter(tnear);
        rec.t = tnear;
        rec.p = p;
        rec.normal = norm;
        rec.mat_ptr = material;
    }else{
        vec3 p=r.pointAtParameter(tfar);
        rec.t = tfar;
        rec.p = p;
        rec.normal = norm;
        rec.mat_ptr = material;
    }
    return true;



}
