#include "Cube.h"

Cube::Cube(vec3 i,vec3 e, Material *m) : Object(m){
    this->bounds[0]=i;
    this->bounds[1]=e;
}

bool Cube::hit(const Ray& r, float t_min, float t_max, HitInfo& rec)const{
    float tmin, tmax, txmin, txmax, tymin, tymax, tzmin, tzmax;
    vec3 invdir=1.0f/r.dirVector();
    int sign[3]={invdir.x<0,invdir.y<0,invdir.z<0};

    txmin = (bounds[sign[0]].x - r.initialPoint().x) * invdir.x;
    txmax = (bounds[1-sign[0]].x - r.initialPoint().x) * invdir.x;
    if(txmin>txmax){
        tmin=tmax;
        tmax=tmin;
    }else{
        tmin=txmin;
        tmax=txmax;
    }

    tymin = (bounds[sign[1]].y - r.initialPoint().y) * invdir.y;
    tymax = (bounds[1-sign[1]].y - r.initialPoint().y) * invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
    return false;
    if (tymin > tmin)
    tmin = tymin;
    if (tymax < tmax)
    tmax = tymax;

    tzmin = (bounds[sign[2]].z - r.initialPoint().z) * invdir.z;
    tzmax = (bounds[1-sign[2]].z - r.initialPoint().z) * invdir.z;

    if ((tmin > tzmax) || (tzmin > tmax))
    return false;
    if (tzmin > tmin)
    tmin = tzmin;
    if (tzmax < tmax)
    tmax = tzmax;

    if(t_min<tmin && tmin<t_max){
        vec3 p=r.pointAtParameter(tmin);
        rec.t = tmin;
        rec.p = p;
        rec.mat_ptr = material;
        if(tmin==txmin)
            rec.normal=vec3(1,0,0);
        else if(tmin==txmax)
            rec.normal=vec3(-1,0,0);
        else if(tmin==tymin)
            rec.normal=vec3(0,1,0);
        else if(tmin==tymax)
            rec.normal=vec3(0,-1,0);
        else if(tmin==tzmin)
            rec.normal=vec3(0,0,1);
        else if(tmin==tzmax)
            rec.normal=vec3(0,0,-1);
    }else if(t_min<tmax && tmax<t_max){
        vec3 p=r.pointAtParameter(tmax);
        rec.t = tmax;
        rec.p = p;
        rec.mat_ptr = material;
        if(tmax==txmin)
            rec.normal=vec3(1,0,0);
        else if(tmax==txmax)
            rec.normal=vec3(-1,0,0);
        else if(tmax==tymin)
            rec.normal=vec3(0,1,0);
        else if(tmax==tymax)
            rec.normal=vec3(0,-1,0);
        else if(tmax==tzmin)
            rec.normal=vec3(0,0,1);
        else if(tmax==tzmax)
            rec.normal=vec3(0,0,-1);
    }
    return true;
}
