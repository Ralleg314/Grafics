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
        vec3 dist_vec=I-r.initialPoint();
        float d=length(dist_vec);
        if(t_min<d && d<t_max){
            rec.t = lambda;
            rec.p = I;
            rec.normal = n;
            rec.mat_ptr = material;
            return true;
        }
        return false;
    }else{
        return false;
    }

    /*float sinCAP = sqrt(1-pow((dot(A,P))/(length(A)*length(P)),2));
    float sinABC = sqrt(1-pow((dot(B,C))/(length(B)*length(C)),2));
    float sinABP = sqrt(1-pow((dot(B,P))/(length(B)*length(P)),2));
    float sinBCP = sqrt(1-pow((dot(C,P))/(length(C)*length(P)),2));

    float CAP=(length(A-C)*length(P-C)*sinCAP)/(2);
    float ABC=(length(B-A)*length(C-A)*sinABC)/(2);
    float ABP=(length(B-A)*length(P-A)*sinABP)/(2);
    float BCP=(length(C-B)*length(P-B)*sinBCP)/(2);

    float u = CAP/ABC;
    float v = ABP/ABC;
    float w = BCP/ABC;
    if(u+v+w == 1){
        return true;
    }
    else{
        return false;
    }*/

}


