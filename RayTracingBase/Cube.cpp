#include "Cube.h"

Cube::Cube(vec3 i,vec3 e, Material *m) : Object(m){
    this->p1=i;
    this->p2=e;
}

bool Cube::hit(const Ray& r, float t_min, float t_max, HitInfo& rec)const{
    float tnear = -std::numeric_limits<float>::infinity();
    float tfar = std::numeric_limits<float>::infinity();
    float txn,txf,tyn,tyf,tzn,tzf,temp;
    vec3 n = normalize(r.dirVector());
    vec3 p;
    //Check X planes
    if(n.x==0){//Rayo paralelo
        if(r.initialPoint().x < p1.x || r.initialPoint().x > p2.x){
            return false;
        }
    }else{//Rayo no paralelo
        txn = (p1.x-r.initialPoint().x)/n.x;
        txf = (p2.x-r.initialPoint().x)/n.x;


        if(txn>txf){
            temp = txn;
            txn = txf;
            txf = temp;
        }

        if(txn>tnear)
            tnear=txn;

        if(txf<tfar)
            tfar=txf;

        if(tnear>tfar)
            return false;

        if(tfar<0)
            return false;

    }

    //Check Y planes
    if(n.y==0){//Rayo paralelo
        if(r.initialPoint().y < p1.x || r.initialPoint().y > p2.y){
            return false;
        }
    }else{//Rayo no paralelo
        tyn = (p1.y-r.initialPoint().y)/n.y;
        tyf = (p2.y-r.initialPoint().y)/n.y;


        if(tyn>tyf){
            temp = tyn;
            tyn = tyf;
            tyf = temp;
        }

        if(tyn>tnear)
            tnear=tyn;

        if(tyf<tfar)
            tfar=tyf;

        if(tnear>tfar)
            return false;

        if(tfar<0)
            return false;
    }

    //Check Z planes
    if(n.z==0){//Rayo paralelo
        if(r.initialPoint().z < p1.z || r.initialPoint().z > p2.z){
            return false;
        }
    }else{//Rayo no paralelo
        tzn = (p1.z-r.initialPoint().z)/n.z;
        tzf = (p2.z-r.initialPoint().z)/n.z;


        if(tzn>tzf){
            temp = tzn;
            tzn = tzf;
            tzf = temp;
        }

        if(tzn>tnear)
            tnear=tzn;

        if(tzf<tfar)
            tfar=tzf;

        if(tnear>tfar)
            return false;

        if(tfar<0)
            return false;
    }

    if(t_min<tnear && tnear<t_max){
        p=r.pointAtParameter(tnear);
        rec.t = tnear;
        rec.p = p;
        rec.mat_ptr = material;
        if(tnear==txn)
            rec.normal=vec3(1,0,0);
        else if(tnear==txf)
            rec.normal=vec3(-1,0,0);
        else if(tnear==tyn)
            rec.normal=vec3(0,1,0);
        else if(tnear==tyf)
            rec.normal=vec3(0,-1,0);
        else if(tnear==tzn)
            rec.normal=vec3(0,0,1);
        else if(tnear==tzf)
            rec.normal=vec3(0,0,-1);
        return true;
    }else if(t_min<tfar && tfar<t_max){
        p=r.pointAtParameter(tfar);
        rec.t = tfar;
        rec.p = p;
        rec.mat_ptr = material;
        if(tfar==txn)
            rec.normal=vec3(1,0,0);
        else if(tfar==txf)
            rec.normal=vec3(-1,0,0);
        else if(tfar==tyn)
            rec.normal=vec3(0,1,0);
        else if(tfar==tyf)
            rec.normal=vec3(0,-1,0);
        else if(tfar==tzn)
            rec.normal=vec3(0,0,1);
        else if(tfar==tzf)
            rec.normal=vec3(0,0,-1);
        return true;
    }
}
