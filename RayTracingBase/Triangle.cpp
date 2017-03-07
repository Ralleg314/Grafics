#include "Triangle.h"

Triangle::Triangle(vec3 A, vec3 B, vec3 C, Material *m): Object(m)
{
    this->A=A;
    this->B=B;
    this->C=C;
}

bool Triangle::hit(const Ray &r, float t_min, float t_max, HitInfo &rec) const{
    vec3 n = cross(this->B-this->A,this->C-this->A)/length(cross(this->B-this->A,this->C-this->A));
    float prod=dot(r.dirVector(),n);
    if(abs(prod)<0.00000000001){
        return false;
    }
    float d=-dot(n,this->A);
    float lambda=-(d+dot(n,r.initialPoint()))/prod;
    vec3 I=r.pointAtParameter(lambda);
    float s1=dot(cross((this->B-this->A),I-this->A),n);
    float s2=dot(cross((this->C-this->B),I-this->B),n);
    float s3=dot(cross((this->A-this->C),I-this->C),n);

    if((s1<0 && s2<0 && s3<0) || (s1>0 && s2>0 && s3>0)){
        if(t_min<lambda && lambda<t_max){
            rec.t = lambda;
            rec.p = I;
            if(dot(n,r.dirVector())<0)
                rec.normal = n;
            else
                rec.normal = -n;
            rec.mat_ptr = material;
            return true;
        }
        return false;
    }else{
        return false;
    }

}


